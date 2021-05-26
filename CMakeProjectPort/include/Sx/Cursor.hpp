#pragma once

#include <Core/Invariant.hpp>
#include <Core/Trivial.hpp>

namespace Sc
{
    struct IMouse;
} // namespace Sc

namespace Sx
{
    // Define game cursor which can pickup tools n stuff
    class Cursor
    {
    public:
        Cursor(Core::Bound const &horizontal,
               Core::Bound const &vertical);
        void update(Sc::IMouse &);
        Core::Point point() const;
        void lock();
        void unlock();

        // Deprecated
        bool m_isLocked{false};

    private:
        Core::Bound m_horizontal;
        Core::Bound m_vertical;
        Core::Point m_point;
    };
} // namespace Sx