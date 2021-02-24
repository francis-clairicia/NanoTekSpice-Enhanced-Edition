/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ParallelGateTwoInputsComponent
*/

#ifndef PARALLELGATETWOINPUTSCOMPONENT_HPP_
#define PARALLELGATETWOINPUTSCOMPONENT_HPP_

#include <iostream>
#include "BoxComponent.hpp"

namespace nts
{
    template<nts::ComponentType Type, typename Gate>
    class ParallelGateTwoInputsComponent: public nts::BoxComponent {
        public:
            enum Pin
            {
                INPUT_1A = 1,
                INPUT_1B = 2,
                OUTPUT_1 = 3,
                OUTPUT_2 = 4,
                INPUT_2A = 5,
                INPUT_2B = 6,
                INPUT_3A = 8,
                INPUT_3B = 9,
                OUTPUT_3 = 10,
                OUTPUT_4 = 11,
                INPUT_4A = 12,
                INPUT_4B = 13
            };

        public:
            ParallelGateTwoInputsComponent() noexcept:
                BoxComponent(Type, 14, {
                    INPUT_1A,
                    INPUT_1B,
                    INPUT_2A,
                    INPUT_2B,
                    INPUT_3A,
                    INPUT_3B,
                    INPUT_4A,
                    INPUT_4B
                }, {
                    OUTPUT_1,
                    OUTPUT_2,
                    OUTPUT_3,
                    OUTPUT_4
                })
            {
                m_components.push_back(std::make_unique<Gate>());
                m_components.back()->setLink(Gate::INPUT1, *this, INPUT_1A);
                m_components.back()->setLink(Gate::INPUT2, *this, INPUT_1B);
                setLinkInternal(OUTPUT_1, *m_components.back(), Gate::OUTPUT);

                m_components.push_back(std::make_unique<Gate>());
                m_components.back()->setLink(Gate::INPUT1, *this, INPUT_2A);
                m_components.back()->setLink(Gate::INPUT2, *this, INPUT_2B);
                setLinkInternal(OUTPUT_2, *m_components.back(), Gate::OUTPUT);

                m_components.push_back(std::make_unique<Gate>());
                m_components.back()->setLink(Gate::INPUT1, *this, INPUT_3A);
                m_components.back()->setLink(Gate::INPUT2, *this, INPUT_3B);
                setLinkInternal(OUTPUT_3, *m_components.back(), Gate::OUTPUT);

                m_components.push_back(std::make_unique<Gate>());
                m_components.back()->setLink(Gate::INPUT1, *this, INPUT_4A);
                m_components.back()->setLink(Gate::INPUT2, *this, INPUT_4B);
                setLinkInternal(OUTPUT_4, *m_components.back(), Gate::OUTPUT);
            }

            ~ParallelGateTwoInputsComponent() noexcept = default;

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

#endif /* !PARALLELGATETWOINPUTSCOMPONENT_HPP_ */
