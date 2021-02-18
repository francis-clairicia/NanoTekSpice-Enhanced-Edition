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
    class ComponentFactory {
        public:
            ComponentFactory() noexcept;
            ~ComponentFactory() noexcept;

            std::unique_ptr<nts::IComponent> createComponent(const std::string &type) const;
    };
}

#endif /* !COMPONENTFACTORY_HPP_ */
