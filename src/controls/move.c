/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:17:26 by maugusto          #+#    #+#             */
/*   Updated: 2024/11/26 11:30:16 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file move.c
 * @brief Movement functions
 */

#include "cub3d.h"

/**
 * @brief Move the player up
 * @param game Struct with game information
 * @param next_x Next x position
 * @param next_y Next y position
 * @return int 1 if the player moved, 0 otherwise
*/
int	move_up(t_game *game, double next_x, double next_y)
{
	int	move;

	move = 0;
	if (game->map[(int)(game->player.y + next_y)][(int)game->player.x] != '1')
	{
		game->player.y += next_y;
		move = 1;
	}
	if (game->map[(int)game->player.y][(int)(game->player.x + next_x)] != '1')
	{
		game->player.x += next_x;
		move = 1;
	}
	return (move);
}

/**
 * @brief Move the player down
 * @param game Struct with game information
 * @param next_x Next x position
 * @param next_y Next y position
 * @return int 1 if the player moved, 0 otherwise
*/
int	move_down(t_game *game, double next_x, double next_y)
{
	int	move;

	move = 0;
	if (game->map[(int)(game->player.y - next_y)][(int)game->player.x] != '1')
	{
		game->player.y -= next_y;
		move = 1;
	}
	if (game->map[(int)game->player.y][(int)(game->player.x - next_x)] != '1')
	{
		game->player.x -= next_x;
		move = 1;
	}
	return (move);
}

/**
 * @brief Move the player to the right
 * @param game Struct with game information
 * @param next_x Next x position
 * @param next_y Next y position
 * @return int Move 1 if the player moved, 0 otherwise
*/
int	move_right(t_game *game, double next_x, double next_y)
{
	int	move;

	move = 0;
	if (game->map[(int)(game->player.y + next_y)][(int)game->player.x] != '1')
	{
		game->player.y += next_y;
		move = 1;
	}
	if (game->map[(int)game->player.y][(int)(game->player.x + next_x)] != '1')
	{
		game->player.x += next_x;
		move = 1;
	}
	return (move);
}

/**
 * @brief Move the player to the left
 * @param game Struct with game information
 * @param next_x Next x position
 * @param next_y Next y position
 * @return int 1 if the player moved, 0 otherwise
*/
int	move_left(t_game *game, double next_x, double next_y)
{
	int	move;

	move = 0;
	if (game->map[(int)(game->player.y - next_y)][(int)game->player.x] != '1')
	{
		game->player.y -= next_y;
		move = 1;
	}
	if (game->map[(int)game->player.y][(int)(game->player.x - next_x)] != '1')
	{
		game->player.x -= next_x;
		move = 1;
	}
	return (move);
}

/**@} */