#include <Core/Slider.hpp>

#include <Core/Utility.hpp>

using ConstraintClamp = Core::ConstraintClamp;
using ConstraintRepeat = Core::ConstraintRepeat;

float ConstraintClamp::constrain(float value, Range const &range)
{
    return Core::clamp(value, range);
}
float ConstraintRepeat::constrain(float value, Range const &range)
{
    return Core::repeat(value, range);
}