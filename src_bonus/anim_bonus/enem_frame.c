/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enem_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:37:58 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/22 15:52:09 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

suseconds_t ft_get_time(void)
{
    struct timeval  now;
    gettimeofday(&now, NULL);
    return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void	update_enemy_frame_mov(t_game *game,t_timer *timer, double curr_time, int i)
{
	double delta_time;
	
	(void)timer;
	delta_time = curr_time - game->enemy[i].last_time;
	delta_time /= 3000;
	game->enemy[i].elapsed_time += delta_time;
	if(game->enemy[i].elapsed_time >= FRAME_DURATION)
	{
		game->enemy[i].curr_frame = (game->enemy[i].curr_frame + 1) % NUM_FRAME;
	}
	if(game->enemy[i].elapsed_time >= FRAME_DURATION)
		game->enemy[i].elapsed_time = 0;
	game->enemy[i].sprite_line = 0;
	game->enemy[i].last_time = curr_time;
}

void update_enemy_frame_death(t_game *game, t_timer *timer, double curr_time, int i)
{
    double delta_time;

    delta_time = (curr_time - timer->enemy_last_time);
	delta_time /= 400;
    timer->enemy_elapsed_time += delta_time;
    if (game->enemy[i].die && game->enemy[i].died == false)
    {
        if (timer->enemy_elapsed_time >= DEATH_FRAME_DURATION)
        {
			if (game->enemy[i].sprite_line == 10)
        	{
            	if (game->enemy[i].curr_frame < 6)
                	game->enemy[i].curr_frame ++;
				else if (game->enemy[i].curr_frame == 6)
            	{
                	game->enemy[i].sprite_line = 11;
                	game->enemy[i].curr_frame = 0;
            	}
        	}
			else if (game->enemy[i].sprite_line == 11)
			{
				if (game->enemy[i].curr_frame < 6)
				{
					game->enemy[i].curr_frame++;
				}
				else
				{
					game->enemy[i].curr_frame = 6;
					game->enemy[i].sprite_line = 11;
					game->enemy[i].die = false;
					game->enemy[i].died = true;
				}
			}
            timer->enemy_elapsed_time = 0;
        }
    }
    timer->enemy_last_time = curr_time;
}

void	update_enemy_frame(t_game *game,t_timer *timer, double curr_time)
{
	int	i;

	i = 0;
    while (i < game->enemy_count)
    {
		if(!game->enemy[i].die && !game->enemy[i].died)
			update_enemy_frame_mov(game, timer, curr_time, i);
		else if (!game->enemy[i].died)
			update_enemy_frame_death(game, timer, curr_time, i);
		i++;
	}
}
