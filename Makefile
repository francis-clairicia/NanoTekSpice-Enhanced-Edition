##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC_MAIN			=	src/main.cpp

SRC_NANOTEKSPICE	=	src/nanotekspice.cpp

SRC_EXCEPTIONS		=	src/Exception.cpp

SRC_PARSER			=	src/Parser.cpp

SRC_UTILS			=	src/Utils/string_operations.cpp

SRC_COMPONENTS		=	src/Component/ComponentFactory.cpp	\
						src/Component/IOComponent.cpp		\
						src/Component/InputComponent.cpp	\
						src/Component/OutputComponent.cpp	\
						src/Component/ClockComponent.cpp	\
						src/Component/ConstComponent.cpp	\
						src/Component/TrueComponent.cpp		\
						src/Component/FalseComponent.cpp	\
						src/Component/AComponent.cpp		\
						src/Component/Component4001.cpp		\
						src/Component/Component4008.cpp		\
						src/Component/Component4011.cpp		\
						src/Component/Component4013.cpp		\
						src/Component/Component4030.cpp		\
						src/Component/Component4069.cpp		\
						src/Component/Component4071.cpp		\
						src/Component/Component4081.cpp

SRC_GATES			=	src/Gate/OneInputGate.cpp			\
						src/Gate/TwoInputsGate.cpp			\
						src/Gate/GateAND.cpp				\
						src/Gate/GateOR.cpp					\
						src/Gate/GateXOR.cpp				\
						src/Gate/GateNOR.cpp				\
						src/Gate/GateNAND.cpp				\
						src/Gate/GateNOT.cpp				\

SRC_SUM				=	src/Sum/SumComponent.cpp

SRC_FLIPFLOP		=	src/FlipFlop/FlipFlopComponent.cpp

SRC					=	$(SRC_MAIN)							\
						$(SRC_NANOTEKSPICE)					\
						$(SRC_EXCEPTIONS)					\
						$(SRC_PARSER)						\
						$(SRC_UTILS)						\
						$(SRC_COMPONENTS)					\
						$(SRC_GATES)						\
						$(SRC_SUM)							\
						$(SRC_FLIPFLOP)

SRC_TEST			=	$(SRC_COMPONENTS)					\
						$(SRC_GATES)						\
						$(SRC_SUM)							\
						$(SRC_FLIPFLOP)						\
						$(SRC_EXCEPTIONS)					\
						$(SRC_UTILS)

CXXFLAGS			=	-Wall -Wextra

CPPFLAGS			=	-I./include/						\
						-I./include/Component/				\
						-I./include/Gate/					\
						-I./include/Sum/					\
						-I./include/FlipFlop/				\
						-I./include/Utils/

OBJ					=	$(SRC:.cpp=.o)

NAME				=	nanotekspice

all:	$(NAME)

$(NAME):	CXXFLAGS += -O2
$(NAME):	$(LDLIBS) $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

tests_run:	CXXFLAGS += --coverage
tests_run:	LDLIBS += -lcriterion
tests_run:	$(LDLIBS)
	@find -name "*.gc*" -delete
	$(CXX) -o unit_tests $(SRC_TEST) tests/**/*.cpp $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	-./unit_tests --verbose
	$(RM) unit_tests test*.gc*
	mkdir -p coverage
	mv *.gc* coverage/

debug:	CXXFLAGS += -g
debug:	$(LDLIBS)
	$(CXX) -o debug $(SRC) $(LDFLAGS) $(LDLIBS) $(CXXFLAGS) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) debug unit_tests *.gc*

fclean:	clean
	rm -f $(NAME)

re::	fclean
re::	all

.PHONY:	all tests_run debug clean fclean re
