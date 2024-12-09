/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:17:26 by maugusto          #+#    #+#             */
/*   Updated: 2024/12/05 11:26:23 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @file move_bonus.c
 * @brief Movement functions
*/

#include "cub3d_bonus.h"

/**
 * @brief Wait for half a second
*/
void	wait_half_second(void)
{
	struct timeval	start;
	struct timeval	current;
	long			elapsed_time;

	gettimeofday(&start, NULL);
	elapsed_time = 0;
	while (elapsed_time < 50)
	{
		gettimeofday(&current, NULL);
		elapsed_time = (current.tv_sec - start.tv_sec)
			* 1000000 + (current.tv_usec - start.tv_usec);
	}
}

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
	if (game->map[(int)(game->player.y + next_y)][(int)game->player.x] != '1' &&
		(game->map[(int)(game->player.y + next_y)][(int)game->player.x] != 'D'
		|| game->door_state_map[(int)(game->player.y + next_y)]
			[(int)game->player.x] == 2))
	{
		game->player.y += next_y;
		move = 1;
	}
	if (game->map[(int)game->player.y][(int)(game->player.x + next_x)] != '1' &&
		(game->map[(int)game->player.y][(int)(game->player.x + next_x)] != 'D'
		|| game->door_state_map[(int)game->player.y]
		[(int)(game->player.x + next_x)] == 2))
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
	if (game->map[(int)(game->player.y - next_y)][(int)game->player.x] != '1' &&
		(game->map[(int)(game->player.y - next_y)][(int)game->player.x] != 'D'
		|| game->door_state_map[(int)(game->player.y - next_y)]
		[(int)game->player.x] == 2))
	{
		game->player.y -= next_y;
		move = 1;
	}
	if (game->map[(int)game->player.y][(int)(game->player.x - next_x)] != '1' &&
		(game->map[(int)game->player.y][(int)(game->player.x - next_x)] != 'D'
		|| game->door_state_map[(int)game->player.y]
		[(int)(game->player.x - next_x)] == 2))
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
	if (game->map[(int)(game->player.y + next_y)][(int)game->player.x] != '1' &&
		(game->map[(int)(game->player.y + next_y)][(int)game->player.x] != 'D'
		|| game->door_state_map[(int)(game->player.y + next_y)]
		[(int)game->player.x] == 2))
	{
		game->player.y += next_y;
		move = 1;
	}
	if (game->map[(int)game->player.y][(int)(game->player.x + next_x)] != '1' &&
		(game->map[(int)game->player.y][(int)(game->player.x + next_x)] != 'D'
		|| game->door_state_map[(int)game->player.y]
		[(int)(game->player.x + next_x)] == 2))
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
	if (game->map[(int)(game->player.y - next_y)][(int)game->player.x] != '1' &&
		(game->map[(int)(game->player.y - next_y)][(int)game->player.x] != 'D'
		|| game->door_state_map[(int)(game->player.y - next_y)]
		[(int)game->player.x] == 2))
	{
		game->player.y -= next_y;
		move = 1;
	}
	if (game->map[(int)game->player.y][(int)(game->player.x - next_x)] != '1' &&
		(game->map[(int)game->player.y][(int)(game->player.x - next_x)] != 'D'
		|| game->door_state_map[(int)game->player.y]
		[(int)(game->player.x - next_x)] == 2))
	{
		game->player.x -= next_x;
		move = 1;
	}
	return (move);
}

/**@} */