/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:17:26 by maugusto          #+#    #+#             */
/*   Updated: 2024/11/20 11:10:13 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void wait_half_second(void)
{
    struct timeval start;
    struct timeval current;
    long elapsed_time;

    gettimeofday(&start, NULL);
    elapsed_time = 0;
    while (elapsed_time < 50)
    {
        gettimeofday(&current, NULL);
        elapsed_time = (current.tv_sec - start.tv_sec) * 1000000 + (current.tv_usec - start.tv_usec);
    }
}

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
