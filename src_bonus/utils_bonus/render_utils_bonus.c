/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:41:30 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/25 12:42:12 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_color(t_game *game, int x, int y, int i)
{
	return (*(int *)(game->img[i].addr
		+ (y * game->img[i].line_len + x * (game->img[i].bpp / 8))));
}

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

suseconds_t	ft_get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void	init_weapon(t_game *game)
{
	game->weapon.scale_factor_width = 4.0;
	game->weapon.scale_factor_height = 3.0;
	game->weapon.frame_height = 93;
	game->weapon.frame_width = 511;
	game->weapon.frame_width = game->weapon.frame_width / WEAPON_NUM_FRAME;
	game->weapon.scaled_width = (int)(game->weapon.frame_width
			* game->weapon.scale_factor_width);
	game->weapon.scaled_height = (int)(game->weapon.frame_height
			* game->weapon.scale_factor_height);
}
