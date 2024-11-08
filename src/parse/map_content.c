/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:50:00 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/08 10:33:48 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flood_fill(char **map, t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= (int)ft_strlen(game->map[y]) || y >= game->heightmap)
		return ;
	if(map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if(map[y][x] == '0')
		map[y][x] = 'F';
	flood_fill(map, game, x + 1, y);
	flood_fill(map, game, x - 1, y);
	flood_fill(map, game, x, y + 1);
	flood_fill(map, game, x, y - 1);
}

void	check_map_validation(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while(map[i] && i < game->heightmap)
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == '0')
				sepuku(game, ERROR_MAP);
			j++;
		}
		i++;
	}
}

void	map_content_validation(t_game *game)
{
	char **map;
	int i;

	map = ft_calloc(((game->mapend - game->mapstart) + 1), sizeof(char *));
	if(!map)
		sepuku(game, ERROR_MALLOC);
	i = -1;
	while(++i < game->mapend)
		map[i] = ft_strdup(game->map[i]);
	flood_fill(map, game, game->player.x, game->player.y);
	check_map_validation(game, map);
}
