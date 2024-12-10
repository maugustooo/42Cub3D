/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:14:47 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/10 10:28:16 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file minimap_bonus.c
 * @brief 
*/

#include "cub3d_bonus.h"

/**
 * @brief Draw a square to the minimap.
 * @param game Pointer to the game structure.
 * @param x X position.
 * @param y Y position.
 * @param color Color of the square.
*/
void	draw_minimap_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		if ((color == 0xFF0000 && i >= 5) || (color == 0x00CC00 && i >= 5))
			break ;
		while (j < 10)
		{
			if ((color == 0xFF0000 && j >= 5) || (color == 0x00CC00 && j >= 5))
				break ;
			put_pixel_minimap(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

/**
 * @brief Render the player on the minimap.
 * @param game Pointer to the game structure.
*/
void	render_player_on_minimap(t_game *game)
{
	double	player_x;
	double	player_y;
	int		color;

	player_x = (game->player.x - 0.25) * 10;
	player_y = (game->player.y - 0.25) * 10;
	color = 0x00CC00;
	draw_minimap_square(game, player_x, player_y, color);
}

/**
 * @brief Continue rendering of minimap.
 * @param game Pointer to the game structure.
 * @param x X position.
 * @param y Y position.
 * @param color Color of the square.
*/
void	render_minimap2(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	if (game->map[y][x] == '1')
		draw_minimap_square(game, x * 10, y * 10, 0x000000);
	else if (game->map[y][x] == 'D' || game->map[y][x] == 'd')
		draw_minimap_square(game, x * 10, y * 10, 0xFFCC00);
	else if (game->map[y][x] != '1' || game->map[y][x] != 'D'
		|| game->map[y][x] != 'X' || game->map[y][x] != 'd')
		draw_minimap_square(game, x * 10, y * 10, 0xFFFFFF);
	while (i < game->enemy_count)
	{
		if (game->enemy[i].died)
			draw_minimap_square_death(game, game->enemy[i].x * 10,
				game->enemy[i].y * 10, 0xFFFFFF);
		else
			draw_minimap_square(game, game->enemy[i].x * 10,
				game->enemy[i].y * 10, 0xFF0000);
		i++;
	}
}

/**
 * @brief Render the minimap.
 * @param game Pointer to the game structure.
*/
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

/** @} */