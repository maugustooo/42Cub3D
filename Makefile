# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 09:44:12 by gude-jes          #+#    #+#              #
#    Updated: 2024/11/20 10:48:50 by gude-jes         ###   ########.fr        #
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
UTILS		= file_utils init sepuku colors read_textures_utils render_utils map_utils
CONTROLS	= controls keys move
RENDER 		= render raycasting draw

GENERAL_BONUS	= main_bonus
PARSE_BONUS		= parse_bonus map_validation_bonus read_map_bonus read_textures_bonus file_content_bonus map_content_bonus
UTILS_BONUS		= file_utils_bonus file_utils2_bonus init_bonus init2_bonus sepuku_bonus colors_bonus read_textures_utils_bonus render_utils_bonus map_utils_bonus
CONTROLS_BONUS	= controls_bonus keys_bonus move_bonus
RENDER_BONUS 	= render_bonus raycasting_bonus draw_bonus minimap_bonus enemy_bonus fps_bonus player_face_bonus
ANIM_BONUS		= enem_frame

ARG			= maps/good/game.cub

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

VPATH = src \
        src/parse \
        src/utils \
        src/controls \
        src/render \
        src_bonus \
        src_bonus/parse_bonus \
        src_bonus/utils_bonus \
        src_bonus/controls_bonus \
        src_bonus/render_bonus \
		src_bonus/anim_bonus

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

BONUS_SRC	= $(addsuffix .c, $(GENERAL_BONUS))\
				$(addsuffix .c, $(PARSE_BONUS))\
				$(addsuffix .c, $(UTILS_BONUS))\
				$(addsuffix .c, $(CONTROLS_BONUS))\
				$(addsuffix .c, $(RENDER_BONUS))\
				$(addsuffix .c, $(ANIM_BONUS))\


OBJ_DIR		= obj

OBJS		= $(SRC:%.c=$(OBJ_DIR)/%.o)

BONUS_OBJS	= $(BONUS_SRC:%.c=$(OBJ_DIR)/%.o)

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#
all: deps $(NAME_BONUS)

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