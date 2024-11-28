/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enem_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:37:58 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/28 16:04:55 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	reset_enemy_to_idle(t_enemy *enemy)
{
	enemy->sprite_line = 8;
	enemy->curr_frame = 0;
	enemy->flag = 1;
}

static void	handle_attack_flags(t_enemy *enemy)
{
	if (enemy->sprite_line == 9 && enemy->curr_frame == 2)
		enemy->swords = true;
	if (enemy->swords && 
		((enemy->sprite_line == 9 && enemy->curr_frame < 2) ||
		enemy->sprite_line == 8))
	{
		enemy->sprite_line = 9;
		enemy->curr_frame = 2;
	}
}

static void	update_attack_frames(t_enemy *enemy, t_game *game)
{
	if (enemy->curr_frame < 6 && enemy->sprite_line < 10)
		enemy->curr_frame++;
	else if (enemy->curr_frame == 6 && enemy->sprite_line < 10)
	{
		enemy->sprite_line++;
		enemy->curr_frame = 0;
	}
	else if (enemy->curr_frame < 4 && enemy->sprite_line == 10)
		enemy->curr_frame++;
	if (enemy->curr_frame == 4 && enemy->sprite_line == 10)
	{
		enemy->flag = 0;
		enemy->attacks++;
		game->player.health--;
	}
}

void	update_enemy_frame_attack2(t_game *game, int i)
{
	t_enemy	*enemy;

	enemy = &game->enemy[i];
	if (enemy->sprite_line <= 10 && enemy->sprite_line >= 8 && enemy->flag)
	{
		handle_attack_flags(enemy);
		update_attack_frames(enemy, game);
	}
	if (enemy->flag == 0 || enemy->sprite_line < 8)
		reset_enemy_to_idle(enemy);
}

void	update_enemy_frame_attack(t_game *game, t_timer *timer,
	double curr_time, int i)
{
	t_enemy	*enemy;
	double	delta_time;

	(void)timer;
	enemy = &game->enemy[i];
	delta_time = (curr_time - enemy->last_time) / 300;
	enemy->elapsed_time += delta_time;
	enemy->attacking = true;
	if (enemy->elapsed_time >= ATTACK_FRAME_DURATION)
	{
		update_enemy_frame_attack2(game, i);
		enemy->elapsed_time = 0;
	}
	enemy->last_time = curr_time;
}

void	update_enemy_frame_mov(t_game *game, double curr_time, int i)
{
	t_enemy	*enemy;
	double	delta_time;

	enemy = &game->enemy[i];
	delta_time = (curr_time - enemy->last_time) / 3000;
	enemy->swords = false;
	enemy->attacking = false;
	enemy->elapsed_time += delta_time;
	if (enemy->elapsed_time >= FRAME_DURATION)
	{
		if (enemy->moving)
			enemy->curr_frame = (enemy->curr_frame + 1) % NUM_FRAME;
		enemy->elapsed_time = 0;
	}
	enemy->sprite_line = 0;
	enemy->last_time = curr_time;
}

void	update_enemy_frame_death2(t_enemy *enemy)
{
	if (enemy->sprite_line == 10 && enemy->curr_frame < 6)
		enemy->curr_frame++;
	else if (enemy->sprite_line == 10 && enemy->curr_frame == 6)
	{
		enemy->sprite_line = 11;
		enemy->curr_frame = 0;
	}
	else if (enemy->sprite_line == 11)
	{
		if (enemy->curr_frame < 6)
			enemy->curr_frame++;
		else
		{
			enemy->curr_frame = 6;
			enemy->die = false;
			enemy->died = true;
		}
	}
}

void	update_enemy_frame_death(t_game *game, double curr_time, int i)
{
	t_enemy	*enemy;
	double	delta_time;

	enemy = &game->enemy[i];
	delta_time = (curr_time - enemy->last_time) / 400;
	enemy->elapsed_time += delta_time;
	if (enemy->die && !enemy->died &&
		enemy->elapsed_time >= DEATH_FRAME_DURATION)
	{
		update_enemy_frame_death2(enemy);
		enemy->elapsed_time = 0;
	}
	enemy->last_time = curr_time;
}

void	update_enemy_frame(t_game *game, t_timer *timer, double curr_time)
{
	int		i;
	double	dist;

	i = 0;
	while (i < game->enemy_count)
	{
		dist = sqrt(pow(game->player.x - game->enemy[i].x, 2) +
				pow(game->player.y - game->enemy[i].y, 2));
		if (!game->enemy[i].die && !game->enemy[i].died && dist > 1.2)
			update_enemy_frame_mov(game, curr_time, i);
		else if (!game->enemy[i].die && !game->enemy[i].died && dist <= 1.2)
			update_enemy_frame_attack(game, timer, curr_time, i);
		else if (!game->enemy[i].died)
			update_enemy_frame_death(game, curr_time, i);
		i++;
	}
}
