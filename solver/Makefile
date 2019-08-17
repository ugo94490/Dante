##
## EPITECH PROJECT, 2018
## PSU_dante_2018
## File description:
## Makefile
##

SRC		=	src/main.c		\

OBJ		=	$(SRC:.c=.o)

NAME		=	solver

TESTS_NAME	=	tests_run

CC		=	gcc

CFLAGS		=

CPPFLAGS	+=	-W -Wall -Wextra -Wshadow -I./include

TEST_FLAGS	=	-lcriterion --coverage

RM		=	rm -f

all		:	$(NAME)

$(NAME) 	: 	$(OBJ)
			@$(CC) -o $(NAME) $(CPPFLAGS) $(OBJ)
			@echo -e $(GREEN)$(GREEN_B)[Done]$(N_COLOR)

tests_run 	:
			@$(CC) $(SRC_T) -o $(TESTS_NAME) $(CPPFLAGS) $(TEST_FLAGS)
			@./$(TESTS_NAME)
			@mv *.gc* tests/

clean 		:
			$(RM) $(OBJ)
			$(RM) $(OBJ_L)

tests_clean 	:
			$(RM) tests/*.gcda
			$(RM) tests/*.gcno
			$(RM) *.gc*
			$(RM) test_run

fclean 		:	clean tests_clean
			$(RM) $(NAME) library/$(NAME_L) $(TESTS_NAME)

re		:	fclean all

.PHONY 		:	all bookstore clean fclean re tests_run tests_clean $name
