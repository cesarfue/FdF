# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 12:34:28 by cesar             #+#    #+#              #
#    Updated: 2024/02/02 16:00:06 by cefuente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	FdF

SRCS_LIST			=	main.c parsing.c draw.c positions.c \
	colors.c key_events.c utils.c mouse_events.c exit.c \

SRCS_DIR		=	srcs/
OBJS_DIR		=	objs/
INCLUDES_DIR	=	includes/

OBJS			=	$(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS))
SRCS			=	$(addprefix $(SRCS_DIR),$(SRCS_LIST))

CC				=	cc
FLAGS			=	-Wall -Wextra -Werror -g 
RM				=	rm -rf
	
LIBFT			=	libft/libft.a 
LIBFT_DIR		=	libft/
LIBFT_LINK		=	ft

MLX				= 	mlx_linux/libmlx_Linux.a
MLX_DIR			=	mlx_linux/
MLX_LINKS		=	mlx_Linux

USRLIB_DIR		=	/usr/lib/
USRLIB_LINKS	=	-lXext -lX11 -lm -lz

all			:	$(NAME)

$(NAME)		:	mlx libft $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -no-pie -L$(LIBFT_DIR) -L$(MLX_DIR) -L$(USRLIB_DIR) -l$(LIBFT_LINK) -l$(MLX_LINKS) $(USRLIB_LINKS) -o $(NAME)


$(OBJS_DIR)%.o	:	%.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -I$(INCLUDES_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(USRLIB_DIR) -c $< -o $@

mlx		:
	$(MAKE) -C $(MLX_DIR)

libft	:
	$(MAKE) -C $(LIBFT_DIR)

clean		:
	$(RM) $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean		:    clean
	$(RM) $(NAME) $(LIBFT)

re			:    fclean all

.PHONY		:	all clean fclean re mlx libft