##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC_MAIN			=	src/main.cpp

SRC_TEST			=	src/nanotekspice.cpp

SRC					=	$(SRC_MAIN) $(SRC_TEST)

CXXFLAGS				=	-Wall -Wextra

CPPFLAGS			=	-I./include/

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
	$(CXX) -o unit_tests $(SRC_TEST) tests/*.cpp $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	-./unit_tests
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
