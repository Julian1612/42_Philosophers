#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschneid <jschneid@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 12:34:30 by jschneid          #+#    #+#              #
#    Updated: 2022/10/27 12:34:30 by jschneid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	philo
CC		:=	gcc
FLAGS	:=	-Wall -Wextra -Werror -pthread
RM		:=	rm -f
RMDIR	:=	rm -rf

SRCS	:=	./src/initialize.c \
			./src/main.c \
			./src/parsing_00.c \
			./src/routine_00.c \
			./src/routine_01.c \
			./src/threads.c \
			./src/utils_00.c \
			./src/thread_check.c

OBJS	:=	$(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

CLR_RMV	:=	\033[0m
RED		:=	\033[1;31m
GREEN	:=	\033[1;32m
YELLOW	:=	\033[1;33m
BLUE	:=	\033[1;34m
CYAN 	:=	\033[1;36m

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			mkdir ./philo
			${CC} ${FLAGS} -o ./philo/${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RMDIR} philo
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re
