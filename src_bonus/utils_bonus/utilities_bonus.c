/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 08:37:16 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/29 11:01:44 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

suseconds_t	ft_get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

char	*files(int i, t_game *game)
{
	char	*strings[13];

	strings[0] = game->textr.south;
	strings[1] = game->textr.north;
	strings[2] = game->textr.east;
	strings[3] = game->textr.west;
	strings[4] = game->textr.door;
	strings[5] = game->textr.enemy;
	strings[8] = "textures/game/state1.xpm";
	strings[6] = "textures/game/state3.xpm";
	strings[7] = "textures/game/state2.xpm";
	strings[9] = "textures/game/state4.xpm";
	strings[10] = "textures/game/weapon.xpm";
	strings[11] = "textures/game/therock.xpm";
	strings[12] = "textures/game/loss.xpm";
	return (strings[i]);
}

char	*error_msg(enum e_error i)
{
	char	*strings[9];

	strings[0] = "Error\nArguments are invalid\n";
	strings[1] = "Error\nFile is invalid\n";
	strings[2] = "Error\nMap is invalid\n";
	strings[3] = "Error\nMalloc failed\n";
	strings[4] = "Error\nColor is invalid\n";
	strings[5] = "Error\nTexture is invalid\n";
	strings[6] = "Error\nMLX failed\n";
	strings[7] = "Error\nOrder is invalid\n";
	strings[8] = "Error\nDuplication found\n";
	return (strings[i]);
}

int	wait_and_exit(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (difftime(time(NULL), game->start_time) >= 3)
		ft_exit(game);
	return (0);
}
