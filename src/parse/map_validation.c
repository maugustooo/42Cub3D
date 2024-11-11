/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:29:59 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/11 09:36:41 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_colors(t_game *game, t_textr *textr)
{
	if(!textr->ceiling || !textr->floor)
		sepuku(game, ERROR_COLOR);
	check_rgb(textr->ceiling, game, 1);
	check_rgb(textr->floor, game, 0);	
}

void	check_textures(t_game *game, t_textr *textr)
{
	if(!textr->north || !textr->south || !textr->east || !textr->west)
		sepuku(game, ERROR_TEXTURE);
	check_file(textr->north, game);
	check_file(textr->south, game);
	check_file(textr->east, game);
	check_file(textr->west, game);
	check_duplicate_text(game, textr);
}

void	player_direction(char pos, t_game *game)
{
	if (pos == 'N')
		game->player.angle = NORTH;
	else if (pos == 'S')
		game->player.angle = SOUTH;
	else if (pos == 'E')
		game->player.angle = EAST;
	else if (pos == 'W')
		game->player.angle = WEST;
}

void	define_coords(t_game *game)
{
	int	i;
	int	j;
	int	player_count;

	i = -1;
	player_count = 0;
	while(game->map[++i])
	{
		j = 0;
		while(game->map[i][j++])
		{
			while(ft_is_wspace(game->map[i][j]))
				j++;
			if(ft_strchr_nn("NSEW", game->map[i][j]))
			{
				game->player.x = j;
				game->player.y = i;
				player_direction(game->map[i][j], game);
				player_count++;
			}
		}
	}
	if(player_count != 1)
		sepuku(game, ERROR_MAP);
}

void	check_map_content(t_game *game)
{
	int	i;
	int j;

	i = -1;
	while(game->map[++i])
	{
		j = 0;
		while(game->map[i][j++])
		{
			while(ft_is_wspace(game->map[i][j]))
				j++;
			if(!(ft_strchr("10NSEW", game->map[i][j])))
				sepuku(game, ERROR_MAP);
		}
	}
	define_coords(game);
}
