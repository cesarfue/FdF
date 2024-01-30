# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 12:34:28 by cesar             #+#    #+#              #
#    Updated: 2024/01/30 15:17:58 by cefuente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	FdF


SRCS_LIST			=	main.c parsing.c draw.c positions.c mem.c \
	colors.c events.c utils.c
SRCS_DIR		=	srcs/
SRCS			=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS_DIR		=	objs/
OBJS			=	$(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)%.o,$(SRCS))


CC				=	cc
FLAGS			=	-Wall -Wextra -g 
RM				=	rm -rf
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

all			:	$(NAME) 

$(NAME)		:	mlx libft $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -no-pie -L$(LIBFT_DIR) -L$(MLX_DIR) -L$(USRLIB_DIR) -l$(LIBFT_LINK) -l$(MLX_LINKS) $(USRLIB_LINKS) -o $(NAME)
	

$(OBJS_DIR)%.o	: $(SRCS_DIR)%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) $(DEPS_FLAGS) -I$(INCLUDES_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(USRLIB_DIR) -c $< -o $@

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