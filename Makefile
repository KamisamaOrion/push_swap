# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 21:57:44 by mhervoch          #+#    #+#              #
#    Updated: 2024/01/10 20:56:52 by mhervoch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

HEAD = push_swap.h

SRCS =  ./main.c \
		./push_swa_utils.c \
		./push_swap.c \
		./push_swap_inst.c \
		./push_swap_inst_2.c \
		./push_swap_parsing.c \
		./opti_push_swap.c \
		./ft_split.c \
		./ft_strlcpy.c

OBJS = ${SRCS:.c=.o}

all:${NAME}

$.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}:${OBJS}
	${CC} ${CFLAGS} $(OBJS) -o $(NAME)

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
