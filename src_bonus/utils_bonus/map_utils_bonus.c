/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:50:13 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/05 12:35:28 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file map_utils_bonus.c
 * @brief Map utilities functions
*/

#include "cub3d_bonus.h"

/**
 * @brief Free the map
 * 
 * @param map Map Array
*/
void	free_map(bool **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

/**
 * @brief Get the width of the map
 * 
 * @param game Pointer to the game structure
*/
void	get_map_width(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			count++;
		if ((count - 1) > game->widthmap)
			game->widthmap = count - 1;
		count = 0;
	}
}

/**
 * @brief Continuation of the check of the doors
 * 
 * @param game Pointer to the game structure
 * @param map Map Array
 * @param i Index i
 * @param j Index j
*/
void	check_doors2(t_game *game, bool **map, int i, int j)
{
	if (game->map[i][j + 1] == '1' && game->map[i][j - 1] == '1')
	{
		if (game->map[i + 1][j] == '1' || game->map[i - 1][j] == '1')
		{
			free_map(map);
			sepuku(game, ERROR_MAP);
		}
	}
	if (game->map[i + 1][j] == '1' && game->map[i - 1][j] == '1')
	{
		if (game->map[i][j + 1] == '1' || game->map[i][j - 1] == '1')
		{
			free_map(map);
			sepuku(game, ERROR_MAP);
		}
	}
}

/**
 * @brief Check if the doors are correctly placed
 * 
 * @param game Game structure
 * @param map Map structure
 */
void	check_doors(t_game *game, bool **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->heightmap)
	{
		j = -1;
		while (++j < (int)ft_strlen(game->map[i]))
		{
			if (game->map[i][j] == 'D')
				check_doors2(game, map, i, j);
		}
	}
}

/**@} */