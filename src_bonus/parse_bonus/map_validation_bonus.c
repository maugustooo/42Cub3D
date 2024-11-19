/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:29:59 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/19 12:05:18 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_colors(t_game *game)
{
	if (!game->textr.ceiling || !game->textr.floor)
		sepuku(game, ERROR_COLOR);
	check_rgb(game->textr.ceiling, game, 1);
	check_rgb(game->textr.floor, game, 0);
}

void	check_textures(t_game *game)
{
	if (!game->textr.north || !game->textr.south
		|| !game->textr.east || !game->textr.west)
		sepuku(game, ERROR_TEXTURE);
	check_file(game->textr.north, game);
	check_file(game->textr.south, game);
	check_file(game->textr.east, game);
	check_file(game->textr.west, game);
	check_file(game->textr.door, game);
	check_file(game->textr.enemy1, game);
	check_file(game->textr.enemy2, game);
	check_file(game->textr.enemyd1, game);
	check_file(game->textr.enemyd2, game);
	check_duplicate_text(game);
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
	while (game->map[++i])
	{
		j = 0;
		while (game->map[i][j++])
		{
			while (ft_is_wspace(game->map[i][j]))
				j++;
			if (ft_strchr_nn("NSEW", game->map[i][j]))
			{
				game->player.x = j + 0.5;
				game->player.y = i + 0.5;
				player_direction(game->map[i][j], game);
				player_count++;
			}
		}
	}
	if (player_count != 1)
		sepuku(game, ERROR_MAP);
}

void	check_map_content(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = 0;
		while (game->map[i][j++])
		{
			while (ft_is_wspace(game->map[i][j]))
				j++;
			if (!(ft_strchr("10NSEWDX", game->map[i][j])))
				sepuku(game, ERROR_MAP);
		}
	}
	define_coords(game);
}
