/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:50:00 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/11 11:58:32 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	flood_fill(bool **map, t_game *game, int x, int y)
{
	bool	map_closed;

	if (x < 0 || y < 0 || y >= game->heightmap || x >= (int)ft_strlen(game->map[y]))
		return (false);
	if(game->map[y][x] == '1' || map[y][x] == true)
		return (true);
	map[y][x] = true;
	map_closed = true;
	map_closed &= flood_fill(map, game, x + 1, y);
	map_closed &= flood_fill(map, game, x, y + 1);
	map_closed &= flood_fill(map, game, x - 1, y);
	map_closed &= flood_fill(map, game, x, y - 1);
	return (map_closed);
}

bool	check_map_extremities(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++x < ft_strclen(game->map[0], '\n'))
	{
		if (game->map[0][x] != '1' && game->map[0][x] != ' ')
			return (false);
		if (game->map[game->heightmap -1][x] != '1'
			&& game->map[game->heightmap -1][x] != ' ')
			return (false);
	}
	while(++y < game->heightmap)
	{
		if (game->map[y][0] != '1' && game->map[y][0] != ' ')
			return (false);
		if (game->map[y][ft_strclen(game->map[y], '\n')-1] != '1'
			&& game->map[y][ft_strclen(game->map[y], '\n') -1] != ' ')
			return (false);
	}
	return (true);
}

void	map_content_validation(t_game *game)
{
	bool	**map;
	bool	map_closed;
	int		i;

	map = ft_calloc(((game->mapend) + 1), sizeof(char *));
	if(!map)
		sepuku(game, ERROR_MALLOC);
	i = -1;
	while(++i < game->mapend)
		map[i] = ft_calloc(ft_strclen(game->map[i], '\n'), sizeof(char));
	map_closed = check_map_extremities(game);
	if(!map_closed)
		sepuku(game, ERROR_MAP);	
	map_closed = flood_fill(map, game, game->player.x, game->player.y);
	if(!map_closed)
		sepuku(game, ERROR_MAP);
}
