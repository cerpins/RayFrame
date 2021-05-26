# CMakeList.txt : CMake project for CMakeProjectPort, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set (CMAKE_CXX_STANDARD 17)

find_package(raylib 3.0 QUIET) # Let CMake search for a raylib-config.cmake

# You could change the QUIET above to REQUIRED and remove this if() clause
# This part downloads raylib and builds it if it's not installed on your system
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)

  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/master.tar.gz
  )

  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)

    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples

    # build raylib
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

include_directories("include")

# Add source to this project's executable.
add_executable (CMakeProjectPort "main.cpp" "include/Core/Aliases.hpp" "include/Core/ASingular.hpp" "include/Core/Degrees.hpp" "include/Core/Invariant.hpp" "include/Core/NumberUnique.hpp" "include/Core/Slider.hpp" "include/Core/Trivial.hpp" "include/Core/Utility.hpp" "include/Gameplay/Screen.hpp" "include/Gameplay/ScreenSwitch.hpp" "include/Sc/IWindowControl.hpp" "include/Sc/IWindowScreen.hpp" "include/Sc/Window.hpp" "include/Sc/WindowAPI.hpp" "include/Sc/API/IAsset.hpp" "include/Sc/API/IDraw.hpp" "include/Sc/API/IKeyboard.hpp" "include/Sc/API/IMouse.hpp" "include/Sx/Console.hpp" "include/Sx/Cursor.hpp" "include/Sx/Draw.hpp" "include/Sx/Gui.hpp" "include/Sx/IClickable.hpp" "include/Sx/Measure.hpp" "src/Degrees.cpp" "src/Invariant.cpp" "src/Slider.cpp" "src/Trivial.cpp" "src/Utility.cpp" "src/ScreenAbout.cpp" "src/ScreenTest.cpp" "src/ScreenTitle.cpp" "src/ScreenTitleUtil.hpp" "src/Window.cpp" "src/Asset.cpp" "src/Asset.hpp" "src/Convert.hpp" "src/Draw.cpp" "src/Draw.hpp" "src/DrawExtended.cpp" "src/DrawExtended.hpp" "src/DrawObject.hpp" "src/IDrawObject.hpp" "src/Keyboard.cpp" "src/Keyboard.hpp" "src/Mouse.cpp" "src/Mouse.hpp" "src/Console.cpp" "src/Cursor.cpp" "src/DrawSx.cpp" "src/Gui.cpp" "src/Measure.cpp" "include/Gameplay/Z.hpp")


target_link_libraries(CMakeProjectPort raylib)

# TODO: Add tests and install targets if needed.