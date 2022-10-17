# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 17:23:51 by jschneid          #+#    #+#              #
#    Updated: 2022/10/17 17:47:58 by jschneid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -Wall -Werror -Wextra -pthread

SRC = main.c parsing_00.c utils_00.c routine_00.c

CC = gcc -g

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@echo "\033[1;32mCompiling  \033[1;97m$< \033[1;0m"
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(YELLOW)Executable created"
	@echo "$(GREEN)$(FETT)Make done$(RESET)"

clean:
	@/bin/rm -f $(OBJ)
	@echo "$(YELLOW)Objectfiles deleted"
	@echo "$(GREEN)$(FETT)Make clean done$(RESET)"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(YELLOW)Executable deleted"
	@echo "$(GREEN)$(FETT)Make fclean done$(RESET)"

re: fclean all
	@echo "$(GREEN)$(FETT)Make re done$(RESET)"

ex: all
	./philo 2 3 4 5

.PHONY:	all bonus clean fclean re lib

# text modifiers #
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
RESET	=	\033[0m
FETT	=	\033[1m

