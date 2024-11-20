/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:25:02 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/20 12:54:09 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_enemy2(t_game *game)
{
	int i;

	i = 0;
	while(i < game->enemy_count)
	{
		game->enemy[i].num_frame = NUM_FRAME;
		game->enemy[i].frame_width = 64;
		game->enemy[i].frame_height = 64;
		game->enemy[i].curr_frame = 0;
		i++;
	}
}

void	init_enemy(t_game *game)
{
	int i;
	int j;
	int count = 0;
	i = -1;
	
	while(game->map[++i])
	{
		j = -1;
		while(game->map[i][++j])
		{
			if (game->map[i][j] == 'X')
			{
				game->enemy[count].x = j + 0.5;
				game->enemy[count].y = i + 0.5;
				game->enemy[count].health = 1;
				game->enemy[count++].state = 0;
			}
		}
	}
	game->enemy_count = count;
	init_enemy2(game);
}
