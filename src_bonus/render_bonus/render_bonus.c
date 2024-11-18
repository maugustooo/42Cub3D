/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:13:57 by maugusto          #+#    #+#             */
/*   Updated: 2024/11/18 16:42:03 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	create_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	render_background(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT - 1)
		{
			if (y <= (SCREEN_HEIGHT / 2) - 1)
				put_pixel(game, x, y, create_rgb(0, game->rgb_sky[0],
						game->rgb_sky[1], game->rgb_sky[2]));
			else
				put_pixel(game, x, y, create_rgb(0, game->rgb_floor[0],
						game->rgb_floor[1], game->rgb_floor[2]));
			y++;
		}
		x++;
	}
}

int	render(t_game *game)
{
	controls(game);
	render_background(game);
	raycasting(game);
	handle_enemy(game);
	render_minimap(game);
	mlx_put_image_to_window(game->mlx_ptr, game->window, game->img[6].mlx_img,
		0, 0);
	mlx_put_image_to_window(game->mlx_ptr, game->window, game->minimap.mlx_img,
		10, 10);
	return (0);
}
