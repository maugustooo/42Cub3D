/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:25:02 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/18 09:32:47 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_enemy(t_game *game)
{
	int i;
	int j;

	i = -1;
	while(game->map[++i])
	{
		j = -1;
		while(game->map[i][++j])
		{
			if (game->map[i][j] == 'X')
			{
				game->enemy.x = j + 0.5;
				game->enemy.y = i + 0.5;
			}
		}
	}
	game->enemy.health = 1;
	game->enemy.state = 0;
}
