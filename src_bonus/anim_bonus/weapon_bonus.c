/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:21:23 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/25 12:40:36 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_color_weapon(t_game *game, int x, int y)
{
	return (*(int *)(game->weapon_img.addr
		+ (y * game->weapon_img.line_len + x * (game->weapon_img.bpp / 8))));
}

void	update_weapon_frame(t_game *game, t_timer *timer, double curr_time)
{
	double		delta_time;
	static int	flag = 0;

	delta_time = curr_time - timer->weapon_last_time;
	delta_time /= 3000;
	timer->weapon_elapsed_time += delta_time;
	if (game->player.attack || flag)
	{
		if (timer->weapon_elapsed_time >= WEAPON_FRAME_DURATION)
		{
			game->weapon.curr_frame = (game->weapon.curr_frame + 1)
				% WEAPON_NUM_FRAME;
			timer->weapon_elapsed_time = 0;
			if (game->weapon.curr_frame == 2)
			{
				game->player.attack = false;
				flag = 1;
			}
			else
				flag = 0;
		}
	}
	else
		game->weapon.curr_frame = 0;
	timer->weapon_last_time = curr_time;
}

void	render_weapon2(t_game *game, int x, int y, int frame_x)
{
	int	color;
	int	tex_x;
	int	tex_y;

	color = 0;
	tex_x = (int)((x - (SCREEN_WIDTH / 2 - game->weapon.scaled_width / 2))
			/ game->weapon.scale_factor_width);
	tex_y = (int)((y - (SCREEN_HEIGHT - game->weapon.scaled_height))
			/ game->weapon.scale_factor_height);
	color = get_color_weapon(game, frame_x + tex_x - 3, 0 + tex_y - 2);
	if (color != 0x00FF12 && color != 0x8080)
		put_pixel(game, x, y, color);
}

void	render_weapon(t_game *game)
{
	int	frame_x;
	int	y;
	int	x;

	init_weapon(game);
	frame_x = game->weapon.curr_frame * game->weapon.frame_width;
	y = (SCREEN_HEIGHT - game->weapon.scaled_height) + 21;
	while (y < SCREEN_HEIGHT)
	{
		x = (SCREEN_WIDTH / 2 - game->weapon.scaled_width / 2) + 12;
		while (x < SCREEN_WIDTH / 2 + game->weapon.scaled_width / 2)
		{
			render_weapon2(game, x, y, frame_x);
			x++;
		}
		y++;
	}
}
