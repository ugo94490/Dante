##
## EPITECH PROJECT, 2018
## PSU_dante_2018
## File description:
## Makefile
##

SRC		=	main.c	\
			src/tools.c		\
			src/check_error.c	\
			src/create_info.c	 \
			src/node_tools.c	\
			src/tools_maze.c	\
			src/check_direction.c	\
			src/generator.c

SRC_T		=

OBJ		=	$(SRC:.c=.o)

OBJ_T		=	$(SRC_T:.c=.o)

NAME		=	generator

TESTS_NAME	=	tests_run

CC		=	gcc

CFLAGS		=	-W -Wall -Wshadow

CPPFLAGS	=	-I./include

TEST_FLAGS	=	-lcriterion --coverage

RM		=	rm -f

$(NAME) 	: 	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ)

all		:	$(NAME)

tests_run 	:
			@$(CC) $(SRC_T) $(CFLAGS) $(CPPFLAGS) $(TEST_FLAGS) -o $(TESTS_NAME)
			@./$(TESTS_NAME)
			@mv *.gc* tests/

clean 		:
			$(RM) $(OBJ)
			$(RM) $(OBJ_T)

tests_clean 	:
			$(RM) tests/*.gcda
			$(RM) tests/*.gcno
			$(RM) *.gc*
			$(RM) test_run

fclean 		:	clean tests_clean
			$(RM) $(NAME) $(TESTS_NAME)

re		:	fclean all

.PHONY 		:	all clean fclean re tests_run tests_clean $name
