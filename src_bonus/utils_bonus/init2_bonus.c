/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:25:02 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/25 09:48:43 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_enemy2(t_game *game)
{
	int i;

	i = 0;
	while(i < game->enemy_count)
	{
		game->enemy[i].frame_width = 66;
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

char *files(int i, t_game *game)
{
	char *strings[12];

	strings[0] = game->textr.south;
	strings[1] = game->textr.north;
	strings[2] = game->textr.east;
	strings[3] = game->textr.west;
	strings[4] = game->textr.door;
	strings[5] = game->textr.enemy1;
	strings[6] = "textures/game/state1.xpm";
	strings[7] = "textures/game/state2.xpm";
	strings[8] = "textures/game/state3.xpm";
	strings[9] = "textures/game/state4.xpm";
	strings[10] = "textures/game/weapon.xpm";
	strings[11] = "textures/game/therock.xpm";
	return (strings[i]);
}
