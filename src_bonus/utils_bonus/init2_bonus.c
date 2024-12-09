/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:25:02 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/05 12:06:46 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file init2_bonus.c
 * @brief Continue the initialization of the game structure.
*/

#include "cub3d_bonus.h"

/**
 * @brief Initialize the door structure.
 * 
 * @param game Pointer to the game structure.
 */
void	init_door(t_game *game)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'D')
			{
				game->door[count].x = j + 0.5;
				game->door[count++].y = i + 0.5;
			}
		}
	}
	game->door_count = count;
}

/**
 * @brief Continue the initialization of the enemy structure.
 * 
 * @param game Pointer to the game structure.
*/
void	init_enemy2(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy_count)
	{
		game->enemy[i].frame_width = 66;
		game->enemy[i].frame_height = 64;
		game->enemy[i].curr_frame = 0;
		i++;
	}
}

/**
 * @brief Initialize the enemy structure.
 * 
 * @param game Pointer to the game structure.
 */
void	init_enemy(t_game *game)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'X')
			{
				game->enemy[count].x = j + 0.5;
				game->enemy[count].y = i + 0.5;
				game->enemy[count].health = 1;
				game->enemy[count++].state = 0;
			}
		}
	}
	game->enemy_count = count;
	init_enemy2(game);
}

/**
 * @brief Initialize the raycasting variables.
 * 
 * @param game Pointer to the game structure.
 * @param x The x coordinate of the screen.
 */
void	init_raycasting(t_game *game, int x)
{
	game->map_x = (int)game->player.x;
	game->map_y = (int)game->player.y;
	game->cam_x = (2 * x) / (double)SCREEN_WIDTH - 1;
	game->ray_dir_x = game->player.dir_x + game->plane_x * game->cam_x;
	game->ray_dir_y = game->player.dir_y + game->plane_y * game->cam_x;
}

/**
 * @brief Initialize the minimap image.
 * 
 * @param game Pointer to the game structure.
 */
void	init_minimap(t_game *game)
{
	game->minimap.mlx_img = mlx_new_image(game->mlx_ptr,
			game->widthmap * 10, game->heightmap * 10);
	if (!game->minimap.mlx_img)
		sepuku(game, ERROR_MLX);
	game->minimap.addr = mlx_get_data_addr(game->minimap.mlx_img,
			&game->minimap.bpp, &game->minimap.line_len, &game->minimap.endian);
	if (!game->minimap.addr)
		sepuku(game, ERROR_MLX);
	game->fps_img.mlx_img = mlx_new_image(game->mlx_ptr,
			64, 13);
	if (!game->fps_img.mlx_img)
		sepuku(game, ERROR_MLX);
	game->fps_img.addr = mlx_get_data_addr(game->fps_img.mlx_img,
			&game->fps_img.bpp, &game->fps_img.line_len, &game->fps_img.endian);
	if (!game->fps_img.addr)
		sepuku(game, ERROR_MLX);
}

/**@} */