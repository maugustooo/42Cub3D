/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enem_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:37:58 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/28 15:59:42 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void update_enemy_frame_attack2(t_game *game, int i)
{
    if (game->enemy[i].sprite_line <= 10 &&  game->enemy[i].sprite_line >= 8 && game->enemy[i].flag == 1)
    {
		if(game->enemy[i].sprite_line == 9 && game->enemy[i].curr_frame == 2)
			game->enemy[i].swords = true;
		if(game->enemy[i].swords == true && ((game->enemy[i].sprite_line == 9 && game->enemy[i].curr_frame < 2) || game->enemy[i].sprite_line == 8))
		{
			game->enemy[i].sprite_line = 9;
			game->enemy[i].curr_frame = 2;
		}
        if (game->enemy[i].curr_frame < 6 && game->enemy[i].sprite_line < 10)
            game->enemy[i].curr_frame++;
        else if (game->enemy[i].curr_frame == 6 && game->enemy[i].sprite_line < 10)
        {
            game->enemy[i].sprite_line++;
            game->enemy[i].curr_frame = 0;
        }
        else if (game->enemy[i].curr_frame < 4 && game->enemy[i].sprite_line == 10)
		{
        	game->enemy[i].curr_frame ++;
		}
		if(game->enemy[i].curr_frame == 4 && game->enemy[i].sprite_line == 10)
		{
			game->enemy[i].flag = 0;
			game->enemy[i].attacks++;
			game->player.health --;
		}
    }
	if (game->enemy[i].flag == 0 || game->enemy[i].sprite_line < 8)
	{
		game->enemy[i].sprite_line = 8;
		game->enemy[i].curr_frame = 0;
		game->enemy[i].flag = 1;
	}
}


void	update_enemy_frame_attack(t_game *game, t_timer *timer,
	double curr_time, int i)
{
	double	delta_time;
	
	(void)timer;
	delta_time = (curr_time - game->enemy[i].last_time);
	delta_time /= 300;
	game->enemy[i].elapsed_time += delta_time;
	game->enemy[i].attacking = true;
	if (game->enemy[i].elapsed_time >= ATTACK_FRAME_DURATION)
	{
		update_enemy_frame_attack2(game, i);
		game->enemy[i].elapsed_time = 0;
	}
	game->enemy[i].last_time = curr_time;
}

void update_enemy_frame_mov(t_game *game, t_timer *timer, double curr_time, int i)
{
    double delta_time;

    (void)timer;
    delta_time = curr_time - game->enemy[i].last_time;
    delta_time /= 3000;
    game->enemy[i].swords = false;
    game->enemy[i].attacking = false;
    game->enemy[i].elapsed_time += delta_time;
    if (game->enemy[i].elapsed_time >= FRAME_DURATION)
    {
		if (game->enemy[i].moving)
        	game->enemy[i].curr_frame = (game->enemy[i].curr_frame + 1) % NUM_FRAME;
        game->enemy[i].elapsed_time = 0;
    }
	game->enemy[i].sprite_line = 0;
    game->enemy[i].last_time = curr_time;
}

void	update_enemy_frame_death2(t_game *game, int i)
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
}

void	update_enemy_frame_death(t_game *game, t_timer *timer,
	double curr_time, int i)
{
	double	delta_time;

	(void)timer;
	delta_time = (curr_time - game->enemy[i].last_time);
	delta_time /= 400;
	game->enemy[i].elapsed_time += delta_time;
	if (game->enemy[i].die && game->enemy[i].died == false)
	{
		if (game->enemy[i].elapsed_time >= DEATH_FRAME_DURATION)
		{
			update_enemy_frame_death2(game, i);
			game->enemy[i].elapsed_time = 0;
		}
	}
	game->enemy[i].last_time = curr_time;
}

void	update_enemy_frame(t_game *game, t_timer *timer, double curr_time)
{
	int	i;
	double dist;
	
	i = 0;
	while (i < game->enemy_count)
	{
		dist = sqrt(pow(game->player.x - game->enemy[i].x, 2) +
			pow(game->player.y - game->enemy[i].y, 2));
		if (!game->enemy[i].die && !game->enemy[i].died && dist > 1.2)
			update_enemy_frame_mov(game, timer, curr_time, i);
		else if (!game->enemy[i].die && !game->enemy[i].died && dist <= 1.2)
			update_enemy_frame_attack(game, timer, curr_time, i);
		else if (!game->enemy[i].died)
			update_enemy_frame_death(game, timer, curr_time, i);
		i++;
	}
}
