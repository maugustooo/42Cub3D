/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:38:09 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/05 16:00:23 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*files(int i)
{
	char	*strings[2];

	strings[0] = "img/img0.xpm";
	strings[1] = "img/img1.xpm";
	return (strings[i]);
}
void init_img(t_game *game)
{
	int i;

	i = 0;
	while (i < 2)
	{
		printf("%s\n", files(i));
		game->img[i].mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, files(i), &game->img[i].width, &game->img[i].height);
		i++;
	}
	i = 0;
	game->img[1].mlx_img = mlx_new_image(game->mlx_ptr,
			game->widthmap, game->heightmap);
	while (i < 2)
	{
		game->img[i].addr = mlx_get_data_addr(game->img[i].mlx_img,
				&game->img[i].bpp, &game->img[i].line_len, &game->img[i].endian);
		if (!game->img[i].addr)
			sepuku(game);
		i++;
	}
	
}
