/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sepuku_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:21:22 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/28 12:18:38 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

void	free_textures(t_game *game)
{
	int i;

	i = -1;
	if (game->textr.north)
		free(game->textr.north);
	if (game->textr.west)
		free(game->textr.west);
	if (game->textr.south)
		free(game->textr.south);
	if (game->textr.east)
		free(game->textr.east);
	if (game->textr.floor)
		free(game->textr.floor);
	if (game->textr.ceiling)
		free(game->textr.ceiling);
	if (game->textr.enemy)
		free(game->textr.enemy);
	if (game->textr.door)
		free(game->textr.door);
	while(++i <= 4)
		if(game->player_face[i].mlx_img)
			mlx_destroy_image(game->mlx_ptr, game->player_face[i].mlx_img);
	if(game->weapon_img.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->weapon_img.mlx_img);
	if(game->victory.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->victory.mlx_img);
	if(game->loss.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->loss.mlx_img);
	if(game->fps_img.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->fps_img.mlx_img);
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
	free_textures(game);
	i = 0;
	while (i < 11)
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
	i = 0;
	if(game && game->door_state_map)
	{
		while(i < game->heightmap)
			free(game->door_state_map[i++]);
		free(game->door_state_map);
	}
}

int	sepuku(t_game *game, enum e_error i)
{
	if (game)
		freedom(game);
	ft_printf(error_msg(i));
	exit(EXIT_SUCCESS);
}

int	ft_exit(t_game *game)
{
	freedom(game);
	exit(EXIT_SUCCESS);
}
