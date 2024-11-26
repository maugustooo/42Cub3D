/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:57:01 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/26 10:33:50 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file main.c
 * @brief Main file of the project
*/

#include "cub3d.h"

/**
 * @brief Graphic rendering function
 * 
 * @param game Struct with game information
*/
void	mlx_functions(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		sepuku(game, ERROR_MLX);
	game->screen_width = 1920;
	game->screen_height = 945;
	game->window = mlx_new_window(game->mlx_ptr, game->screen_width,
			game->screen_height, "Cub3D");
	if (!game->window)
		sepuku(game, ERROR_MLX);
	init_img(game);
	mlx_loop_hook(game->mlx_ptr, &render, game);
	mlx_hook(game->window, KeyPress, KeyPressMask, handle_key_press, game);
	mlx_hook(game->window, KeyRelease, KeyRelease, handle_key_release, game);
	mlx_hook(game->window, 17, 0, sepuku, game);
	mlx_loop(game->mlx_ptr);
}

/**
 * @brief Main function of the project
 * 
 * @param argc Number of arguments
 * @param argv Arguments
 * @return int Exit status
*/
int	main(int argc, char **argv)
{
	t_game	game;
	t_textr	textr;
	int		fd;

	if (argc == 2)
	{
		check_extension(argv[1]);
		ft_memset(&textr, 0, sizeof(t_textr));
		ft_memset(&game, 0, sizeof(t_game));
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			sepuku(&game, ERROR_ARGS);
		close(fd);
		parse(argv, &game);
		mlx_functions(&game);
	}
	return (EXIT_SUCCESS);
}

/**@} */