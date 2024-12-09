/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:18:40 by maugusto          #+#    #+#             */
/*   Updated: 2024/12/05 11:30:16 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @file controls_bonus.c
 * @brief Functions to control the player movement and rotation 
*/

#include "cub3d_bonus.h"

/**
 * @brief Rotate the player
 * 
 * @param game Pointer to the game struct
 * @param angle Angle to rotate
*/
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

/**
 * @brief Controls functions
 * 
 * @param game Pointer to the game struct
 * @param next_x Next position in the x axis
 * @param next_y Next position in the y axis
 * @return int 0 if the player moved, 1 otherwise
 */
int	controls(t_game *game)
{
	int	moved;

	moved = 0;
	if (game->player.move_up == 1)
		moved = move_up(game, game->player.dir_x * SPEED, game->player.dir_y
				* SPEED);
	if (game->player.move_down == 1)
		moved = move_down(game, game->player.dir_x * SPEED,
				game->player.dir_y * SPEED);
	if (game->player.move_right == 1)
		moved = move_right(game, game->plane_x * SPEED, game->plane_y * SPEED);
	if (game->player.move_left == 1)
		moved = move_left(game, game->plane_x * SPEED, game->plane_y * SPEED);
	if (game->player.rotate_right == 1)
		rotate(game, ROTSPEED);
	if (game->player.rotate_left == 1)
		rotate(game, -ROTSPEED);
	if (moved)
		return (0);
	return (0);
}

/**@} */