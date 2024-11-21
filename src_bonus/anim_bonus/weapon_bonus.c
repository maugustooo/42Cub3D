/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:21:23 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/21 12:30:19 by gude-jes         ###   ########.fr       */
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

    delta_time = curr_time - timer->last_time;
    timer->elapsed_time += delta_time;

    if (game->weapon.is_attacking)
    {
        if (timer->elapsed_time >= WEAPON_FRAME_DURATION)
        {
            game->weapon.curr_frame = (game->weapon.curr_frame + 1) % WEAPON_NUM_FRAME;
            timer->elapsed_time = 0;
        }
    }
    else
        game->weapon.curr_frame = 0;

    timer->last_time = curr_time;
}

void render_weapon(t_game *game)
{
    double scale_factor_width = 4.0; // Adjust the width scale factor as needed
    double scale_factor_height = 3.0; // Adjust the height scale factor as needed
    game->weapon.curr_frame = 0;
    game->weapon.frame_height = 93;
    game->weapon.frame_width = 511;
    game->weapon.frame_width = game->weapon.frame_width / WEAPON_NUM_FRAME;

    int scaled_width = (int)(game->weapon.frame_width * scale_factor_width);
    int scaled_height = (int)(game->weapon.frame_height * scale_factor_height);

    int frame_x = game->weapon.curr_frame * game->weapon.frame_width;
    int frame_y = 0;

    for (int y = (SCREEN_HEIGHT - scaled_height) + 21; y < SCREEN_HEIGHT; y++)
    {
        for (int x = (SCREEN_WIDTH / 2 - scaled_width / 2) + 12; x < SCREEN_WIDTH / 2 + scaled_width / 2; x++)
        {
            int tex_x = (int)((x - (SCREEN_WIDTH / 2 - scaled_width / 2)) / scale_factor_width);
            int tex_y = (int)((y - (SCREEN_HEIGHT - scaled_height)) / scale_factor_height);
            int color = get_color_weapon(game, frame_x + tex_x - 3, frame_y + tex_y - 2);
            if (color != 0x00FF12) // Check for transparency
                put_pixel(game, x, y, color);
        }
    }
}