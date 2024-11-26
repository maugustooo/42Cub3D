/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sepuku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:21:22 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/26 10:46:47 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup Mandatory Mandatory
 * @{
 * @file sepuku.c
 * @brief 
*/

#include "cub3d.h"

/**
 * @brief Error messages
 * 
 * @param i Number of the error
 * @return char* String with the error message
*/
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

/**
 * @brief Free the textures
 * 
 * @param game Struct with the game information
*/
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
}

/**
 * @brief Free the game struct
 * 
 * @param game Struct with the game information
*/
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

/**
 * @brief Exit the program with an error message
 * 
 * @param game Struct with the game information
 * @param i Error number
 * @return int Exit the program
*/
int	sepuku(t_game *game, enum e_error i)
{
	if (game)
		freedom(game);
	ft_printf(error_msg(i));
	exit(EXIT_SUCCESS);
}

/**
 * @brief Exit the program
 * 
 * @param game Struct with the game information
 * @return int Exit the program
*/
int	ft_exit(t_game *game)
{
	freedom(game);
	exit(EXIT_SUCCESS);
}

/**@} */