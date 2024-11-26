/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:50:00 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/26 10:58:15 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file map_content.c
 * @brief Check the map content.
 */

#include "cub3d.h"

/**
 * @brief Check if there are holes in the map.
 * @param game Struct with the game information.
 * @param map Map to check.
 */
void	check_holes(t_game *game, bool **map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->heightmap)
	{
		x = -1;
		while (++x < (int)ft_strlen(game->map[y]))
		{
			if (game->map[y][x] == '0')
			{
				if (game->map[y][x + 1] == ' ' || game->map[y][x - 1] == ' '
					|| game->map[y + 1][x] == ' ' || game->map[y - 1][x] == ' ')
				{
					free_map(map);
					sepuku(game, ERROR_MAP);
				}
			}
		}
	}
}

/**
 * @brief Flood fill algorithm to check if the map is closed.
 * @param map Map to check.
 * @param game Struct with the game information.
 * @param x X position.
 * @param y Y position.
 * @return true If the map is closed.
 * @return false If the map is not closed.
*/
bool	flood_fill(bool **map, t_game *game, int x, int y)
{
	bool	map_closed;

	if (x < 0 || y < 0 || y >= game->heightmap
		|| x >= (int)ft_strlen(game->map[y]))
		return (false);
	if (game->map[y][x] == '1' || map[y][x] == true)
		return (true);
	map[y][x] = true;
	map_closed = true;
	map_closed &= flood_fill(map, game, x + 1, y);
	map_closed &= flood_fill(map, game, x, y + 1);
	map_closed &= flood_fill(map, game, x - 1, y);
	map_closed &= flood_fill(map, game, x, y - 1);
	return (map_closed);
}

/**
 * @brief Continuation of checking map extremities.
 * @param game Struct with the game information.
 * @return true If the map is closed.
 * @return false If the map is not closed.
*/
bool	check_map_extremities2(t_game *game)
{
	int	y;

	y = -1;
	while (++y < game->heightmap)
	{
		if (game->map[y][0] != '1' && game->map[y][0] != ' ')
			return (false);
		if (game->map[y][ft_strclen(game->map[y], '\n') - 1] != '1'
			&& game->map[y][ft_strclen(game->map[y], '\n') - 1] != ' ')
			return (false);
	}
	return (true);
}

/**
 * @brief Check the map extremities.
 * 
 * @param game Struct with the game information.
 * @return true If the map is closed.
 * @return false If the map is not closed.
*/
bool	check_map_extremities(t_game *game)
{
	int	x;

	x = -1;
	while (++x < ft_strclen(game->map[0], '\n'))
	{
		if (game->map[0][x] != '1' && game->map[0][x] != ' ')
			return (false);
	}
	x = -1;
	while (++x < ft_strclen(game->map[game->heightmap -1], '\n'))
	{
		if (game->map[game->heightmap -1][x] != '1'
			&& game->map[game->heightmap -1][x] != ' ')
			return (false);
	}
	return (check_map_extremities2(game));
}

/**
 * @brief Map content validation.
 * @param game Struct with the game information.
*/
void	map_content_validation(t_game *game)
{
	bool	**map;
	bool	map_closed;
	int		i;

	map = ft_calloc(((game->mapend) + 1), sizeof(char *));
	if (!map)
		sepuku(game, ERROR_MALLOC);
	i = -1;
	while (++i < game->mapend)
		map[i] = ft_calloc(ft_strclen(game->map[i], '\n'), sizeof(char));
	map_closed = check_map_extremities(game);
	if (!map_closed)
	{
		free_map(map);
		sepuku(game, ERROR_MAP);
	}
	check_holes(game, map);
	map_closed = flood_fill(map, game, game->player.x, game->player.y);
	if (!map_closed)
	{
		free_map(map);
		sepuku(game, ERROR_MAP);
	}
	free_map(map);
}

/**@} */