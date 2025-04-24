#include "ASubject.hpp"
#include "Core/Buffer/Square.hpp"
#include <algorithm>

namespace ArcaTek::Event {
    template <typename T>
    void ASubject<T>::attach(std::shared_ptr<IObserver> observer) {
        this->observers.push_back(observer);
    }

    template <typename T>
    void ASubject<T>::detach(std::shared_ptr<IObserver> observer) {
        auto it = std::remove_if(observers.begin(), observers.end(),
            [&observer](const std::shared_ptr<IObserver>& o) { return o == observer; });

        observers.erase(it, observers.end());
    }

    template <typename T>
    void ASubject<T>::notify(T data) {
        for (std::shared_ptr<IObserver> observer : this->observers) {
            const std::shared_ptr<AObserver<T>> typedObserver = std::dynamic_pointer_cast<AObserver<T>>(observer);

            if (!typedObserver)
                continue;
            typedObserver->update(data);
        }
    }
} // namespace ArcaTek::Event

// Explicit instantiation for the types you want to use
template class ArcaTek::Event::ASubject<unsigned char>;
template class ArcaTek::Event::ASubject<ArcaTek::Buffer::Square>;
template class ArcaTek::Event::ASubject<bool>;
