/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:13:57 by maugusto          #+#    #+#             */
/*   Updated: 2024/11/21 13:04:25 by maugusto         ###   ########.fr       */
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
	double fog = 0.25;
	int fog_color = 200;
	
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT - 1)
		{
			if (y <= (SCREEN_HEIGHT / 2) - 1)
				put_pixel(game, x, y, create_rgb(0, (1- fog) * game->rgb_sky[0] + fog * fog_color,
						(1- fog) * game->rgb_sky[1] + fog * fog_color,
						(1- fog) * game->rgb_sky[2] + fog * fog_color));
			else
				put_pixel(game, x, y, create_rgb(0, (1-fog) * game->rgb_floor[0] + fog * fog_color,
						(1-fog) * game->rgb_floor[1] + fog * fog_color,
						(1-fog) * game->rgb_floor[2] + fog * fog_color));
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
	int door_state = game->door_state_map[game->map_y][game->map_x];
	if (game->door && (door_state == 1 || door_state == 3))
	{
		update_door_timers(game, get_delta_time());
		draw_door(game, 1);
	}
	double curr_time = (double)ft_get_time();
	update_enemy_frame_mov(game, &game->timer, curr_time);
	update_weapon_frame(game, &game->timer, curr_time);
	game->z_buffer[game->x] = game->walldist;
	handle_enemy(game);
	update_fps(game);
	put_player_face(game);
	render_minimap(game);
	render_weapon(game);
	mlx_put_image_to_window(game->mlx_ptr, game->window, game->img[6].mlx_img,
		0, 0);
	mlx_put_image_to_window(game->mlx_ptr, game->window, game->player_face[4].mlx_img,
		SCREEN_WIDTH - 192, SCREEN_HEIGHT - 192);
	mlx_put_image_to_window(game->mlx_ptr, game->window, game->minimap.mlx_img,
		10, 10);
	mlx_put_image_to_window(game->mlx_ptr, game->window, game->fps_img.mlx_img,
		 game->widthmap * 10 + 12, 12);
	return (0);
}
