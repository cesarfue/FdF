# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cesar <cesar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 12:34:28 by cesar             #+#    #+#              #
#    Updated: 2024/01/30 13:51:45 by cesar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			=	main.c parsing.c draw.c positions.c mem.c \
	colors.c events.c utils.c
SRCS_DIR		=	srcs
OBJS_DIR		=	objs
CC				=	cc
FLAGS			=	-Wall -Wextra -g 
RM				=	rm -rf
NAME			=	FdF
DEPS_FLAGS		=	-MMD -MP
INCLUDES_DIR	=	includes/
	
LIBFT			=	libft/libft.a 
LIBFT_DIR		=	libft/
LIBFT_LINK		=	ft

MLX				= 	mlx_linux/libmlx_Linux.a
MLX_DIR			=	mlx_linux/
MLX_LINKS		=	mlx_Linux

USRLIB_DIR		=	/usr/lib/
USRLIB_LINKS	=	-lXext -lX11 -lm -lz

.PHONY	:	libft
libft	:
	$(MAKE) -C $(LIBFT_DIR)

.PHONY	:	mlx
mlx		:
	$(MAKE) -C $(MLX_DIR)

OBJS			=	$(SRCS:%.c=$(OBJS_DIR)/%.o)

$(OBJS_DIR)/%.o	: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) $(DEPS_FLAGS) -I$(INCLUDES_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(USRLIB_DIR) -c $< -o $@
	
$(NAME)		:	mlx libft $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -no-pie -L$(LIBFT_DIR) -L$(MLX_DIR) -L$(USRLIB_DIR) -l$(LIBFT_LINK) -l$(MLX_LINKS) $(USRLIB_LINKS) -o $(NAME)

all			:	$(NAME) 

clean		:
	$(RM) $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean		:    clean
	$(RM) $(NAME) $(LIBFT)

re			:    fclean all

.PHONY		:	all clean fclean re