##
## EPITECH PROJECT, 2018
## PSU_dante_2018
## File description:
## Makefile
##

SRC		=	src/main.c			\
			src/solver.c			\
			src/create_maze.c		\
			src/create_ctrl.c		\
			src/ctrl_lines.c		\
			src/useful_fct.c		\

SRC_T		=	src/solver.c			\
			tests/t_solver.c		\
			src/create_ctrl.c		\
			src/create_maze.c		\
			src/ctrl_lines.c		\
			tests/t_create_ctrl.c

OBJ		=	$(SRC:.c=.o)

OBJ_T		=	$(SRC_T:.c=.o)

NAME		=	solver

TESTS_NAME	=	tests_run

CC		=	gcc

CFLAGS		=	-W -Wall -Wshadow -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm

CPPFLAGS	=	-I./include

TEST_FLAGS	=	-lcriterion --coverage -I./tests/include -Wl,--wrap=malloc

RM		=	rm -f

all		:	$(NAME)

$(NAME) 	: 	$(OBJ)
			@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

tests_run 	:
			@$(CC) $(CFLAGS) $(CPPFLAGS) $(TEST_FLAGS) $(SRC_T) -o $(TESTS_NAME)
			@./$(TESTS_NAME)
			@mv *.gc* tests/
			@gcovr . --exclude tests/
			@gcovr . -b --exclude tests/

clean 		:
			$(RM) $(OBJ)
			$(RM) $(OBJ_T)

tests_clean 	:
			$(RM) tests/*.gcda
			$(RM) tests/*.gcno
			$(RM) *.gc*
			$(RM) vg*
			$(RM) test_run

fclean 		:	clean tests_clean
			$(RM) $(NAME) $(TESTS_NAME)

re		:	fclean all

.PHONY 		:	all clean fclean re tests_run tests_clean $name
