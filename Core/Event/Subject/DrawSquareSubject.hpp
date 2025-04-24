#pragma once

#include "Core/CoreNamespace.hpp"
#include "Core/Event/ASubject.hpp"
#include "Core/Buffer/Square.hpp"

namespace ArcaTek::Event::Subject
{
    class DrawSquareSubject : public ASubject<Buffer::Square> {

    };
} // namespace ArcaTek::Event::Subject
