#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Event/ISubject.hpp"
#include "Core/Event/IObserver.hpp"
#include "Core/Event/AObserver.hpp"
#include <vector>

namespace ArcaTek::Event {
    template <typename T>
    class ASubject : public ISubject {
    protected:
        std::vector<std::shared_ptr<IObserver>> observers;

    public:
        ASubject() = default;

        void attach(std::shared_ptr<IObserver> observer) {
            this->observers.push_back(observer);
        }
    
        void attach(std::function<void(T)> callback) {
            this->attach(std::make_shared<AObserver<T>>(callback));
        }
    
        void detach(std::shared_ptr<IObserver> observer) {
            auto it = std::remove_if(observers.begin(), observers.end(),
                [&observer](const std::shared_ptr<IObserver>& o) { return o == observer; });
    
            observers.erase(it, observers.end());
        }
    
        void notify(T data) {
            for (std::shared_ptr<IObserver> observer : this->observers) {
                const std::shared_ptr<AObserver<T>> typedObserver = std::dynamic_pointer_cast<AObserver<T>>(observer);
    
                if (!typedObserver)
                    continue;
                typedObserver->update(data);
            }
        }
    };        
} // namespace ArcaTek::Event
