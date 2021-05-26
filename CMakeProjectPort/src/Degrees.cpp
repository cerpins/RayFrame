#include <Core/Degrees.hpp>

#include <Core/Utility.hpp>

using Degrees = Core::Degrees;

Degrees::Degrees()
    : Slider(0, Range{-360, 360}) {}
Degrees::Degrees(float degrees)
    : Slider(degrees, {-360, 360}) {}

using DegreesClamp = Core::DegreesClamp;

DegreesClamp::DegreesClamp()
    : Slider(0, {-360, 360}) {}
DegreesClamp::DegreesClamp(float degrees, Bound const &bound)
    : Slider(
          degrees,
          {clamp(bound.min(), {-360, 360}),
           clamp(bound.max(), {-360, 360})}) {}