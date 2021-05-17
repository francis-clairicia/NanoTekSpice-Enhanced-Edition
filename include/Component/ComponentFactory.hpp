/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ComponentFactory
*/

#ifndef COMPONENTFACTORY_HPP_
#define COMPONENTFACTORY_HPP_

#include <memory>
#include "IComponent.hpp"

namespace nts
{
    class ComponentFactory
    {
    public:
        ~ComponentFactory() noexcept = default;

        static std::unique_ptr<IComponent> createComponent(const std::string &type);

    private:
        ComponentFactory() noexcept = default;
    };
}

#endif /* !COMPONENTFACTORY_HPP_ */
