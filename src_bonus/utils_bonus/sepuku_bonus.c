/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sepuku_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:21:22 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/29 09:01:04 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	destroy_img(t_game *game)
{
	int	i;

	i = -1;
	if (game->weapon_img.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->weapon_img.mlx_img);
	if (game->victory.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->victory.mlx_img);
	if (game->loss.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->loss.mlx_img);
	if (game->fps_img.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->fps_img.mlx_img);
	while (++i <= 4)
		if (game->player_face[i].mlx_img)
			mlx_destroy_image(game->mlx_ptr, game->player_face[i].mlx_img);
	i = 0;
	while (i < 11)
	{
		if (game && game->img[i].mlx_img)
			mlx_destroy_image(game->mlx_ptr, game->img[i].mlx_img);
		i++;
	}
}

void	free_textures(t_game *game)
{
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
}

void	freedom(t_game *game)
{
	int	i;

	i = 0;
	if (game && game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
	}
	free_textures(game);
	destroy_img(game);
	if (game && game->mlx_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->window);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	i = 0;
	if (game && game->door_state_map)
	{
		while (i < game->heightmap)
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
