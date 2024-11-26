/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:50:13 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/26 09:36:49 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_map(bool **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

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
