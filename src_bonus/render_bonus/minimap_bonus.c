/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:14:47 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/26 09:14:47 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_minimap_square(t_game *game, int x, int y, int color)
{
	int i;
	int j;

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

void draw_player_square(t_game *game, int x, int y, int color)
{
	int i;
	int j;

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
	int player_x;
	int player_y;
	int color;

	player_x = (int)game->player.x * 10;
	player_y = (int)game->player.y * 10;
	color = 0x00CC00;
	draw_minimap_square(game, player_x, player_y, color);
}

int check_enemy(t_game *game, int x, int y)
{
	int i;

	i = 0;
	while (i < game->enemy_count)
	{
		if ((int)game->enemy[i].x == x && (int)game->enemy[i].y == y && game->enemy[i].died)
			return (1);
		i++;
	}
	return (0);
}

void	render_minimap(t_game *game)
{
	int x;
	int y;

	x = -1;
	while (++x < game->widthmap)
	{
		y = -1;
		while (++y < game->heightmap)
		{
			if (game->map[y][x] == '1')
				draw_minimap_square(game, x * 10, y * 10, 0x000000);
			else if (game->map[y][x] == 'D')
				draw_minimap_square(game, x * 10, y * 10, 0xFFCC00);
			else if (game->map[y][x] == 'X')
			{
				if(check_enemy(game, x, y))
					draw_minimap_square(game, x * 10, y * 10, 0xFFFFFF);
				else
					draw_minimap_square(game, x * 10, y * 10, 0xFF0000);
			}
			else if (game->map[y][x] != '1' || game->map[y][x] != 'D' || game->map[y][x] != 'X')
				draw_minimap_square(game, x * 10, y * 10, 0xFFFFFF);
		}
	}
	render_player_on_minimap(game);
	render_fps(game);
}
