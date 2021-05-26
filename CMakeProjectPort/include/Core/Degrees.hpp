#pragma once

#include <Core/Trivial.hpp>
#include <Core/Slider.hpp>

namespace Core
{
    // This is overly complicated and should be replaced

    // Alias for a value constrained to -360, 360 range
    class Degrees : public Slider<ConstraintRepeat>
    {
    public:
        Degrees();
        Degrees(float degrees);
    };
    // Alias for a value constrained to a specified -360, 360 bound
    class DegreesClamp : public Slider<ConstraintClamp>
    {
    public:
        DegreesClamp();
        DegreesClamp(float degrees, Bound const &bound);
    };

    struct RotationalPoint
    {
        Degrees m_degrees;
        Point m_point;
    };
} // namespace Core