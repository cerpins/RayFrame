#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <array>
#include <functional>
#include <algorithm>

// Ignore all this stuff it's just for testing
#include <Core/Aliases.hpp>
#include <Core/Utility.hpp>
#include <Sc/WindowAPI.hpp>
#include <Sc/Window.hpp>
#include <Sx/IClickable.hpp>
#include <Sx/Gui.hpp>
#include <Sx/Draw.hpp>
#include <Sx/Cursor.hpp>
#include <Sx/Measure.hpp>
#include <Sx/Console.hpp>
#include <Gameplay/ScreenSwitch.hpp>

// Utilities for screen title

Sx::GuiImgToggle makeItemBox(
    Sx::FactoryForGui const &factory,
    Sc::Texture const &texture,
    int const position)
{
    float const margin = 5.f;
    float const height = margin;
    float const scale = 0.6f;
    Core::Size const size = {80, 60};
    Core::Point const point = {
        (position + 1.f) * margin + position * size.width,
        height};

    return factory.imgToggle({point, size}, texture, scale);
}

template <class TCallable, class T, class... TVar>
void call(TCallable call, T &item, TVar const &... items)
{
    call(item);
    call(call, items...);
}
template <class TCallable, class T>
void call(TCallable call, T const &item)
{
    call(item);
}

// Shorthand for if block
template <class TCallable, class... TVar>
void callIf(bool const condition, TCallable call, TVar const &... items)
{
    if (condition)
    {
        call(call, items...);
    }
}
template <class TCallable>
void callIf(bool const condition, TCallable call)
{
    if (condition)
    {
        call();
    }
}

template <class TCallable, class TElseCallable>
void callIfElse(bool const condition, TCallable call, TElseCallable callElse)
{
    condition
        ? call()
        : callElse();
}

//makeIdMap

//EItem:id
//map tex to eitem, or color, how?
struct ItemConfig
{
    Sc::Texture m_texture;
    Core::Color m_color;
    int m_position;
    Sx::GuiImgToggle m_gui;
};
