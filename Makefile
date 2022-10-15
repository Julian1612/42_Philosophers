# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 17:23:51 by jschneid          #+#    #+#              #
#    Updated: 2022/10/15 15:34:45 by jschneid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -Wall -Werror -Wextra -pthread

SRC = main.c

CC = gcc -g

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@echo "$(BLUE)$(FETT)-_-COMPILING-_-$(RESET)"
	@echo "\033[1;32mCompiling  \033[1;97m$< \033[1;0m"
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o ./philo/$(NAME)
	@echo "$(YELLOW)Executable created"
	@echo "$(GREEN)$(FETT)Make done$(RESET)"

clean:
	@/bin/rm -f $(OBJ)
	@echo "$(YELLOW)Objectfiles deleted"
	@echo "$(GREEN)$(FETT)Make clean done$(RESET)"

fclean: clean
	@/bin/rm -f ./philo/$(NAME)
	@echo "$(YELLOW)Executable deleted"
	@echo "$(GREEN)$(FETT)Make fclean done$(RESET)"

re: fclean all
	@echo "$(GREEN)$(FETT)Make re done$(RESET)"

ex: all
	./philo/philo

.PHONY:	all bonus clean fclean re lib

# text modifiers #
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
RESET	=	\033[0m
FETT	=	\033[1m
