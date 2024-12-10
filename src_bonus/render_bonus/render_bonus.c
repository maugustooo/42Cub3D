/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:13:57 by maugusto          #+#    #+#             */
/*   Updated: 2024/12/10 10:29:46 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgrop bonus Bonus
 * @{
 * @file render_bonus.c
 * @brief Functions to render the game.
 */

#include "cub3d_bonus.h"

/**
 * @brief Put pixel in the screen for background
 * @param game Pointer to structure t_game
 * @param x X coordinate
 * @param y Y coordinate
 * @param color Color in hex
*/
void	put_pixel_bg(t_game *game, int x, int y, int type)
{
	if (type == 1)
	{
		put_pixel(game, x, y,
			create_rgb(0, (1 - game->fog) * game->rgb_sky[0]
				+ game->fog * game->fog_color,
				(1 - game->fog) * game->rgb_sky[1]
				+ game->fog * game->fog_color,
				(1 - game->fog) * game->rgb_sky[2]
				+ game->fog * game->fog_color));
	}
	else
	{
		put_pixel(game, x, y,
			create_rgb(0, (1 - game->fog) * game->rgb_floor[0]
				+ game->fog * game->fog_color,
				(1 - game->fog) * game->rgb_floor[1]
				+ game->fog * game->fog_color,
				(1 - game->fog) * game->rgb_floor[2]
				+ game->fog * game->fog_color));
	}
}

/**
 * @brief Render background
 * @param game Pointer to structure t_game
*/
void	render_background(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT - 1)
		{
			if (y <= (SCREEN_HEIGHT / 2) - 1)
				put_pixel_bg(game, x, y, 1);
			else
				put_pixel_bg(game, x, y, 2);
			y++;
		}
		x++;
	}
}

/**
 * @brief Check if player won or lost
 * @param game Pointer to structure t_game
*/
void	check_victory(t_game *game)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (++i < game->enemy_count)
	{
		if (game->enemy[i].died == true)
			count ++;
	}
	if ((count == game->enemy_count && game->player.health > 0)
		|| game->player.health == 0)
	{
		mlx_clear_window(game->mlx_ptr, game->window);
		if (count == game->enemy_count && game->player.health > 0)
			mlx_put_image_to_window(game->mlx_ptr, game->window,
				game->victory.mlx_img, 0, 0);
		else if (game->player.health == 0)
			mlx_put_image_to_window(game->mlx_ptr, game->window,
				game->loss.mlx_img, 0, 0);
		game->start_time = time(NULL);
		mlx_loop_hook(game->mlx_ptr, wait_and_exit, game);
		mlx_loop(game->mlx_ptr);
	}
}

/**
 * @brief Put images to window 
 * @param game Pointer to structure t_game
*/
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

/**
 * @brief Render main function
 * 
 * @param game Pointer to structure t_game
 * @return int Normal return
*/
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

/**@} */