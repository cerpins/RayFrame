// CMakeProjectPort.cpp : Defines the entry point for the application.
//

#include <Sc/Window.hpp>
#include <Gameplay/Screen.hpp>

/*  Right now certain things like event queues aren't build to handle
    registered objects to go out of scope, so make sure you don't pass
    any non-trivial (or non-POD) objects outside of a screen's scope.

    ? Implementing life-time trackers to pass around a reference
*/

int main()
{
    const Sc::Window win = Sc::Window(
        { {800, 600}, "Hello, World!" },
        std::make_unique<Gameplay::ScreenTitle>());

    return 0;
}