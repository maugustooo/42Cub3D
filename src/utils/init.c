/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:38:09 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/11 10:47:17 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*files(int i, t_game *game)
{
	char	*strings[4];

	strings[0] = game->textr.north;
	strings[1] = game->textr.south;
	strings[2] = game->textr.west;
	strings[3] = game->textr.east;
	return (strings[i]);
}
void init_img(t_game *game)
{
	int i;

	i = 0;
	while (i < 4)
	{
		game->img[i].mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, files(i, game), &game->img[i].width, &game->img[i].height);
		i++;
	}
	game->img[4].mlx_img = mlx_new_image(game->mlx_ptr,
			game->screen_width, game->screen_height);
	i = 0;
	while (i < 5)
	{
		game->img[i].addr = mlx_get_data_addr(game->img[i].mlx_img,
				&game->img[i].bpp, &game->img[i].line_len, &game->img[i].endian);
		if (!game->img[i].addr)
			sepuku(game, ERROR_MLX);
		i++;
	}
	game->plane_x = 0.80;
	game->plane_y = 0;
	game->player.dir_x = 0;
	game->player.dir_y = -1;
}
