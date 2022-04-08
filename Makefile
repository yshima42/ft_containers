NAME_STL	:=	tester_stl
NAME_FT		:=	tester_ft

SRCS			:=	tests/main.cpp tests/test_vector.cpp tests/Timer.cpp tests/benchmark_vector.cpp \

OBJDIR_STL	:=	./objs_stl
OBJDIR_FT	:=	./objs_ft

OBJS_STL		:=	$(addprefix $(OBJDIR_STL)/, $(SRCS:.cpp=.o))
OBJS_FT		:=	$(addprefix $(OBJDIR_FT)/, $(SRCS:.cpp=.o))

INC				:=	-I./containers -I./tests

CXX				:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98 $(INC)

all				:	$(NAME_STL) $(NAME_FT)

$(NAME_STL)	:	$(OBJS_STL)
	$(CXX) $(CXXFLAGS) -o $(NAME_STL) $(OBJS_STL)

$(NAME_FT)	:	$(OBJS_FT)
	$(CXX) $(CXXFLAGS) -o $(NAME_FT) -D IS_FT=1 $(OBJS_FT)

$(OBJDIR_STL)/%.o: %.cpp
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR_FT)/%.o: %.cpp
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CXX) $(CXXFLAGS) -o $@ -D IS_FT=1 -c $<

run		:	all
	./tester_stl

clean	:
	rm -rf $(OBJDIR_STL) $(OBJDIR_FT)

fclean		: clean
	$(RM) $(NAME_STL) $(NAME_FT)

re				:	fclean all

.PHONY	: all clean fclean re
