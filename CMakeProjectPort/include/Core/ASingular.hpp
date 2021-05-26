#pragma once

#include <stdexcept>

namespace Core
{

    /*  Inherit from this when a class should not have more than one instance,
    pass that class as Type parameter, also.
    */
    template <class T>
    class ASingular
    {
    public:
        ASingular()
        {
            if (m_instanceExists)
            {
                throw std::runtime_error("Instance of single-instance object already exists.");
            }
            m_instanceExists = true;
        };
        virtual ~ASingular()
        {
            m_instanceExists = false;
        }

    private:
        static bool m_instanceExists;
    };

    template <class T>
    bool ASingular<T>::m_instanceExists = false;

} // namespace Core
