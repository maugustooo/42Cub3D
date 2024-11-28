/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:13:57 by maugusto          #+#    #+#             */
/*   Updated: 2024/11/28 11:22:51 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	render_background(t_game *game)
{
	int		x;
	int		y;
	double	fog;
	int		fog_color;

	x = 0;
	fog = 0.25;
	fog_color = 200;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT - 1)
		{
			if (y <= (SCREEN_HEIGHT / 2) - 1)
				put_pixel(game, x, y, create_rgb(0, (1 - fog) * game->rgb_sky[0]
						+ fog * fog_color,
						(1 - fog) * game->rgb_sky[1] + fog * fog_color,
						(1 - fog) * game->rgb_sky[2] + fog * fog_color));
			else
				put_pixel(game, x, y, create_rgb(0, (1 - fog)
						* game->rgb_floor[0] + fog * fog_color,
						(1 - fog) * game->rgb_floor[1] + fog * fog_color,
						(1 - fog) * game->rgb_floor[2] + fog * fog_color));
			y++;
		}
		x++;
	}
}

int	wait_and_exit(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (difftime(time(NULL), game->start_time) >= 3)
		ft_exit(game);
	return (0);
}

void	check_victory(t_game *game)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < game->enemy_count)
	{
		if (game->enemy[i].died == true)
			count ++;
		i++;
	}
	if (count == game->enemy_count && game->player.health > 0)
	{
		mlx_clear_window(game->mlx_ptr, game->window);
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->victory.mlx_img, 0, 0);
		game->start_time = time(NULL);
		mlx_loop_hook(game->mlx_ptr, wait_and_exit, game);
		mlx_loop(game->mlx_ptr);
	}
	else if (game->player.health == 0)
	{
		mlx_clear_window(game->mlx_ptr, game->window);
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->loss.mlx_img, 0, 0);
		game->start_time = time(NULL);
		mlx_loop_hook(game->mlx_ptr, wait_and_exit, game);
		mlx_loop(game->mlx_ptr);
	}
}

void	mlx_put_img(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->window, game->img[6].mlx_img,
		0, 0);
	mlx_put_image_to_window(game->mlx_ptr, game->window,
		game->player_face[4].mlx_img, SCREEN_WIDTH - 192, SCREEN_HEIGHT - 192);
	mlx_put_image_to_window(game->mlx_ptr, game->window, game->minimap.mlx_img,
		10, 10);
	mlx_put_image_to_window(game->mlx_ptr, game->window, game->fps_img.mlx_img,
		game->widthmap * 10 + 12, 12);
}

int	render(t_game *game)
{
	double	curr_time;

	check_victory(game);
	controls(game);
	render_background(game);
	raycasting(game);
	curr_time = (double)ft_get_time();
	update_enemy_frame(game, &game->timer, curr_time);
	handle_enemy(game);
	put_player_face(game);
	update_weapon_frame(game, &game->timer, curr_time);
	game->z_buffer[game->x] = game->walldist;
	update_fps(game);
	render_minimap(game);
	render_weapon(game);
	mlx_put_img(game);
	return (0);
}
