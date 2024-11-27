/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:18:15 by maugusto          #+#    #+#             */
/*   Updated: 2024/11/27 08:48:18 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	if (keycode == XK_e)
		interact_with_door(game);
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
	if (x < SCREEN_WIDTH / 2)
		rotate(game, -MSPEED);
	else if (x > SCREEN_WIDTH / 2)
		rotate(game, MSPEED);
	if (y < SCREEN_HEIGHT / 2)
	{
		if (game->player.angle - 5 > -FOV / 2)
			game->player.angle -= 5;
	}
	else if (y > SCREEN_HEIGHT / 2)
	{
		if (game->player.angle + 5 < FOV / 2)
			game->player.angle += 5;
	}
	mlx_mouse_move(game->mlx_ptr, game->window, SCREEN_WIDTH / 2, y);
	return (0);
}

void	handle_mouse_click2(t_game *game)
{
	double	dx;
	double	dy;
	double	distance;
	int		i;

	i = 0;
	while (i < game->enemy_count)
	{
		dx = game->enemy[i].x - game->player.x;
		dy = game->enemy[i].y - game->player.y;
		distance = sqrt(dx * dx + dy * dy);
		if (distance < 1.0)
		{
			game->enemy[i].die = true;
			game->enemy[i].sprite_line = 10;
			game->enemy[i].curr_frame = 4;
		}
		game->enemy[i].curr_time = (double)ft_get_time();
		i++;
	}
}

int	handle_mouse_click(int button, int x, int y, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	(void)x;
	(void)y;
	if (button == Button1)
	{
		game->player.attack = true;
		handle_mouse_click2(game);
	}
	return (0);
}
