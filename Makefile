# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 12:34:28 by cesar             #+#    #+#              #
#    Updated: 2024/01/26 16:19:40 by cefuente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=	srcs/main.c srcs/parsing.c srcs/draw.c srcs/positions.c srcs/mem.c srcs/colors.c srcs/events.c srcs/utils.c
OBJS	=	$(addprefix objs/, $(notdir $(SRCS:.c=.o)))
HEADER	=	includes/fdf.h
CC		=	cc -g 
FLAGS	=	-Wall -Wextra
RM		=	rm -rf
AR		=	ar rcs
LIBFT	=	libft/libft.a
NAME	=	FdF

all		:	$(NAME)

$(LIBFT):
	$(MAKE) -C ./libft
	
mlx	:
	$(MAKE) -C ./mlx_linux

$(NAME)	:	$(OBJS) $(LIBFT) mlx Makefile
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -no-pie -o $(NAME) $(LIBFT)

objs/%.o		: srcs/%.c $(HEADER) $(LIBFT)
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