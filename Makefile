##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC_MAIN				=	src/main.cpp

SRC_PARSER				=	src/Args.cpp

SRC_NANOTEKSPICE		=	src/nanotekspice.cpp

SRC_EXCEPTIONS			=	src/Exception/BadComponentNameException.cpp					\
							src/Exception/BadComponentTypeException.cpp					\
							src/Exception/BadPinException.cpp							\
							src/Exception/ComponentNameOverride.cpp						\
							src/Exception/Exception.cpp									\
							src/Exception/FileException.cpp								\
							src/Exception/InputValueException.cpp						\
							src/Exception/NoChipsetException.cpp						\
							src/Exception/NoIOPinException.cpp							\
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
							src/Component/Box/Component4094.cpp							\
							src/Component/Box/Sum/SumComponent.cpp

SRC_GATES				=	src/Component/Gate/AGate.cpp								\
							src/Component/Gate/GateAND.cpp								\
							src/Component/Gate/GateNAND.cpp								\
							src/Component/Gate/GateNOR.cpp								\
							src/Component/Gate/GateNOT.cpp								\
							src/Component/Gate/GateOneInput.cpp							\
							src/Component/Gate/GateOR.cpp								\
							src/Component/Gate/GateTransmission.cpp						\
							src/Component/Gate/GateTwoInputs.cpp						\
							src/Component/Gate/GateXOR.cpp

SRC_CALC_COMPONENTS		=	src/Component/Calculation/ACalculationComponent.cpp			\
							src/Component/Calculation/LoggerComponent.cpp				\
							src/Component/Calculation/Component2716.cpp					\
							src/Component/Calculation/Component4017.cpp					\
							src/Component/Calculation/Component4040.cpp					\
							src/Component/Calculation/Component4512.cpp					\
							src/Component/Calculation/Component4514.cpp					\
							src/Component/Calculation/Component4801.cpp					\
							src/Component/Calculation/FlipFlop/DTypeFlipFlopWithSR.cpp

SRC_COMPONENTS			=	src/Component/ComponentFactory.cpp							\
							src/Component/ComponentType.cpp								\
							src/Pin/Pin.cpp												\
							src/Pin/PinList.cpp											\
							$(SRC_ONEPIN_COMPONENTS)									\
							$(SRC_BOX_COMPONENTS)										\
							$(SRC_GATES)												\
							$(SRC_CALC_COMPONENTS)

SRC						=	$(SRC_MAIN)													\
							$(SRC_PARSER)												\
							$(SRC_NANOTEKSPICE)											\
							$(SRC_EXCEPTIONS)											\
							$(SRC_CIRCUIT)												\
							$(SRC_COMPONENTS)											\
							$(SRC_UTILS)

SRC_TEST				=	$(SRC_COMPONENTS)											\
							$(SRC_CIRCUIT)												\
							$(SRC_EXCEPTIONS)											\
							$(SRC_UTILS)												\

SRC_UNIT_TEST			=	tests/Circuit/test_Circuit.cpp								\
							tests/Circuit/test_Parser.cpp								\
							tests/Component/advanced/test_and_or_not.cpp				\
							tests/Component/test_ClockComponent.cpp						\
							tests/Component/test_Component4008.cpp						\
							tests/Component/test_Component4017.cpp						\
							tests/Component/test_Component4040.cpp						\
							tests/Component/test_Component4094.cpp						\
							tests/Component/test_Component4512.cpp						\
							tests/Component/test_Component4514.cpp						\
							tests/Component/test_Component4801.cpp						\
							tests/Component/test_ConstComponent.cpp						\
							tests/Component/test_IOComponent.cpp						\
							tests/Component/test_LoggerComponent.cpp					\
							tests/FlipFlop/test_FlipFlop.cpp							\
							tests/Gate/test_GateAND.cpp									\
							tests/Gate/test_GateNAND.cpp								\
							tests/Gate/test_GateNOR.cpp									\
							tests/Gate/test_GateNOT.cpp									\
							tests/Gate/test_GateOR.cpp									\
							tests/Gate/test_GateTransmission.cpp						\
							tests/Gate/test_GateXOR.cpp									\
							tests/Sum/test_Sum.cpp										\
							tests/Utils/test_string_endswith.cpp						\
							tests/Utils/test_string_is_number.cpp						\
							tests/Utils/test_string_split.cpp							\
							tests/Utils/test_trim_trailing_whitespace.cpp

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
							-I./include/Pin/											\
							-I./include/Utils/											\
							-I./include/Memory/

OBJ						=	$(SRC:.cpp=.o)

OBJ_TEST				=	$(SRC_TEST:.cpp=.o)

OBJ_UNIT_TEST			=	$(SRC_UNIT_TEST:.cpp=.o)

NAME					=	nanotekspice

all:	CXXFLAGS += -O2
all:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

tests_run::	LDLIBS += -lcriterion -lgcov
tests_run::	clean
tests_run::	$(OBJ_TEST) $(OBJ_UNIT_TEST)
	@find -name "*.gc*" -delete
	$(CXX) -o unit_tests $(OBJ_TEST) $(OBJ_UNIT_TEST) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)
	./unit_tests --verbose --always-succeed
	$(RM) -r unit_tests coverage

debug:	CXXFLAGS += -g
debug:	$(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_UNIT_TEST)
	$(RM) debug unit_tests *.gc*

fclean:	clean
	$(RM) $(NAME)

re::	fclean
re::	all

.PHONY:	all tests_run debug clean fclean re
