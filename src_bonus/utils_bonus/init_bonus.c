/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:38:09 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/05 12:05:17 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file init_bonus.c
 * @brief Initialize the game status.
*/

#include "cub3d_bonus.h"

/**
 * @brief Continue initialization of the game status.
 * 
 * @param game Pointer to the game structure.
*/
void	init_status2(t_game *game)
{
	game->player.health = 4;
	if (game->player.angle == EAST)
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->plane_x = 0;
		game->plane_y = 0.66;
	}
	if (game->player.angle == WEST)
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->plane_x = 0;
		game->plane_y = -0.66;
	}
}

/**
 * @brief Initialize the game status.
 * 
 * @param game Pointer to the game structure.
*/
void	init_status(t_game *game)
{
	if (game->player.angle == NORTH)
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->plane_x = 0.66;
		game->plane_y = 0;
	}
	if (game->player.angle == SOUTH)
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->plane_x = -0.66;
		game->plane_y = 0;
	}
	game->player.health = 0;
	game->player.scared = 0;
	init_status2(game);
}

/**
 * @brief Initialize the door map.
 * 
 * @param game Pointer to the game structure.
*/
void	init_door_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->door_state_map = (int **)malloc(game->heightmap * sizeof(int *));
	if (!game->door_state_map)
		sepuku(game, ERROR_MALLOC);
	while (++i < game->heightmap)
	{
		j = 0;
		game->door_state_map[i] = (int *)malloc(game->widthmap * sizeof(int));
		if (!game->door_state_map[i])
			sepuku(game, ERROR_MALLOC);
		while (j < game->widthmap)
		{
			if (game->map[i][j] == 'D')
				game->door_state_map[i][j] = 0;
			else
				game->door_state_map[i][j] = 0;
			j++;
		}
	}
}

/**
 * @brief Initialize the images.
 * 
 * @param game Pointer to the game structure.
*/
void	init_img(t_game *game)
{
	int	i;

	i = 0;
	xpm_img(game);
	while (i < 7)
	{
		game->img[i].addr = mlx_get_data_addr(game->img[i].mlx_img,
				&game->img[i].bpp, &game->img[i].line_len,
				&game->img[i].endian);
		if (!game->img[i].addr)
			sepuku(game, ERROR_MLX);
		if (i < 5)
		{
			game->player_face[i].addr
				= mlx_get_data_addr(game->player_face[i].mlx_img,
					&game->player_face[i].bpp, &game->player_face[i].line_len,
					&game->player_face[i].endian);
			if (!game->player_face[i].addr)
				sepuku(game, ERROR_MLX);
		}
		i++;
	}
	game->weapon_img.addr = mlx_get_data_addr(game->weapon_img.mlx_img,
			&game->weapon_img.bpp, &game->weapon_img.line_len,
			&game->weapon_img.endian);
}

/**
 * @brief Initialize the game status.
 * 
 * @param game Pointer to the game structure.
*/
void	initializations(t_game *game)
{
	init_img(game);
	init_door_map(game);
	init_minimap(game);
	init_status(game);
	init_fog(game);
	init_bitmap(game);
}

/**@} */