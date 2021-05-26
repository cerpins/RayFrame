# This is an extraction of some private and experimental code I want to expand in time

Extracted it into a fresh VS CMake project from a game I was making, which was last worked on about a year ago.
It was also done purely on Linux, so some things are lacking here. 
Even the following README is outdated and meant purely for me.

To-do:
*   Review and cleanup the code
*   Add all neccessary compiler warnings, which on clang were previously
    "-Wall", "-Wpedantic", "-pedantic-errors", "-Wextra", 
    "-Werror", "-Wshadow", "-Wnon-virtual-dtor", "-Wconversion", "-Wunreachable-code", "-Wuninitialized", 
    "-Wold-style-cast", "-Wconversion", "-Wsign-conversion", "-Wdouble-promotion", "-Wno-missing-braces", 
    "-Wno-error=unused-private-field", "-Wno-error=unused-parameter", "-Wno-error=unused-variable", "-fno-rtti"
*   Extend features

## Features 

1.  Wraps part of raylib to be C++
2.  Z-layered drawing
3.  Scene system
4.  Tiny GUI system

## Features needed

1.  Event pipelines
2.  Save/load system

## Why was I making it?

1.  Use of C++ features which cannot be used without
    overriding the underlying C types. This includes
    operator overloading and RAII, namespaces, hiding
    of raw pointers and use of dated c-style arrays
    and strings, etc. (Partly a raylib c++ wrapper)

2.  Trying to simplify higher level abstractions in
    games, like scene swapping, z layering, etc. 
    (Mini game framework, not just a library)

## How to use (boilerplate)

1. Include <Sc/Window.hpp>
   <Sc/IWindowScreen.hpp>
2. Inherit and define [IWindowScreen].
3. In class:
   start(control, ...) {
   while (control.frameTick()) {
   // ...
   }
   }
4. Instantiate Window with:
   std::make_unique<YourScreenName>()

Everything else can be discerned via values
passed into start(...) method.

Instantiate Context with an extension of IScene.

## Convention

### Prefixes

m* : Indicate member when not in scopeless struct.
Resolves write/read function name conflicts.
g* : Indicate global.
I : Pure abstract class.
F : Pure abstract class with friend.
A : Abstract class.
T : Template parameter.

### Casing

camelCase : Functions, methods, local variables.
PascalCase : User types.

### Foldering & Namespacing

Don't namespace beyond the initial folders in Include.
Prefix logically joined parts with the same name.

./Include : Globally available headers.
/Core : Non-library-specific utilities.
Do not put anything that depends on
Sc wrapper or Gameplay here.
/Sc : Interface to raylib wrapper.
/Sx : Sc raylib wrapper further utilities.
/Gameplay : Non-specific, put game files here.
./Source : Source files and internal header/source pairs.
./Asset : Assets.

**Assets currently need to be copy pasted into the output
folder for them to be read.**

### Guideline & Syntax

- Prefer floats to integers
- Enforce const correctness
- Wrap pointers in smart pointers
- Forward declare whenever possible
- Limit line width to 80
- Place const after type
- Employ auto

### Compiler

Using CLANG for c++17
Pushing to github or merging branches should throw no warnings
Werrors disabled - missing-braces
Werrors ignored - unused-private-field, unused-parameter
Run CMAKE from folder ./build
cmake .. -DCMAKE_CXX_COMPILER=clang++

### Formating

Using default. Ideally would set-up clang-format
with an exact config file.

#### About auto

I'm not fully sure where to avoid it, but generally,
use it where

1.  Something obvious is passed back, like a standard library
    type **which is not subject to change**, rather than something passed back by your own functions.
2.  The auto variable is quickly discarded and not used in multiple
    statements.
3.  It's conveyed into or from another clearly declared type.
4.  It's the operational result of two clear types, for example,
    an auto which equals (string + string).
5.  It's the result of a library function **which is not subject to change**.
