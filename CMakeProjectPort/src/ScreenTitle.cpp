#include <Gameplay/Screen.hpp>

#include "ScreenTitleUtil.hpp"
#include <Gameplay/Z.hpp>

using ScreenTitle = Gameplay::ScreenTitle;

Sx::GuiConfig defaultGuiSetting(
    Sc::IAsset &api,
    std::string const &fontPath,
    int const z)
{
    return {
        z,
        {0, 5, 10, 225},
        10.0f,
        5.0f,
        0.4f,
        api.loadFont(fontPath, 12),
        api.loadFont(fontPath, 20),
        api.loadFont(fontPath, 26),
        {225, 225, 225, 255}};
}

void ScreenTitle::start(Sc::IWindowControl &control, Sc::WindowAPI &api)
{
    using namespace Core;
    using namespace Sc;
    using namespace Sx;

    std::cout << "Screen title." << std::endl;
    // Can probably unpack API here so we don't write "api.member" all the time
    IAsset &asset = api.asset;
    IMouse &mouse = api.mouse;

    std::string const fontPath = "font/Hack-Regular.ttf";
    Font const font = api.asset.loadFont(fontPath, 20);

    Texture const texCursor = asset.loadTexture("cursor.png");

    Cursor cursor = {{0, 790}, {0, 590}};

    Sx::GuiConfig guiConfig = defaultGuiSetting(api, fontPath, g_zGui);
    Sx::FactoryForGui factory = (guiConfig);
    Sx::GuiLabel guiLabel = factory.label({400, 400, 130, 30}, "Hi, World!");
    Sx::GuiButton guiButton = factory.button({400, 100, 300, 180}, "Click me to log in the console! Console is opened via (~)");

    Sx::Console console = {font, g_colorBlack};

    Sx::MeasureLine measureLine = {font, g_colorBlack};
    Sx::MeasureGrid measureGrid = {100, 30, g_colorDream};

    bool isConsoleVisible = false;
    auto const toggleConsole = [&console, &isConsoleVisible]() {
        isConsoleVisible
            ? console.hide()
            : console.show();
        isConsoleVisible = !isConsoleVisible;
    };
    auto const drawCursorAt = [&texCursor](IDraw &api, Point const &point) {
        drawTextureBasic(api, g_zForeground, texCursor, point);
    };


    while (control.tickFrame())
    {
        // Propogate API
        cursor.update(api);
        drawTextureBasic(api.draw, g_zGuiMax, texCursor, cursor.point());

        //spew.update();
        measureLine.update(
            api, cursor.point(),
            api.mouse.isHeld(Sc::EMouseButton::Left));
        measureGrid.update(api);
        console.update(api);

        // Draws
        int const zBody = g_zGame + 100;
        guiLabel.draw(api);
        guiButton.draw(api);

        if (api.keyboard.isClicked(Sc::EKeyboardKey::Grave)) {
            toggleConsole();
            console.log("console_status", "Console was just opened! This message will fade in time.", 60 * 4);
            
        }


        if (guiButton.isCollision(cursor.point()))
        {
            if (mouse.isClicked(EMouseButton::Left)) {
                guiButton.click();
                console.log("button", "Button was clicked.", 60 * 1);
            }
            else {
                guiButton.hover();
            }
        }

        // Screen control
        Gameplay::screenSwitch(control, api);
    }
}
