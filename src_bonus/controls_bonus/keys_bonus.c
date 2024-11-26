/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:18:15 by maugusto          #+#    #+#             */
/*   Updated: 2024/11/26 09:25:57 by gude-jes         ###   ########.fr       */
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

int handle_mouse_click(int button, int x, int y, void *param)
{
	t_game	*game;
	double	dx;
	double	dy;
	double	distance;
	int		i;

	i = 0;
	game = (t_game *)param;
	(void)x;
	(void)y;
	if (button == Button1)
	{
		game->player.attack = true;
		while (i < game->enemy_count)
		{
			dx = game->enemy[i].x - game->player.x;
			dy = game->enemy[i].y - game->player.y;
			distance = sqrt(dx * dx + dy * dy);
			if (distance < 1.0)
			{
				game->enemy[i].die = true;
				game->enemy[i].sprite_line = 10; // Iniciar a sequência de morte
				game->enemy[i].curr_frame = 4;
			}
			game->enemy[i].curr_time = (double)ft_get_time();
			i++;
		}
		
	}
	return (0);
}
