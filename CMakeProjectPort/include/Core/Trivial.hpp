#pragma once

#include <cmath>
#include <array>

/*  Simple data structures without invariants
*/
namespace Core
{
    struct Point;
    bool operator>(const Point &a, const Point &b);
    bool operator<(const Point &a, const Point &b);
    Point operator+(const Point &a, const Point &b);
    Point operator-(const Point &a, const Point &b);
    Point operator*(const Point &a, const Point &b);

    struct Point
    {
        float x;
        float y;

        Point &operator+=(const Point &a);
        Point &operator-=(const Point &a);
        friend bool operator>(const Point &a, const Point &b);
        friend bool operator<(const Point &a, const Point &b);
        friend Point operator+(const Point &a, const Point &b);
        friend Point operator-(const Point &a, const Point &b);
        friend Point operator*(const Point &a, const Point &b);
    };

    struct Size
    {
        float width;
        float height;
    };

    struct Line
    {
        Point start;
        Point end;
    };

    struct Rectangle
    {
        Point point;
        Size size;
    };

    struct Quad
    {
        Point leftTop;
        Point rightTop;
        Point rightBottom;
        Point leftBottom;
    };

    struct Tri
    {
        Point first;
        Point second;
        Point third;
    };

    struct Color
    {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
    };

    // struct Image
    // {

    // };

    inline Color constexpr colorNormal(float r, float g, float b, float a = 1)
    {
        using uchar = unsigned char;
        return {
            static_cast<uchar>(std::min(255.0f, std::max(0.0f, r * 255.0f))),
            static_cast<uchar>(std::min(255.0f, std::max(0.0f, g * 255.0f))),
            static_cast<uchar>(std::min(255.0f, std::max(0.0f, b * 255.0f))),
            static_cast<uchar>(std::min(255.0f, std::max(0.0f, a * 255.0f)))};
    }

    // Extend as need be
    inline Color constexpr g_colorRed{colorNormal(1.f, 0.f, 0.f)};
    inline Color constexpr g_colorMagenta{colorNormal(1.f, 0.f, 0.5f)};
    inline Color constexpr g_colorMiami{colorNormal(1.f, 0.f, 0.6f)};
    inline Color constexpr g_colorRoyal{colorNormal(0.35f, 0.25f, 0.f)};
    inline Color constexpr g_colorPigment{colorNormal(1.f, 0.81f, 0.7f)};
    inline Color constexpr g_colorTan{colorNormal(0.95f, 0.65f, 0.55f)};
    inline Color constexpr g_colorDream{colorNormal(0.95f, 0.92f, 0.9f)};

    inline Color constexpr g_colorGreen{colorNormal(0.f, 1.f, 1.f)};
    inline Color constexpr g_colorForest{colorNormal(0.f, 0.5f, 1.f)};
    inline Color constexpr g_colorSpearmint{colorNormal(0.7f, 0.9f, 0.75f)};
    inline Color constexpr g_colorMint{colorNormal(0.9f, 1.f, 0.95f)};

    inline Color constexpr g_colorBlue{colorNormal(0.f, 1.f, 1.f)};
    inline Color constexpr g_colorGenie{colorNormal(0.7f, 0.f, 1.f)};
    inline Color constexpr g_colorNight{colorNormal(0.1f, 0.1f, 0.4f)};
    inline Color constexpr g_colorNinja{colorNormal(0.2f, 0.f, 0.8f)};
    inline Color constexpr g_colorWizard{colorNormal(0.5f, 0.f, 1.f)};
    inline Color constexpr g_colorWinter{colorNormal(0.f, 0.9f, 0.95f)};

    inline Color constexpr g_colorBlack{colorNormal(0.f, 0.f, 0.f)};
    inline Color constexpr g_colorWhite{colorNormal(1.f, 1.f, 1.f)};
} // namespace Core