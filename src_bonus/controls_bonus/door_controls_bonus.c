/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_controls_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:44:08 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/27 08:45:12 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	open_or_close_door(t_game *game, int map_x, int map_y)
{
	int	door_state;

	door_state = game->door_state_map[map_y][map_x];
	if (door_state == 0)
		game->door_state_map[map_y][map_x] = 1;
	else if (door_state == 2)
		game->door_state_map[map_y][map_x] = 3;
}

void	interact_with_door(t_game *game)
{
	int	map_x;
	int	map_y;

	map_x = (int)(game->player.x + game->player.dir_x);
	map_y = (int)(game->player.y + game->player.dir_y);
	if (game->map[map_y][map_x] == 'D')
		open_or_close_door(game, map_x, map_y);
}
