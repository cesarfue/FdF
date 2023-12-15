# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cesar <cesar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 12:34:28 by cesar             #+#    #+#              #
#    Updated: 2023/12/15 16:01:14 by cesar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=	srcs/main.c
OBJS	=	$(addprefix objs/, $(notdir $(SRCS:.c=.o)))
HEADER	=	includes/fdf.h
CC		=	cc
FLAGS	=	-Wall -Wextra
RM		=	rm -rf
AR		=	ar rcs
LIBFT	=	./libft/libft.a
NAME	=	FdF

all		:	$(NAME)

$(LIBFT):
	$(MAKE) -C ./libft
	
mlx	:
	$(MAKE) -C ./mlx_linux

$(NAME)	:	$(OBJS) $(LIBFT) mlx Makefile
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

objs/%.o		: srcs/%.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean	:
	${RM} ${OBJS}
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./mlx_linux clean

fclean	:    clean
	${RM} ${NAME}
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./mlx_linux clean

re		:    fclean all

.PHONY	: all bonus clean fclean re