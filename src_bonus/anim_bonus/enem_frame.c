/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enem_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:37:58 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/05 11:46:47 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file enem_frame.c
 * @brief Enemy frame update functions.
 */

#include "cub3d_bonus.h"

/**
 * @brief Update enemy frame when enemy is moving.
 *
 * @param game Pointer to the game structure.
 * @param timer Pointer to the timer structure.
 * @param curr_time Current time.
 * @param i Index of the enemy.
 */
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

/**
 * @brief Continuation of update_enemy_frame_death function.
 * 
 * @param enemy Pointer to the enemy structure.
*/
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

/**
 * @brief Update enemy frame when enemy is dying.
 *
 * @param game Pointer to the game structure.
 * @param curr_time Current time.
 * @param i Index of the enemy.
 */
void	update_enemy_frame_death(t_game *game, double curr_time, int i)
{
	t_enemy	*enemy;
	double	delta_time;

	enemy = &game->enemy[i];
	delta_time = (curr_time - enemy->last_time) / 400;
	enemy->elapsed_time += delta_time;
	if (enemy->die && !enemy->died
		&& enemy->elapsed_time >= DEATH_FRAME_DURATION)
	{
		update_enemy_frame_death2(enemy);
		enemy->elapsed_time = 0;
	}
	enemy->last_time = curr_time;
}

/**
 * @brief Update enemy frame.
 *
 * @param game Pointer to the game structure.
 * @param timer Pointer to the timer structure.
 * @param curr_time Current time.
 */
void	update_enemy_frame(t_game *game, t_timer *timer, double curr_time)
{
	int		i;
	double	dist;

	i = 0;
	while (i < game->enemy_count)
	{
		dist = sqrt(pow(game->player.x - game->enemy[i].x, 2)
				+ pow(game->player.y - game->enemy[i].y, 2));
		if (!game->enemy[i].die && !game->enemy[i].died && dist > 1.2)
			update_enemy_frame_mov(game, curr_time, i);
		else if (!game->enemy[i].die && !game->enemy[i].died && dist <= 1.2)
			update_enemy_frame_attack(game, timer, curr_time, i);
		else if (!game->enemy[i].died)
			update_enemy_frame_death(game, curr_time, i);
		i++;
	}
}

/**@} */