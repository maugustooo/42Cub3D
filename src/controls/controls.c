/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:18:40 by maugusto          #+#    #+#             */
/*   Updated: 2024/11/14 10:59:00 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(angle)
		- game->player.dir_y * sin(angle);
	game->player.dir_y = old_dir_x * sin(angle)
		+ game->player.dir_y * cos(angle);
	old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(angle) - game->plane_y * sin(angle);
	game->plane_y = old_plane_x * sin(angle) + game->plane_y * cos(angle);
}

int	controls(t_game *game)
{
	int	moved;

	moved = 0;
	if (game->player.move_up == 1)
		move_up(game, game->player.dir_x * SPEED, game->player.dir_y
			* SPEED);
	if (game->player.move_down == 1)
		move_down(game, game->player.dir_x * SPEED, game->player.dir_y * SPEED);
	if (game->player.move_right == 1)
		move_right(game, game->plane_x * SPEED, game->plane_y * SPEED);
	if (game->player.move_left == 1)
		move_left(game, game->plane_x * SPEED, game->plane_y * SPEED);
	if (game->player.rotate_right == 1)
		rotate(game, ROTSPEED);
	if (game->player.rotate_left == 1)
		rotate(game, -ROTSPEED);
	return (0);
}
