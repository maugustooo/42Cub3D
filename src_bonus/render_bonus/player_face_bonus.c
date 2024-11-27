/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_face_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:13:44 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/27 09:14:40 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_color_player(t_game *game, int x, int y, int i)
{
	return (*(int *)(game->player_face[i].addr
		+ (y * game->player_face[i].line_len + x
			* (game->player_face[i].bpp / 8))));
}

void	put_pixel_player(t_game *game, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > SCREEN_HEIGHT - 1 || x < 0
		|| x > SCREEN_WIDTH - 1)
		return ;
	pixel = (game->player_face[4].addr + (y * game->player_face[4].line_len
				+ x * (game->player_face[4].bpp / 8)));
	*(int *)pixel = color;
}

void	clear_player_face(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < 128)
	{
		x = 0;
		while (x < 128)
		{
			put_pixel_player(game, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	put_player_face2(t_game *game)
{
	int	x;
	int	y;
	int	color;

	x = 1;
	while (x < 127)
	{
		y = 1;
		while (y < 127)
		{
			if (game->enemy_near == true && game->player.health == 0)
				color = get_color_player(game, x, y, 3);
			else
				color = get_color_player(game, x, y, game->player.health);
			if (color != 0)
				put_pixel_player(game, x + 16, y + 16, color);
			y++;
		}
		x++;
	}
}

void	put_player_face(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < 32)
	{
		put_pixel_player(game, x, 0, 0x000000);
		put_pixel_player(game, x, 127, 0x000000);
		x++;
	}
	y = 0;
	while (y < 32)
	{
		put_pixel_player(game, 0, y, 0x000000);
		put_pixel_player(game, 127, y, 0x000000);
		y++;
	}
	if (game->is_clear == true)
		clear_player_face(game);
	game->is_clear = false;
	x = 1;
	put_player_face2(game);
}
