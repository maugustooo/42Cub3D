/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:38:09 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/26 10:39:39 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file init.c
 * @brief Initializes the mlx images and the player status
*/

#include "cub3d.h"

/**
 * @brief Completes the player status
 * 
 * @param game Struct with all game information
*/
void	init_status2(t_game *game)
{
	if (game->player.angle == EAST)
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->plane_x = 0.1;
		game->plane_y = 0.8;
	}
	if (game->player.angle == WEST)
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->plane_x = 0.1;
		game->plane_y = -0.8;
	}
}

/**
 * @brief Initializes the player status
 * 
 * @param game Struct with all game information
*/
void	init_status(t_game *game)
{
	if (game->player.angle == NORTH)
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->plane_x = 0.8;
		game->plane_y = 0;
	}
	if (game->player.angle == SOUTH)
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->plane_x = -0.8;
		game->plane_y = 0;
	}
	init_status2(game);
}

/**
 * @brief Function to return the file path
 * 
 * @param i Index of the file
 * @param game Struct with all game information
 * @return char* The file path
*/
char	*files(int i, t_game *game)
{
	char	*strings[4];

	strings[0] = game->textr.south;
	strings[1] = game->textr.north;
	strings[2] = game->textr.east;
	strings[3] = game->textr.west;
	return (strings[i]);
}

/**
 * @brief Initializes the mlx images
 * 
 * @param game Struct with all game information
*/
void	init_img(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->img[i].mlx_img = mlx_xpm_file_to_image(game->mlx_ptr,
				files(i, game), &game->img[i].width, &game->img[i].height);
		i++;
	}
	game->img[4].mlx_img = mlx_new_image(game->mlx_ptr,
			game->screen_width, game->screen_height);
	i = 0;
	while (i < 5)
	{
		game->img[i].addr = mlx_get_data_addr(game->img[i].mlx_img,
				&game->img[i].bpp, &game->img[i].line_len,
				&game->img[i].endian);
		if (!game->img[i].addr)
			sepuku(game, ERROR_MLX);
		i++;
	}
	init_status(game);
}

/**@} */