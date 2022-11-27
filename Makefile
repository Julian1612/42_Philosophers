# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 17:23:51 by jschneid          #+#    #+#              #
#    Updated: 2022/11/27 18:05:13 by jschneid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -Wall -Werror -Wextra -pthread -g
# -fsanitize=thread

SRC = ./src/main.c ./src/initialize.c ./src/join_destroy.c \
./src/parsing_00.c ./src/threads.c ./src/utils_00.c \
./src/routine_00.c ./src/routine_01.c ./src/thread_check.c \

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
	./philo/philo

.PHONY:	all bonus clean fclean re lib

# text modifiers #
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
RESET	=	\033[0m
FETT	=	\033[1m
