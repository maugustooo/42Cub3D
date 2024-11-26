/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:16:44 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/26 10:40:30 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @file map_utils.c
 * @brief Utils functions for map parsing and handling.
*/

#include "cub3d.h"

/**
 * @brief Free the map allocated memory.
 * @param map Map to be freed.
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
 * @brief Get the map width object
 * @param game Struct with game information.
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

/**@} */