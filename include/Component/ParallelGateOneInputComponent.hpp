/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ParallelGateOneInputComponent
*/

#ifndef PARALLELGATEONEINPUTCOMPONENT_HPP_
#define PARALLELGATEONEINPUTCOMPONENT_HPP_

#include <iostream>
#include "BoxComponent.hpp"

namespace nts
{
    template<nts::ComponentType Type, typename Gate>
    class ParallelGateOneInputComponent: public nts::BoxComponent {
        public:
            enum Pin
            {
                INPUT_1  = 1,
                OUTPUT_1 = 2,
                INPUT_2  = 3,
                OUTPUT_2 = 4,
                INPUT_3  = 5,
                OUTPUT_3 = 6,
                OUTPUT_4 = 8,
                INPUT_4  = 9,
                OUTPUT_5 = 10,
                INPUT_5  = 11,
                OUTPUT_6 = 12,
                INPUT_6  = 13
            };

        public:
            ParallelGateOneInputComponent() noexcept:
                BoxComponent(Type, 14, {
                    INPUT_1,
                    INPUT_2,
                    INPUT_3,
                    INPUT_4,
                    INPUT_5,
                    INPUT_6
                }, {
                    OUTPUT_1,
                    OUTPUT_2,
                    OUTPUT_3,
                    OUTPUT_4,
                    OUTPUT_5,
                    OUTPUT_6,
                })
            {
                m_components.push_back(std::make_unique<Gate>());
                m_components.back()->setLink(Gate::INPUT, *this, INPUT_1);
                setLinkInternal(OUTPUT_1, *m_components.back(), Gate::OUTPUT);

                m_components.push_back(std::make_unique<Gate>());
                m_components.back()->setLink(Gate::INPUT, *this, INPUT_2);
                setLinkInternal(OUTPUT_2, *m_components.back(), Gate::OUTPUT);

                m_components.push_back(std::make_unique<Gate>());
                m_components.back()->setLink(Gate::INPUT, *this, INPUT_3);
                setLinkInternal(OUTPUT_3, *m_components.back(), Gate::OUTPUT);

                m_components.push_back(std::make_unique<Gate>());
                m_components.back()->setLink(Gate::INPUT, *this, INPUT_4);
                setLinkInternal(OUTPUT_4, *m_components.back(), Gate::OUTPUT);

                m_components.push_back(std::make_unique<Gate>());
                m_components.back()->setLink(Gate::INPUT, *this, INPUT_5);
                setLinkInternal(OUTPUT_5, *m_components.back(), Gate::OUTPUT);

                m_components.push_back(std::make_unique<Gate>());
                m_components.back()->setLink(Gate::INPUT, *this, INPUT_6);
                setLinkInternal(OUTPUT_6, *m_components.back(), Gate::OUTPUT);
            }
            ~ParallelGateOneInputComponent() noexcept = default;

        protected:
            void dumpInternalComponents() const final
            {
                std::cout << "Internal components:" << std::endl;
                for (const auto &component : m_components)
                    component->dump();
            }

        private:
            internComponent_t m_components;
    };
}

#endif /* !PARALLELGATEONEINPUTCOMPONENT_HPP_ */
