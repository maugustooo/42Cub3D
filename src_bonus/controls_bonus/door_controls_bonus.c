/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_controls_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:44:08 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/28 16:02:48 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	toggle_door(t_game *game, int door_x, int door_y)
{
	if (game->door_state_map[door_y][door_x] == 0)
	{
		game->door_state_map[door_y][door_x] = 1;
		game->map[door_y][door_x] = 'd';
	}
	else if (game->door_state_map[door_y][door_x] == 1)
	{
		game->door_state_map[door_y][door_x] = 0;
		game->map[door_y][door_x] = 'D';
	}
}

void	interact_with_door(t_game *game)
{
	int	map_x;
	int	map_y;

	map_x = (int)(game->player.x + game->player.dir_x);
	map_y = (int)(game->player.y + game->player.dir_y);
	if (game->map[map_y][map_x] == 'D' || game->map[map_y][map_x] == 'd')
		toggle_door(game, map_x, map_y);
}
