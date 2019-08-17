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
			@cd generator && make
			@echo -e "\n"
			@cd solver && make
			@echo -e $(GREEN)$(GREEN_B)[Done]$(N_COLOR)

tests_run 	:
			@$(CC) $(SRC_T) -o $(TESTS_NAME) $(CPPFLAGS) $(TEST_FLAGS)
			@./$(TESTS_NAME)
			@mv *.gc* tests/

clean 		:
			@echo -e $(RED)============= Cleaning ==============$(N_COLOR)
			@cd generator && make clean
			@cd solver && make clean
			@echo -e $(RED)[OK]$(N_COLOR)

tests_clean 	:
			@echo -e $(RED)========== Cleaning : TEST ==========$(N_COLOR)
			@cd generator && make tests_clean
			@cd solver && make tests_clean
			@echo -e $(RED)[OK]$(N_COLOR)

fclean 		:	clean tests_clean
			@echo -e $(RED)========= Cleaning : FINAL ==========$(N_COLOR)
			@cd generator && make fclean
			@cd solver && make fclean
			@echo -e $(RED)[OK]$(N_COLOR)

re		:	fclean all

.PHONY 		:	all bookstore clean fclean re tests_run tests_clean $name
