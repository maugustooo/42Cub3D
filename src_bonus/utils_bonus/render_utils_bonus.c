/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:41:30 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/29 14:48:19 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > SCREEN_HEIGHT - 1 || x < 0
		|| x > SCREEN_WIDTH - 1)
		return ;
	pixel = (game->img[6].addr + (y * game->img[6].line_len
				+ x * (game->img[6].bpp / 8)));
	*(int *)pixel = color;
}

void	put_pixel_minimap(t_game *game, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	pixel = (game->minimap.addr + (y * game->minimap.line_len
				+ x * (game->minimap.bpp / 8)));
	*(int *)pixel = color;
}

void	put_pixel_minimap_death(t_game *game, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	pixel = (game->minimap.addr + (y * game->minimap.line_len
				+ x * (game->minimap.bpp / 8)));
	if (*(int *)pixel == 0)
		return ;
	*(int *)pixel = color;
}

void	draw_minimap_square_death(t_game *game, int x, int y, int color)
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
			put_pixel_minimap_death(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}
