##
## EPITECH PROJECT, 2018
## PSU_dante_2018
## File description:
## Makefile
##

SRC		=	src/main.c		\

SRC_T		=

OBJ		=	$(SRC:.c=.o)

OBJ_T		=	$(SRC_T:.c=.o)

NAME		=	solver

TESTS_NAME	=	tests_run

CC		=	gcc

CFLAGS		+=	-W -Wall -Wextra -Wshadow

CPPFLAGS	=	-I./include

TEST_FLAGS	=	-lcriterion --coverage

RM		=	rm -f

all		:	$(NAME)

$(NAME) 	: 	$(OBJ)
			@$(CC) $(OBJ) -o $(NAME)

tests_run 	:
			@$(CC) $(CFLAGS) $(CPPFLAGS) $(TEST_FLAGS) $(SRC_T) -o $(TESTS_NAME)
			@./$(TESTS_NAME)
			@mv *.gc* tests/

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
