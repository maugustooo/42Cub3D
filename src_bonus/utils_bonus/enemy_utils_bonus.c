/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:46:57 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/05 11:56:13 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @file enemy_utils_bonus.c
 * @brief Auxiliary functions to handle enemies
*/

#include "cub3d_bonus.h"

/**
 * @brief Check if the position is valid
 * 
 * @param game Pointer to the game structure
 * @param x X position
 * @param y Y position
 * @return true Position is valid
 * @return false Position is not valid
 */
bool	is_valid_position(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= game->widthmap || map_y < 0
		|| map_y >= game->heightmap)
	{
		return (false);
	}
	return (game->map[map_y][map_x] == '0' || game->map[map_y][map_x] == 'X'
		|| game->map[map_y][map_x] == 'd');
}

/**
 * @brief Check if the path is clear
 * 
 * @param game Pointer to the game structure
 * @param i Index of the enemy
 * @return true Path is clear
 * @return false Path is not clear
 */
bool	is_path_clear(t_game *game, int i)
{
	double	step;
	double	current_x;
	double	current_y;
	int		j;

	step = fmax(fabs(game->player.x - game->enemy[i].x),
			fabs(game->player.y - game->enemy[i].y));
	if (step == 0)
		return (true);
	current_x = game->enemy[i].x;
	current_y = game->enemy[i].y;
	j = -1;
	while (++j <= step)
	{
		if (!is_valid_position(game, current_x, current_y))
			return (false);
		current_x += ((game->player.x - game->enemy[i].x) / step) + 0.1;
		current_y += ((game->player.y - game->enemy[i].y) / step);
	}
	return (true);
}

/**@} */