/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sepuku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:21:22 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/11 15:12:39 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*error_msg(enum e_error i)
{
	char	*strings[9];

	strings[0] = "Error\nArguments are invalid\n";
	strings[1] = "Error\nFile is invalid\n";
	strings[2] = "Error\nMap is invalid\n";
	strings[3] = "Error\nMalloc failed\n";
	strings[4] = "Error\nColor is invalid\n";
	strings[5] = "Error\nTexture is invalid\n";
	strings[6] = "Error\nMLX failed\n";
	strings[7] = "Error\nOrder is invalid\n";
	strings[8] = "Error\nDuplication found\n";
	return (strings[i]);
}

void	freedom(t_game *game)
{
	int	i;

	i = -1;
	if (game && game->map)
	{
		while (game->map[++i])
			free(game->map[i]);
		free(game->map);
	}
	i = 0;
	while (i < 5)
	{
		if (game && game->img[i].mlx_img)
			mlx_destroy_image(game->mlx_ptr, game->img[i].mlx_img);
		i++;
	}
	if (game && game->mlx_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->window);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
}


int	sepuku(t_game *game, enum e_error i)
{
		freedom(game);
	ft_printf(error_msg(i));
	exit(EXIT_SUCCESS);
}

int	ft_exit(t_game *game)
{
	freedom(game);
	exit(EXIT_SUCCESS);
}