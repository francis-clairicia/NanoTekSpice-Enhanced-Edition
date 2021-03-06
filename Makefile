##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC_MAIN				=	src/main.cpp

SRC_NANOTEKSPICE		=	src/nanotekspice.cpp

SRC_EXCEPTIONS			=	src/Exception/BadComponentNameException.cpp					\
							src/Exception/BadComponentTypeException.cpp					\
							src/Exception/BadPinException.cpp							\
							src/Exception/ConstComponentException.cpp					\
							src/Exception/Exception.cpp									\
							src/Exception/FileException.cpp								\
							src/Exception/InputValueException.cpp						\
							src/Exception/NoChipsetException.cpp						\
							src/Exception/Parser/ComponentLinkException.cpp				\
							src/Exception/Parser/ComponentNameExistsException.cpp		\
							src/Exception/Parser/ComponentNameUnknownException.cpp		\
							src/Exception/Parser/ComponentTypeUnknownException.cpp		\
							src/Exception/Parser/ParserException.cpp					\
							src/Exception/Parser/SyntaxException.cpp

SRC_CIRCUIT				=	src/Circuit.cpp												\
							src/Parser.cpp

SRC_UTILS				=	src/Utils/string_operations.cpp

SRC_ONEPIN_COMPONENTS	=	src/Component/SinglePin/SinglePinComponent.cpp				\
							src/Component/SinglePin/ClockComponent.cpp					\
							src/Component/SinglePin/InputComponent.cpp					\
							src/Component/SinglePin/OutputComponent.cpp

SRC_BOX_COMPONENTS		=	src/Component/Box/BoxComponent.cpp							\
							src/Component/Box/Component4008.cpp							\
							src/Component/Box/Component4013.cpp							\
							src/Component/Box/Component4514.cpp							\
							src/Component/Box/Sum/SumComponent.cpp

SRC_GATES				=	src/Component/Gate/AGate.cpp								\
							src/Component/Gate/GateAND.cpp								\
							src/Component/Gate/GateNAND.cpp								\
							src/Component/Gate/GateNOR.cpp								\
							src/Component/Gate/GateNOT.cpp								\
							src/Component/Gate/GateOneInput.cpp							\
							src/Component/Gate/GateOR.cpp								\
							src/Component/Gate/GateTwoInputs.cpp						\
							src/Component/Gate/GateXOR.cpp

SRC_CALC_COMPONENTS		=	src/Component/Calculation/ACalculationComponent.cpp			\
							src/Component/Calculation/LoggerComponent.cpp				\
							src/Component/Calculation/Component4017.cpp					\
							src/Component/Calculation/Component4040.cpp					\
							src/Component/Calculation/Component4512.cpp					\
							src/Component/Calculation/FlipFlop/DTypeFlipFlopWithSR.cpp

SRC_COMPONENTS			=	src/Component/ComponentFactory.cpp							\
							src/Component/Pin.cpp										\
							$(SRC_ONEPIN_COMPONENTS)									\
							$(SRC_BOX_COMPONENTS)										\
							$(SRC_GATES)												\
							$(SRC_CALC_COMPONENTS)

SRC						=	$(SRC_MAIN)													\
							$(SRC_NANOTEKSPICE)											\
							$(SRC_EXCEPTIONS)											\
							$(SRC_CIRCUIT)												\
							$(SRC_COMPONENTS)											\
							$(SRC_UTILS)

SRC_TEST				=	$(SRC_COMPONENTS)											\
							$(SRC_EXCEPTIONS)											\
							$(SRC_UTILS)

CXXFLAGS				=	-Wall -Wextra -std=c++17

CPPFLAGS				=	-I./include/												\
							-I./include/Exception/										\
							-I./include/Exception/Parser/								\
							-I./include/Component/										\
							-I./include/Component/SinglePin/							\
							-I./include/Component/Box/									\
							-I./include/Component/Box/ParallelGate						\
							-I./include/Component/Box/ParallelGate/OneInput				\
							-I./include/Component/Box/ParallelGate/TwoInputs			\
							-I./include/Component/Box/Sum/								\
							-I./include/Component/Gate/									\
							-I./include/Component/Calculation							\
							-I./include/Component/Calculation/FlipFlop/					\
							-I./include/Utils/

OBJ						=	$(SRC:.cpp=.o)

NAME					=	nanotekspice

all:	$(NAME)

$(NAME):	CXXFLAGS += -O2
$(NAME):	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

tests_run:	CXXFLAGS += --coverage
tests_run:	LDLIBS += -lcriterion
tests_run:
	@find -name "*.gc*" -delete
	$(CXX) -o unit_tests $(SRC_TEST) tests/**/*.cpp $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	-./unit_tests --verbose
	$(RM) unit_tests test*.gc*
	mkdir -p coverage
	mv *.gc* coverage/

debug:	CXXFLAGS += -g
debug:
	$(CXX) -o debug $(SRC) $(LDFLAGS) $(LDLIBS) $(CXXFLAGS) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) debug unit_tests *.gc*

fclean:	clean
	$(RM) $(NAME)

re::	fclean
re::	all

.PHONY:	all tests_run debug clean fclean re
