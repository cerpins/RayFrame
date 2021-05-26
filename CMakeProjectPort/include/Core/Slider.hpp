#pragma once

#include <Core/Trivial.hpp>
#include <Core/Invariant.hpp>

namespace Core
{
    // This is overly complicated and should be replaced

    struct ConstraintClamp
    {
        static float constrain(float value, Range const &limit);
    };

    struct ConstraintRepeat
    {
        static float constrain(float value, Range const &limit);
    };

    template <class TConstraint>
    class Slider;
    template <class TConstraint>
    Slider<TConstraint> operator+(Slider<TConstraint> const &a, float const b)
    {
        return Slider<TConstraint>(a.value() + b, a.Slider());
    }
    template <class TConstraint>
    Slider<TConstraint> operator-(Slider<TConstraint> const &a, float const b)
    {
        return Slider<TConstraint>(a.value() - b, a.Slider());
    }

    // Value with a min() max() constraint
    template <class TConstraint>
    class Slider
    {
    public:
        Slider(float value, Core::Range const &limit)
            : m_value(TConstraint::constrain(value, limit)),
              m_limit{limit.min(), limit.max()} {}

        float value() const { return m_value; }
        Core::Range constrain() const { return m_limit; }

        Slider &operator+=(float const a)
        {
            m_value = TConstraint::constrain(m_value + a, m_limit);
            return *this;
        }
        Slider &operator-=(float const a)
        {
            m_value = TConstraint::constrain(m_value - a, m_limit);
            return *this;
        }

        template <class TC>
        friend Slider<TC> operator+(Slider<TC> const &a, float const b);
        template <class TC>
        friend Slider<TC> operator-(Slider<TC> const &a, float const b);

    private:
        float m_value;
        Core::Range m_limit;
    };

    using Clamped = Slider<ConstraintClamp>;
    using Repeated = Slider<ConstraintRepeat>;

} // namespace Core