/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:50:00 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/08 11:08:46 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	flood_fill(bool **map, t_game *game, int x, int y)
{
	bool	map_closed;

	if (x < 0 || y < 0 || x >= (int)ft_strlen(game->map[y]) || y >= game->heightmap)
		return (false);
	if(game->map[y][x] == '1' || map[y][x] == true)
		return (true);
	else
		map[y][x] = true;
	map_closed = true;
	map_closed &= flood_fill(map, game, x + 1, y);
	map_closed &= flood_fill(map, game, x - 1, y);
	map_closed &= flood_fill(map, game, x, y + 1);
	map_closed &= flood_fill(map, game, x, y - 1);
	return (map_closed);
}

void	map_content_validation(t_game *game)
{
	bool	**map;
	bool	map_closed;
	int		i;

	map = ft_calloc(((game->mapend - game->mapstart) + 1), sizeof(char *));
	if(!map)
		sepuku(game, ERROR_MALLOC);
	i = -1;
	while(++i < game->mapend)
		map[i] = ft_calloc((int)ft_strlen(game->map[i]), sizeof(char));
	map_closed = flood_fill(map, game, game->player.x, game->player.y);
	if(!map_closed)
		sepuku(game, ERROR_MAP);
}