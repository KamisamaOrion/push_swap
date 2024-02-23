# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 21:57:44 by mhervoch          #+#    #+#              #
#    Updated: 2024/02/23 19:21:51 by mhervoch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

HEAD = push_swap.h

SRCS =  ./main.c \
		./push_swa_utils.c \
		./push_swa_utils_2.c \
		./push_swa_utils_3.c \
		./push_swap.c \
		./push_swap_inst.c \
		./push_swap_inst_2.c \
		./push_swap_inst_3.c \
		./push_swap_parsing.c \
		./push_swap_parsing_2.c \
		./push_swap_parsing_3.c \
		./push_swap_parsing_4.c \
		./opti_push_swap.c \
		./ft_split.c \
		./ft_strlcpy.c \
		./push_swap_action.c \

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
