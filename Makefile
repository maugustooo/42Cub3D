# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 09:44:12 by gude-jes          #+#    #+#              #
#    Updated: 2024/11/12 22:30:55 by maugusto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -g
MLXFLAGS 	= -L ./lib/minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11

NAME		= cub3D
NAME_BONUS	= cub3D_bonus

INC			= -I./includes -I$(LIBFT_PATH) -I$(MLX_PATH)
RM			= rm -rf

GENERAL		= main
PARSE		= parse map_validation read_map read_textures file_content map_content
UTILS		= file_utils init sepuku colors read_textures_utils render_utils
CONTROLS	= controls keys move
RENDER 		= render raycasting draw

ARG			= maps/good/test_whitespace.cub

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

VPATH		= src\
				src/parse\
				src/utils\
				src/controls\
				src/render\

LIBS_PATH	= lib

LIBFT_PATH	= $(LIBS_PATH)/libft
LIBFT		= $(LIBFT_PATH)/libft.a
MLX_PATH	= $(LIBS_PATH)/minilibx-linux
MLX			= $(MLX_PATH)/libmlx_Linux.a

SRC			= $(addsuffix .c, $(GENERAL))\
				$(addsuffix .c, $(PARSE))\
				$(addsuffix .c, $(UTILS))\
				$(addsuffix .c, $(CONTROLS))\
				$(addsuffix .c, $(RENDER))\

BONUS_SRC	= $(addsuffix .c, $(BONUS_GENERAL))\


OBJ_DIR		= obj

OBJS		= $(SRC:%.c=$(OBJ_DIR)/%.o)

BONUS_OBJS	= $(BONUS_SRC:%.c=$(OBJ_DIR)/%.o)

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: deps $(NAME)

deps:
	@$(MAKE) -C $(LIBFT_PATH)
	@$(MAKE) -C $(MLX_PATH)

$(OBJ_DIR):
	@mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(BONUS_INC)

$(NAME): $(OBJ_DIR) $(OBJS) $(DEPS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

bonus: deps $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_DIR) $(BONUS_OBJS) $(DEPS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME_BONUS)

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@$(RM) $(OBJS)

clean_bonus:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@$(MAKE) clean -C $(MLX_PATH)
	@$(RM) $(BONUS_OBJS)
	@$(RM) $(NAME_BONUS)

fclean: clean clean_bonus
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@$(MAKE) clean -C $(MLX_PATH)
	@$(RM) $(NAME) $(OBJ_DIR)
	@$(RM) $(NAME_BONUS) $(OBJ_DIR)

re: fclean all

valgrind:
	valgrind --leak-check=full -s --show-leak-kinds=all ./$(NAME) $(ARG)

download:
	@wget https://cdn.intra.42.fr/document/document/25858/minilibx-linux.tgz
	@tar -xzf minilibx-linux.tgz -C lib
	@rm minilibx-linux.tgz