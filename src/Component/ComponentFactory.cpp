/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ComponentFactory
*/

#include "ComponentFactory.hpp"
#include "ClockComponent.hpp"
#include "ConstComponent.hpp"
#include "OutputComponent.hpp"
#include "Component4001.hpp"
#include "Component4008.hpp"
#include "Component4011.hpp"
#include "Component4013.hpp"
#include "Component4017.hpp"
#include "Component4030.hpp"
#include "Component4040.hpp"
#include "Component4069.hpp"
#include "Component4071.hpp"
#include "Component4081.hpp"
#include "Component4094.hpp"
#include "Component4512.hpp"
#include "Component4514.hpp"
#include "LoggerComponent.hpp"
#include "BadComponentTypeException.hpp"

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
    {"4017",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4017>();}},
    {"4030",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4030>();}},
    {"4040",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4040>();}},
    {"4069",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4069>();}},
    {"4071",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4071>();}},
    {"4081",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4081>();}},
    {"4094",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4094>();}},
    {"4512",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4512>();}},
    {"4514",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4514>();}},
    {"logger", []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::LoggerComponent>();}},
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
