/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:50:16 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/27 09:10:26 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_fps(t_fps *fps)
{
    gettimeofday(&fps->last_time, NULL);
    fps->frame_count = 0;
    fps->elapsed_time = 0.0;
    fps->fps = 0;
}

int	check_enemy(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->enemy_count)
	{
		if ((int)game->enemy[i].x == x && (int)game->enemy[i].y == y
			&& game->enemy[i].died)
			return (1);
		i++;
	}
	return (0);
}
