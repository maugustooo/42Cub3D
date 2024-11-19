/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:25:02 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/19 12:06:16 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
}
