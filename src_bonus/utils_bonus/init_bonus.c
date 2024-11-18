/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:38:09 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/15 18:34:18 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"


void	init_status2(t_game *game)
{
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
	init_status2(game);
}

char	*files(int i, t_game *game)
{
	char	*strings[6];

	strings[0] = game->textr.south;
	strings[1] = game->textr.north;
	strings[2] = game->textr.east;
	strings[3] = game->textr.west;
	strings[4] = game->textr.door;
	strings[5] = game->textr.enemy1;
	return (strings[i]);
}

void init_minimap(t_game *game)
{
	game->minimap.mlx_img = mlx_new_image(game->mlx_ptr,
		game->widthmap * 10, game->heightmap * 10);
	if (!game->minimap.mlx_img)
		sepuku(game, ERROR_MLX);
	game->minimap.addr = mlx_get_data_addr(game->minimap.mlx_img,
			&game->minimap.bpp, &game->minimap.line_len, &game->minimap.endian);
	if (!game->minimap.addr)
		sepuku(game, ERROR_MLX);
}

void	init_img(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		game->img[i].mlx_img = mlx_xpm_file_to_image(game->mlx_ptr,
				files(i, game), &game->img[i].width, &game->img[i].height);
		i++;
	}
	game->img[6].mlx_img = mlx_new_image(game->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	i = 0;
	while (i < 7)
	{
		game->img[i].addr = mlx_get_data_addr(game->img[i].mlx_img,
				&game->img[i].bpp, &game->img[i].line_len,
				&game->img[i].endian);
		if (!game->img[i].addr)
			sepuku(game, ERROR_MLX);
		i++;
	}
	init_minimap(game);
	init_status(game);
}
