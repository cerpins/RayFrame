#include <Core/Trivial.hpp>

#include <cmath>
#include <Core/Invariant.hpp>

using Point = Core::Point;
using Rectangle = Core::Rectangle;
using Color = Core::Color;

Point &Point::operator+=(const Core::Point &a)
{
    x += a.x;
    y += a.y;
    return *this;
}
Point &Point::operator-=(const Core::Point &a)
{
    x -= a.x;
    y -= a.y;
    return *this;
}

bool Core::operator>(const Core::Point &a, const Core::Point &b)
{
    // Maybe return an enum of which quadrant instead?
    return a.x > b.x && a.y > b.y;
}
bool Core::operator<(const Core::Point &a, const Core::Point &b)
{
    return a.x < b.x && a.y < b.y;
}
Point Core::operator+(const Core::Point &a, const Core::Point &b)
{
    return {a.x + b.x, a.y + b.y};
}
Point Core::operator-(const Core::Point &a, const Core::Point &b)
{
    return {a.x - b.x, a.y - b.y};
}
Point Core::operator*(const Core::Point &a, const Core::Point &b)
{
    return {a.x * b.x, a.y * b.y};
}
