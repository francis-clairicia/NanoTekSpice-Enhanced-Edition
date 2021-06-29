/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ComponentFactory
*/

#include "ComponentFactory.hpp"
#include "ClockComponent.hpp"
#include "ConstComponent.hpp"
#include "OutputComponent.hpp"
#include "Component2716.hpp"
#include "Component4001.hpp"
#include "Component4008.hpp"
#include "Component4011.hpp"
#include "Component4013.hpp"
#include "Component4017.hpp"
#include "Component4030.hpp"
#include "Component4040.hpp"
#include "Component4063.hpp"
#include "Component4069.hpp"
#include "Component4071.hpp"
#include "Component4081.hpp"
#include "Component4094.hpp"
#include "Component4512.hpp"
#include "Component4514.hpp"
#include "Component4801.hpp"
#include "LoggerComponent.hpp"
#include "SubComponent.hpp"
#include "MulComponent.hpp"
#include "GraphicalInputComponent.hpp"
#include "GraphicalOutputComponent.hpp"
#include "ButtonComponent.hpp"
#include "ToggleComponent.hpp"
#include "RGBLEDComponent.hpp"
#include "BadComponentTypeException.hpp"

namespace
{
    const std::unordered_map<std::string_view, std::unique_ptr<nts::IComponent> (*)()> COMPONENT_CREATOR{
        {"input",  []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::InputComponent>();}},
        {"clock",  []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::ClockComponent>();}},
        {"true",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::TrueComponent>();}},
        {"false",  []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::FalseComponent>();}},
        {"output", []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::OutputComponent>();}},
        {"2716",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component2716>();}},
        {"4001",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4001>();}},
        {"4008",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4008>();}},
        {"4011",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4011>();}},
        {"4013",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4013>();}},
        {"4017",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4017>();}},
        {"4030",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4030>();}},
        {"4040",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4040>();}},
        {"4063",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4063>();}},
        {"4069",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4069>();}},
        {"4071",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4071>();}},
        {"4081",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4081>();}},
        {"4094",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4094>();}},
        {"4512",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4512>();}},
        {"4514",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4514>();}},
        {"4801",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4801>();}},
        {"logger", []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::LoggerComponent>();}},
        {"sub",    []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::SubComponent>();}},
        {"mul",    []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::MulComponent>();}},
    };

    const std::unordered_map<std::string_view, std::unique_ptr<nts::AGraphicalComponent> (*)()> GRAPHICAL_COMPONENT_CREATOR{
        {"input",  []() -> std::unique_ptr<nts::AGraphicalComponent> {return std::make_unique<nts::GraphicalInputComponent>();}},
        {"output", []() -> std::unique_ptr<nts::AGraphicalComponent> {return std::make_unique<nts::GraphicalOutputComponent>();}},
        {"button", []() -> std::unique_ptr<nts::AGraphicalComponent> {return std::make_unique<nts::ButtonComponent>();}},
        {"toggle", []() -> std::unique_ptr<nts::AGraphicalComponent> {return std::make_unique<nts::ToggleComponent>();}},
        {"rgbled", []() -> std::unique_ptr<nts::AGraphicalComponent> {return std::make_unique<nts::RGBLEDComponent>();}}
    };
} // namespace

namespace nts
{
    std::unique_ptr<IComponent> ComponentFactory::createComponent(const std::string &type)
    {
        auto search = COMPONENT_CREATOR.find(std::string_view{type});

        if (search == COMPONENT_CREATOR.end())
            throw BadComponentTypeException(type);
        return search->second();
    }

    std::unique_ptr<AGraphicalComponent> ComponentFactory::createGraphicalComponent(const std::string &type)
    {
        auto search = GRAPHICAL_COMPONENT_CREATOR.find(std::string_view{type});

        if (search == GRAPHICAL_COMPONENT_CREATOR.end())
            throw BadComponentTypeException(type);
        return search->second();
    }
} // namespace nts

