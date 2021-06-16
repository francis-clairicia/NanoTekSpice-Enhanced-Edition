/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ComponentFactory
*/

#ifndef COMPONENTFACTORY_HPP_
#define COMPONENTFACTORY_HPP_

#include <memory>
#include "IComponent.hpp"
#include "AGraphicalComponent.hpp"

namespace nts
{
    class ComponentFactory
    {
    public:
        ~ComponentFactory() noexcept = default;

        static std::unique_ptr<IComponent> createComponent(const std::string &type);
        static std::unique_ptr<IComponent> createGraphicalComponent(const std::string &type);

    private:
        ComponentFactory() noexcept = default;
    };
}

#endif /* !COMPONENTFACTORY_HPP_ */
