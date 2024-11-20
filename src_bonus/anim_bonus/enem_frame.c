/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enem_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:37:58 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/20 09:38:10 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	render_enemy_frame_mov(t_game *game, int x, int y)
{
	int frame_x;
	int frame_y;
	int i;

	i = 0;
	while(i < game->enemy_count)
	{
		frame_x = game->enemy[i].curr_frame * game->enemy[i].frame_width;
		frame_y = 0;
	}
}

void	update_enemy_frame_mov(t_game *game,t_timer *timer, double curr_time)
{
	double delta_time;
	int i;

	delta_time = curr_time - timer->last_time;
	timer->elapsed_time += delta_time;
	i - 0;
	while(i < game->enemy_count)
	{
		if(timer->elapsed_time >= FRAME_DURATION)
		{
			game->enemy[i].curr_frame = (game->enemy[i].curr_frame + 1) % NUM_FRAME;
			timer->elapsed_time = 0;
		}
		timer->last_time = curr_time;
		i++;
	}
}