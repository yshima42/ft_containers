NAME_STL	:=	tester_stl
NAME_FT		:=	tester_ft

SRCS		:=	$(shell find * -name \*.cpp)
OBJDIR_STL	:=	./objs_stl
OBJDIR_FT	:=	./objs_ft

OBJS_STL		:=	$(addprefix $(OBJDIR_STL)/, $(SRCS:.cpp=.o))
DEPS_STL	:= $(addprefix $(OBJDIR_STL)/, $(SRCS:.o=.d))
OBJS_FT		:=	$(addprefix $(OBJDIR_FT)/, $(SRCS:.cpp=.o))
DEPS_FT		:= $(addprefix $(OBJDIR_FT)/, $(SRCS:.o=.d))

INC				:=	-I./containers -I./tests

CXX				:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98 -Wshadow -pedantic -MMD -MP $(INC) -g -fsanitize=address

all			:	$(NAME_STL) $(NAME_FT)

-include $(DEPS_STL) $(DEPS_FT)

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

#mapのcoverageのみ確認する
cover : 
	$(CXX) -fprofile-arcs -ftest-coverage -D IS_FT=1 $(SRCS) -o cover_test
	./cover_test -t map
	lcov -c -d . -o cover_test.info
	genhtml cover_test.info -o ./info
	$(RM) -rf cover_test.info
	$(RM) -rf cover_test
	$(RM) -rf *.gcda
	$(RM) -rf *.gcno
	$(RM) -rf *.info
	$(RM) -rf cover_test.dSYM
	open info/index.html

test		:	all
	bash tests/exec_test.sh vector stack map

ft_vector		: all
	./tester_ft -t vector

stl_vector		: all
	./tester_stl -t vector

ft_stack		: all
	./tester_ft -t stack

stl_stack		: all
	./tester_stl -t stack

ft_map		: all
	./tester_ft -t map

stl_map		: all
	./tester_stl -t map

clean	:
	$(RM) -rf $(OBJDIR_STL) $(OBJDIR_FT)
	$(RM) -rf ./info

fclean		: clean
	$(RM) $(NAME_STL) $(NAME_FT)

re				:	fclean all

.PHONY	: all clean fclean re
