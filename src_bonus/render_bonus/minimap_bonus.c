/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:14:47 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/27 14:40:08 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_minimap_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			put_pixel_minimap(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_player_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			put_pixel_minimap(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	render_player_on_minimap(t_game *game)
{
	int	player_x;
	int	player_y;
	int	color;

	player_x = (int)game->player.x * 10;
	player_y = (int)game->player.y * 10;
	color = 0x00CC00;
	draw_minimap_square(game, player_x, player_y, color);
}

void	render_minimap2(t_game *game, int x, int y)
{
	int i;

	i = 0;
	if (game->map[y][x] == '1')
		draw_minimap_square(game, x * 10, y * 10, 0x000000);
	else if (game->map[y][x] == 'D')
		draw_minimap_square(game, x * 10, y * 10, 0xFFCC00);
	else if (game->map[y][x] != '1' || game->map[y][x] != 'D'
		|| game->map[y][x] != 'X')
		draw_minimap_square(game, x * 10, y * 10, 0xFFFFFF);
	while (i < game->enemy_count)
	{
		if (game->enemy[i].died)
			draw_minimap_square(game, game->enemy[i].x * 10, game->enemy[i].y * 10, 0xFFFFFF);
		else
			draw_minimap_square(game, game->enemy[i].x * 10, game->enemy[i].y * 10, 0xFF0000);
		i++;	
	}
}

void	render_minimap(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (++x < game->widthmap)
	{
		y = -1;
		while (++y < game->heightmap)
			render_minimap2(game, x, y);
	}
	render_player_on_minimap(game);
	render_fps(game);
}
