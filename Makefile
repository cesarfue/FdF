# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 18:46:17 by cefuente          #+#    #+#              #
#    Updated: 2023/12/14 15:17:29 by cefuente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/main.c
OBJS	=	$(SRCS:.c=.o)
HEADER	=	includes/fdf.h
CC		=	cc
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
LIBFT	=	./libft/libft.a
NAME	=	FdF

all	:	$(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

${NAME}    :    ${OBJS} ${LIBFT}
	${CC} ${FLAGS} -o $@ $@

%.o        :    %.c ${HEADER}
	${CC} ${FLAGS} -Imlx -c $< -o $@

clean    :
	rm -f ${OBJS}

fclean    :    clean
	rm -f ${NAME}

re        :    fclean all

.PHONY    :    all clean fclean re