/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:21:23 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/21 14:30:35 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_color_weapon(t_game *game, int x, int y)
{
	return (*(int *)(game->weapon_img.addr
		+ (y * game->weapon_img.line_len + x * (game->weapon_img.bpp / 8))));
}

void update_weapon_frame(t_game *game, t_timer *timer, double curr_time)
{
    double delta_time;
	static int flag = 0;

	delta_time = curr_time - timer->weapon_last_time;
	delta_time /= 3000;
	timer->weapon_elapsed_time += delta_time;
    if (game->player.attack || flag)
    {
		if (timer->weapon_elapsed_time >= WEAPON_FRAME_DURATION)
        {
            game->weapon.curr_frame = (game->weapon.curr_frame + 1) % WEAPON_NUM_FRAME;
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

void render_weapon(t_game *game)
{
	int frame_x;
    int frame_y;
	int color;

	color =0;
	frame_y = 0;
    double scale_factor_width = 4.0; // Adjust the width scale factor as needed
    double scale_factor_height = 3.0; // Adjust the height scale factor as needed
    game->weapon.frame_height = 93;
    game->weapon.frame_width = 511;
    game->weapon.frame_width = game->weapon.frame_width / WEAPON_NUM_FRAME;
    int scaled_width = (int)(game->weapon.frame_width * scale_factor_width);
    int scaled_height = (int)(game->weapon.frame_height * scale_factor_height);
    frame_x = game->weapon.curr_frame * game->weapon.frame_width;
    for (int y = (SCREEN_HEIGHT - scaled_height) + 21; y < SCREEN_HEIGHT; y++)
    {
        for (int x = (SCREEN_WIDTH / 2 - scaled_width / 2) + 12; x < SCREEN_WIDTH / 2 + scaled_width / 2; x++)
        {
            int tex_x = (int)((x - (SCREEN_WIDTH / 2 - scaled_width / 2)) / scale_factor_width);
            int tex_y = (int)((y - (SCREEN_HEIGHT - scaled_height)) / scale_factor_height);
            color = get_color_weapon(game, frame_x + tex_x - 3, frame_y + tex_y - 2);
            if (color != 0x00FF12 && color != 0x8080)
                put_pixel(game, x, y, color);
        }
    }
}
