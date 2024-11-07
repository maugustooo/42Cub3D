/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:50:00 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/07 09:27:02 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flood_fill(char **map, t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= ft_strlen(game->map[y]) || y >= game->heightmap)
		sepuku(game, ERROR_MAP);
	if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == ' ')
		return ;
	if (map[y][x] == '0')
	{
		map[y][x] = 'F';
		flood_fill(map, game, x + 1, y);
		flood_fill(map, game, x - 1, y);
		flood_fill(map, game, x, y + 1);
		flood_fill(map, game, x, y - 1);
	}
}

void	map_content_validation(t_game *game)
{
	char **map;
	int i;

	map = ft_calloc((game->mapend - game->mapstart + 1), sizeof(char *));
	if(!map)
		sepuku(game, ERROR_MALLOC);
	i = game->mapstart;
	while(i < game->mapend)
	{
		map[i - game->mapstart] = ft_strdup(game->map[i]);
		if(!map[i - game->mapstart])
			sepuku(game, ERROR_MALLOC);
		i++;
	}
}
