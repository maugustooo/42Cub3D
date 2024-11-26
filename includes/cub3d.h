/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:58:55 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/26 11:35:28 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file cub3d.h
 * @brief Project header file
*/

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <limits.h>

# define SPEED 0.1
# define ROTSPEED 0.05
# define MSPEED 0.03
# define FOV 90
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

/**
 * @brief Error codes
*/
typedef enum e_error
{
	ERROR_ARGS,
	ERROR_FILE,
	ERROR_MAP,
	ERROR_MALLOC,
	ERROR_COLOR,
	ERROR_TEXTURE,
	ERROR_MLX,
	ERROR_ORDER,
	ERROR_DUP,
}				t_error;

/**
 * @brief Struct for image data
 * @param mlx_img The mlx image pointer
 * @param addr The address of the image
 * @param bpp Bits per pixel
 * @param line_len Line length
 * @param endian Endian
 * @param width Image width
 * @param height Image height
*/
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}				t_img;

/**
 * @brief Struct for textures
 * @param north The north texture
 * @param east The east texture
 * @param south The south texture
 * @param west The west texture
 * @param floor The floor texture
 * @param ceiling The ceiling texture
*/
typedef struct s_textr
{
	char	*north;
	char	*east;
	char	*south;
	char	*west;
	char	*floor;
	char	*ceiling;
}				t_textr;

/**
 * @brief Struct for player data
 * @param x The player x position
 * @param y The player y position
 * @param angle The player angle
 * @param dir_x The player direction x
 * @param dir_y The player direction y
 * @param move_up The player move up flag
 * @param move_down The player move down flag
 * @param move_left The player move left flag
 * @param move_right The player move right flag
 * @param rotate_left The player rotate left flag
 * @param rotate_right The player rotate right flag
*/
typedef struct s_player
{
	double	x;
	double	y;
	int		angle;
	double	dir_x;
	double	dir_y;
	int		move_up;
	int		move_down;
	int		move_left;
	int		move_right;
	int		rotate_left;
	int		rotate_right;
}				t_player;

/**
 * @brief Struct for game data
 * @param map The map
 * @param x The x position
 * @param y The y position
 * @param tlines The total lines
 * @param mapstart The map start
 * @param mapend The map end
 * @param heightmap The map height
 * @param widthmap The map width
 * @param screen_width The screen width
 * @param screen_height The screen height
 * @param mlx_ptr The mlx pointer
 * @param window The window pointer
 * @param rgb The rgb values
 * @param mapflag The map flag
 * @param rgb_sky The sky color
 * @param rgb_floor The floor color
 * @param textr The textures
 * @param img The images
 * @param minimap The minimap image
 * @param player The player data
 * @param wall_end The wall end
 * @param wall_start The wall start
 * @param plane_x The plane x
 * @param plane_y The plane y
 * @param ray_dir_x The ray direction x
 * @param ray_dir_y The ray direction y
 * @param delta_dist_x The delta distance x
 * @param delta_dist_y The delta distance y
 * @param side_dist_x The side distance x
 * @param side_dist_y The side distance y
 * @param map_x The map x
 * @param map_y The map y
 * @param step_x The step x
 * @param step_y The step y
 * @param wall_side The wall side
 * @param walldist The wall distance
 * @param cam_x The camera x
 * @param wall_x The wall x
 * @param tex_x The texture x
 * @param tex_y The texture y
 * @param tex_pos The texture position
 * @param step The step
*/
typedef struct s_game
{
	char		**map;

	int			x;
	int			y;
	int			tlines;
	int			mapstart;
	int			mapend;	
	int			heightmap;
	int			widthmap;
	int			screen_width;
	int			screen_height;
	void		*mlx_ptr;
	void		*window;
	char		**rgb;
	bool		mapflag;

	int			rgb_sky[3];
	int			rgb_floor[3];
	t_textr		textr;
	t_img		img[5];
	t_img		minimap;
	t_player	player;

	int			wall_end;
	int			wall_start;
	double		plane_x;
	double		plane_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			wall_side;
	double		walldist;
	double		cam_x;

	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		tex_pos;
	double		step;
}				t_game;

void	parse(char **argv, t_game *game);
void	check_extension(char *file);
void	read_map(char *file, t_game *game);
void	check_textures(t_game *game);
void	check_map_content(t_game *game);
void	check_file(char *file, t_game *game);
void	check_duplicate_text(t_game *game);
void	read_textures(char *file, t_game *game);
char	*return_no_extra_spaces(char *tmp);
void	check_text_content(t_game *game, int *i);
void	check_rgb(char *color, t_game *game, int type);
void	check_colors(t_game *game);
void	check_order(char *file, t_game *game);
void	map_content_validation(t_game *game);
void	get_map_width(t_game *game);
int		sepuku(t_game *game, enum e_error i);
void	free_map(bool **map);
int		ft_exit(t_game *game);

int		controls(t_game *game);
void	init_img(t_game *game);

int		render(t_game *game);
void	raycasting(t_game *game);
void	draw_column(t_game *game, int x);

int		handle_key_release(int keycode, t_game *game);
int		handle_key_press(int keycode, t_game *game);

void	put_pixel(t_game *game, int x, int y, int color);
int		get_color(t_game *game, int x, int y, int i);

void	rotate(t_game *game, double angle);
int		move_left(t_game *game, double next_x, double next_y);
int		move_right(t_game *game, double next_x, double next_y);
int		move_down(t_game *game, double next_x, double next_y);
int		move_up(t_game *game, double next_x, double next_y);

#endif