#pragma once

namespace Sx
{
    /*  This should be rebuilt into a generic class which
        passes around an interface in initializer from (*this)
        and takes an array of "IInformWhenDeleted" pointers
        from a pipe.
        
        Essentially, an event class that signals it's own
        going out of scope for safety, and generic, simple,
        passing into a pipe.
    */
    struct IClickable
    {
        virtual ~IClickable(){};
        virtual void wasClicked() = 0;
    };
} // namespace Sx