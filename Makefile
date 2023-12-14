# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 18:46:17 by cefuente          #+#    #+#              #
#    Updated: 2023/12/14 15:33:03 by cefuente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/main.c
OBJS	=	$(SRCS:.c=.o)
HEADER	=	includes/fdf.h
CC		=	cc
LFLAGS	=	-L./mlx -lmlx_Linux
FLAGS	=	-Wall -Wextra -Werror -I./mlx
RM		=	rm -rf
LIBFT	=	./libft/libft.a
NAME	=	FdF

all	:	$(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

${NAME}    :    ${OBJS} ${LIBFT}
	${CC} ${FLAGS} -o $@ ${LFLAGS}

%.o        :    %.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

clean    :
	rm -f ${OBJS}

fclean    :    clean
	rm -f ${NAME}

re        :    fclean all

.PHONY    :    all clean fclean re