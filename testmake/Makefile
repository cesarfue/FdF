# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cesar <cesar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 09:56:44 by cesar             #+#    #+#              #
#    Updated: 2024/01/30 09:59:57 by cesar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
SRCS_DIR	=	srcs
OBJS_DIR	=	objs
INCLUDES	=	includes
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft
LIBMLX		=	./mlx_linux/libmlx_Linux.a
MLX_DIR		=	./mlx_linux

SRCS		=	colors.c \
				draw.c \
				events.c \
				main.c \
				mem.c \
				parsing.c \
				utils.c	\
				positions.c

CC			= cc
LIBFLAGS	= ar -rcs
RM			= rm -rf

CFLAGS		= -Wall -Wextra -Werror -g 
MLXFLAGS	= -lmlx_Linux -lXext -lX11 -lm -lz
MK_FLAG		= --no-print-directory


OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX_DIR) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	echo "Done compiling fdf!"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	echo "Creating $(NAME) .o files..."
	mkdir -p $(@D)
	$(CC) -I $(INCLUDES) $(CFLAGS) -c $< -o $@

$(LIBFT):
	echo "Making libft..."
	$(MAKE) $(MK_FLAG) -C $(LIBFT_DIR)

$(LIBMLX):
	echo "Making MiniLibX..."
	$(MAKE) $(MK_FLAG) -sC $(MLX_DIR)

clean:
	$(RM) $(OBJS_DIR)
	echo "Deleted $(NAME) $(OBJS_DIR)"
	$(MAKE) $(MK_FLAG) clean -C $(LIBFT_DIR)
	$(MAKE) $(MK_FLAG) clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT)
	echo "Deleted $(NAME) and $(LIBFT)"
	
re: fclean all

.PHONY: all clean fclean re