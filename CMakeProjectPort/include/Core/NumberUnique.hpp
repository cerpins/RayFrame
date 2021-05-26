#pragma once

namespace Core
{
    template <class TNumber>
    class NumberUnique
    {
    public:
        NumberUnique() : number(0) {}
        TNumber get()
        {
            return number++;
        }

    private:
        TNumber number;
    };
} // namespace Core
