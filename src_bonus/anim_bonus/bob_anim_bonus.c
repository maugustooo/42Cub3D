/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bob_anim_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:40:14 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/20 10:20:57 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	bob_anim(t_game *game)
{
	int y_offset;
	int adjusted_y;
	int x;
	int y;

	y_offset = (int)(game->bob_offset * sin(game->bob_time));
	adjusted_y = 0;
	x = -1;
	while(++x < SCREEN_WIDTH)
	{
		y = -1;
		while(++y < SCREEN_HEIGHT)
		{
			adjusted_y = y + y_offset;
			if(adjusted_y >= 0 && adjusted_y <= SCREEN_HEIGHT)
				put_pixel(game, x, adjusted_y, get_color(game, x, y, )); //TODO: add the correct image index
		}
	}
}
