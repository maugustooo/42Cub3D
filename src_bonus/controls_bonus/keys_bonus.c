/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:18:15 by maugusto          #+#    #+#             */
/*   Updated: 2024/11/13 21:44:27 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		ft_exit(game);
	if (keycode == XK_w)
		game->player.move_up = 1;
	if (keycode == XK_s)
		game->player.move_down = 1;
	if (keycode == XK_a)
		game->player.move_left = 1;
	if (keycode == XK_d)
		game->player.move_right = 1;
	if (keycode == XK_Left)
		game->player.rotate_left = 1;
	if (keycode == XK_Right)
		game->player.rotate_right = 1;
	return (0);
}

int	handle_key_release(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		ft_exit(game);
	if (keycode == XK_w && game->player.move_up)
		game->player.move_up = 0;
	if (keycode == XK_s && game->player.move_down)
		game->player.move_down = 0;
	if (keycode == XK_a && game->player.move_left)
		game->player.move_left = 0;
	if (keycode == XK_d && game->player.move_right)
		game->player.move_right = 0;
	if (keycode == XK_Left && game->player.rotate_left)
		game->player.rotate_left = 0;
	if (keycode == XK_Right && game->player.rotate_right)
		game->player.rotate_right = 0;
	return (0);
}
	
int	handle_mouse(int x, int y, t_game *game)
{
	if(x < game->screen_width / 2)
	{
		rotate(game, -MSPEED);
	}
	else if(x > game->screen_width / 2)
	{
		rotate(game, MSPEED);
	}
	mlx_mouse_move(game->mlx_ptr, game->window, game->screen_width / 2, y);
	return (0);
}
