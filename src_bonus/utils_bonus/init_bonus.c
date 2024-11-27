/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:38:09 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/27 15:30:56 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_status2(t_game *game)
{
	game->player.health = 4;
	if (game->player.angle == EAST)
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->plane_x = 0.1;
		game->plane_y = 0.8;
	}
	if (game->player.angle == WEST)
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->plane_x = 0.1;
		game->plane_y = -0.8;
	}
}

void	init_status(t_game *game)
{
	if (game->player.angle == NORTH)
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->plane_x = 0.8;
		game->plane_y = 0;
	}
	if (game->player.angle == SOUTH)
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->plane_x = -0.8;
		game->plane_y = 0;
	}
	game->player.health = 0;
	game->player.scared = 0;
	init_status2(game);
}

void	init_minimap(t_game *game)
{
	game->minimap.mlx_img = mlx_new_image(game->mlx_ptr,
			game->widthmap * 10, game->heightmap * 10);
	if (!game->minimap.mlx_img)
		sepuku(game, ERROR_MLX);
	game->minimap.addr = mlx_get_data_addr(game->minimap.mlx_img,
			&game->minimap.bpp, &game->minimap.line_len, &game->minimap.endian);
	if (!game->minimap.addr)
		sepuku(game, ERROR_MLX);
	game->fps_img.mlx_img = mlx_new_image(game->mlx_ptr,
			64, 13);
	if (!game->fps_img.mlx_img)
		sepuku(game, ERROR_MLX);
	game->fps_img.addr = mlx_get_data_addr(game->fps_img.mlx_img,
			&game->fps_img.bpp, &game->fps_img.line_len, &game->fps_img.endian);
	if (!game->fps_img.addr)
		sepuku(game, ERROR_MLX);
}

void	init_door_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->door_state_map = (int **)malloc(game->heightmap * sizeof(int *));
	game->door_timer_map = (double **)malloc(game->heightmap * sizeof(double *));
	if (!game->door_state_map || !game->door_timer_map)
		sepuku(game, ERROR_MALLOC);
	while (++i < game->heightmap)
	{
		j = 0;
		game->door_state_map[i] = (int *)malloc(game->widthmap * sizeof(int));
		game->door_timer_map[i] = (double *)malloc(game->widthmap * sizeof(double));
		if (!game->door_state_map[i] || !game->door_timer_map[i])
			sepuku(game, ERROR_MALLOC);
		while (j < game->widthmap)
		{
			game->door_timer_map[i][j] = 0;
			if (game->map[i][j] == 'D')
				game->door_state_map[i][j] = 0;
			else
				game->door_state_map[i][j] = 0;
			j++;
		}
	}
}

void	init_img(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		game->img[i].mlx_img = mlx_xpm_file_to_image(game->mlx_ptr,
				files(i, game), &game->img[i].width, &game->img[i].height);
		if (i < 4)
			game->player_face[i].mlx_img = mlx_xpm_file_to_image(game->mlx_ptr,
					files(i + 6, game), &game->player_face[i].width, &game->player_face[i].height);
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
	i = 0;
	while (i < 7)
	{
		game->img[i].addr = mlx_get_data_addr(game->img[i].mlx_img,
				&game->img[i].bpp, &game->img[i].line_len, &game->img[i].endian);
		if (!game->img[i].addr)
			sepuku(game, ERROR_MLX);
		if (i < 5)
		{
			game->player_face[i].addr = mlx_get_data_addr(game->player_face[i].mlx_img,
					&game->player_face[i].bpp, &game->player_face[i].line_len, &game->player_face[i].endian);
			if (!game->player_face[i].addr)
				sepuku(game, ERROR_MLX);
		}
		i++;
	}
	game->weapon_img.addr = mlx_get_data_addr(game->weapon_img.mlx_img,
			&game->weapon_img.bpp, &game->weapon_img.line_len,
			&game->weapon_img.endian);
	init_door_map(game);
	init_minimap(game);
	init_status(game);
}
