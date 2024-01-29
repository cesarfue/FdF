# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cesar <cesar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 12:34:28 by cesar             #+#    #+#              #
#    Updated: 2024/01/29 16:16:45 by cesar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			=	srcs/main.c srcs/parsing.c srcs/draw.c srcs/positions.c srcs/mem.c \
	srcs/colors.c srcs/events.c srcs/utils.c
OBJS			=	$(patsubst srcs/%.c, objs/%.o, $(SRCS))
CC				=	cc -g
FLAGS			=	-Wall -Wextra
INCLUDES		=	-Iincludes -Ilibft
LIBFT_DIR		=	./libft
MLX_INCLUDES	=	-Imlx_linux -I/usr/include 
MLX_DIR			=	./mlx_linux
MLX_LINKS		=	-lmlx_Linux -lXext -lX11 -lm -lz
RM				=	rm -r
NAME			=	FdF

objs/%.o	: srcs/%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDES) $(MLX_INCLUDES) -c $< -o $@

$(NAME)		:	$(OBJS) Makefile
	$(MAKE) -C ./libft
	$(MAKE) -C ./mlx_linux
	$(CC) $(FLAGS) $(OBJS) -no-pie -L$(LIBFT_DIR) -L$(MLX_DIR) -L/usr/lib -lft $(MLX_LINKS) -o $(NAME)

all			:	$(NAME)

clean		:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean		:    clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

re			:    fclean all

.PHONY		:	all clean fclean re