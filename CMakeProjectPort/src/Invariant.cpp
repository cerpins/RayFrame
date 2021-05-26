#include <Core/Invariant.hpp>

#include <Core/Utility.hpp>

using Normal = Core::Normal;
using Range = Core::Range;
using Bound = Core::Bound;

Normal::Normal(float const value)
    : m_normalized(
          clamp(value, {0.f, 1.f})) {}
Normal::operator float() const
{
    return m_normalized;
}

Range::Range(float const min, float const max)
    : m_min(min), m_max(max) {}
float Range::min() const { return m_min; }
float Range::max() const { return m_max; }
float Core::extent(Range const &range)
{
    return std::abs(range.min()) - std::abs(range.max());
}

Bound::Bound(float a, float b)
    : Range{a < b ? a : b,
            a > b ? a : b} {}