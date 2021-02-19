/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ComponentFactory
*/

#include <iostream>
#include "ComponentFactory.hpp"
#include "ClockComponent.hpp"
#include "ConstComponent.hpp"
#include "OutputComponent.hpp"
#include "Component4001.hpp"
#include "Component4008.hpp"
#include "Component4011.hpp"
#include "Component4013.hpp"
#include "Component4030.hpp"
#include "Component4069.hpp"
#include "Component4071.hpp"
#include "Component4081.hpp"
#include "BadComponentTypeException.hpp"
#include "BadComponentNameException.hpp"

static const std::unordered_map<std::string, std::unique_ptr<nts::IComponent> (*)()> COMPONENT_CREATOR{
    {"input",  []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::InputComponent>();}},
    {"clock",  []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::ClockComponent>();}},
    {"true",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::TrueComponent>();}},
    {"false",  []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::FalseComponent>();}},
    {"output", []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::OutputComponent>();}},
    {"4001",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4001>();}},
    {"4008",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4008>();}},
    {"4011",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4011>();}},
    {"4013",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4013>();}},
    {"4030",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4030>();}},
    {"4069",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4069>();}},
    {"4071",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4071>();}},
    {"4081",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4081>();}},
};

nts::ComponentFactory::ComponentFactory() noexcept
{
}

nts::ComponentFactory::~ComponentFactory() noexcept
{
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComponent(const std::string &type) const
{
    const auto &search = COMPONENT_CREATOR.find(type);

    if (search == COMPONENT_CREATOR.end())
        throw nts::BadComponentTypeException(type);
    return search->second();
}
