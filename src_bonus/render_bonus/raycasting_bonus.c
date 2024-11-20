/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:12:27 by maugusto          #+#    #+#             */
/*   Updated: 2024/11/20 11:29:53 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	wall_stuff(t_game *game)
{
	int	wall;

	wall = 0;
	game->door = false;
	game->is_enemy = false;
	while (wall == 0)
	{
		game->wall = false;
		if (game->side_dist_x < game->side_dist_y)
		{
			game->side_dist_x += game->delta_dist_x;
			game->map_x += game->step_x;
			game->wall_side = 0;
		}
		else
		{
			game->side_dist_y += game->delta_dist_y;
			game->map_y += game->step_y;
			game->wall_side = 1;
		}
		if (game->map[game->map_y][game->map_x] == '1')
		{
			game->wall = true;
			wall = 1;
		}
		if(game->map[game->map_y][game->map_x] == 'D')
		{
			wall = 1;
			game->door = true;
		}
		// if (game->map[game->map_y][game->map_x] == 'X')
		// {
		// 	wall = 1;
		// }
	}
}

void	get_step(t_game *game)
{
	if (game->ray_dir_x < 0)
	{
		game->step_x = -1;
		game->side_dist_x = (game->player.x - game->map_x) * game->delta_dist_x;
	}
	else
	{
		game->step_x = 1;
		game->side_dist_x = (game->map_x + 1.0 - game->player.x)
			* game->delta_dist_x;
	}
	if (game->ray_dir_y < 0)
	{
		game->step_y = -1;
		game->side_dist_y = (game->player.y - game->map_y)
			* game->delta_dist_y;
	}
	else
	{
		game->step_y = 1;
		game->side_dist_y = (game->map_y + 1.0 - game->player.y)
			* game->delta_dist_y;
	}
}

void	get_distance(t_game *game)
{
	if (game->ray_dir_x == 0)
		game->delta_dist_x = INT_MAX;
	else
		game->delta_dist_x = fabs(1 / game->ray_dir_x);
	if (game->ray_dir_y == 0)
		game->delta_dist_y = INT_MAX;
	else
		game->delta_dist_y = fabs(1 / game->ray_dir_y);
}

void	init_raycasting(t_game *game, int x)
{
	game->map_x = (int)game->player.x;
	game->map_y = (int)game->player.y;
	game->cam_x = (2 * x) / (double)SCREEN_WIDTH - 1;
	game->ray_dir_x = game->player.dir_x + game->plane_x * game->cam_x;
	game->ray_dir_y = game->player.dir_y + game->plane_y * game->cam_x;
}

void	raycasting(t_game *game)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_raycasting(game, x);
		get_distance(game);
		get_step(game);
		wall_stuff(game);
		if (game->wall_side == 0)
			game->walldist = (game->side_dist_x - game->delta_dist_x);
		else
			game->walldist = (game->side_dist_y - game->delta_dist_y);
		game->z_buffer[x] = game->walldist;
		draw_column(game, x);
		x++;
	}
}
