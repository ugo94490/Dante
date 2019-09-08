##
## EPITECH PROJECT, 2018
## PSU_dante_2018
## File description:
## Makefile
##

NAME		=	DANTE

RED		=	'\033[1;31m'

RED_B		=	'\033[5;91m'

GREEN		= 	'\033[1;92m'

GREEN_B		=	'\033[5;92m'

N_COLOR		=	'\033[1;0m'

all		:	$(NAME)

buildin		:
			@echo -e $(GREEN)[BUILDING] : $(NAME) $(N_COLOR)

$(NAME) 	: 	buildin
			@make -C solver
			@make -C generator
			@echo -e $(GREEN)$(GREEN_B)[Done]$(N_COLOR)

tests_run 	:
			@make tests_run -C solver
			@make tests_run -C generator

clean 		:
			@echo -e $(RED)============= Cleaning ==============$(N_COLOR)
			@make clean -C solver
			@make clean -C generator
			@echo -e $(RED)[OK]$(N_COLOR)

tests_clean 	:
			@echo -e $(RED)========== Cleaning : TEST ==========$(N_COLOR)
			@make tests_clean -C solver
			@make tests_clean -C generator
			@echo -e $(RED)[OK]$(N_COLOR)

fclean 		:	clean tests_clean
			@echo -e $(RED)========= Cleaning : FINAL ==========$(N_COLOR)
			@make fclean -C solver
			@make fclean -C generator
			@echo -e $(RED)[OK]$(N_COLOR)

re		:	fclean all

.PHONY 		:	all clean fclean re tests_run tests_clean
