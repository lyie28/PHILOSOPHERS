# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 10:54:51 by user42            #+#    #+#              #
#    Updated: 2021/12/13 11:50:43 by lyie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/philo.c \
	srcs/ft_atoi.c \
	srcs/actions.c \
	srcs/list_tools.c \
	srcs/health_check.c \
	srcs/tools_2.c \
	srcs/tools.c \
	srcs/init.c \
	srcs/ft_atoi_long.c \
	srcs/str_functions.c

OBJS = ${SRCS:.c=.o}
INCLUDES = includes/philo.h
NAME = philo
CC = clang
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
all: ${NAME}
bonus: ${NAME_BONUS}

.c.o:
		${CC} ${CFLAGS} -I${INCLUDES} -c $< -o ${<:.c=.o}

$(NAME)	: ${OBJS}
	${CC} ${CFLAGS} -I${INCLUDES} ${OBJS} -pthread -o $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
