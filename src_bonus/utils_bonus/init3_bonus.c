/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 08:49:57 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/29 10:27:31 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_weapon(t_game *game)
{
	game->weapon.scale_factor_width = 4.0;
	game->weapon.scale_factor_height = 3.0;
	game->weapon.frame_height = 93;
	game->weapon.frame_width = 511;
	game->weapon.frame_width = game->weapon.frame_width / WEAPON_NUM_FRAME;
	game->weapon.scaled_width = (int)(game->weapon.frame_width
			* game->weapon.scale_factor_width);
	game->weapon.scaled_height = (int)(game->weapon.frame_height
			* game->weapon.scale_factor_height);
}

void	init_fps(t_fps *fps)
{
	gettimeofday(&fps->last_time, NULL);
	fps->frame_count = 0;
	fps->elapsed_time = 0.0;
	fps->fps = 0;
}

void	xpm_img(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		game->img[i].mlx_img = mlx_xpm_file_to_image(game->mlx_ptr,
				files(i, game), &game->img[i].width, &game->img[i].height);
		if (i < 4)
			game->player_face[i].mlx_img = mlx_xpm_file_to_image(game->mlx_ptr,
					files(i + 6, game), &game->player_face[i].width,
					&game->player_face[i].height);
		i++;
	}
	game->img[6].mlx_img = mlx_new_image(game->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	game->player_face[4].mlx_img = mlx_new_image(game->mlx_ptr,
			128 + 32, 128 + 32);
	game->weapon_img.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr,
			files(10, game), &game->weapon_img.width, &game->weapon_img.height);
	game->victory.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr,
			files(11, game), &game->victory.width, &game->victory.height);
	game->loss.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr,
			files(12, game), &game->loss.width, &game->loss.height);
}

void	init_fog(t_game *game)
{
	game->fog = 0.25;
	game->fog_color = 200;
}
