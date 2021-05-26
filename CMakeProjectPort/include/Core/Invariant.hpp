#pragma once

/*  Invariant.hpp 
    Defines values with logical constraints,
    such as Range, which is limited to a min
    and max value.
*/
/*  Templated behaviors in invariants is useful
    when something should take a specificaton of
    an invariant only, call these [name]Generic
*/

namespace Core
{
    // Float restrained to ranges [0-1]
    class Normal
    {
    public:
        explicit Normal(float const);
        operator float() const;

    private:
        float m_normalized;
    };

    // Invariant [min, max]
    class Range
    {
    public:
        Range(float const min, float const max);
        // Make non member
        float min() const;
        float max() const;

    private:
        float m_min;
        float m_max;
    };

    float extent(Range const &);

    template <int TMin, int TMax>
    // Can be cast to Range
    class GenericRange : public Range
    {
    public:
        GenericRange()
            : Range(static_cast<float>(TMin), static_cast<float>(TMax)){};
    };

    /*  Invariant [min, max] without specifying order of min or max,
        can be cast to Range.*/
    struct Bound : public Range
    {
        Bound(float a, float b);
    };
} // namespace Core