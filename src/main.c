/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:57:01 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/12 22:30:59 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
int	main(int argc, char **argv)
{
	t_game	game;
	t_textr	textr;
	int		fd;

	if(argc == 2)
	{
		check_extension(argv[1]);
		ft_memset(&textr, 0, sizeof(t_textr));
		ft_memset(&game, 0, sizeof(t_game));
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			sepuku(&game, ERROR_ARGS);
		close(fd);
		//TODO: VERIFICAR COM OS MAPAS TODOS, OS BONS E MAUS com valgrind, temos make valgrind tens e que mudar o $ARG, VERIFICAR AS CORES QUE ALGUMA MERDA TA MAL
		parse(argv, &game);
		mlx_functions(&game);
	}
	return(EXIT_SUCCESS);
}

//TODO: NAO RETIRAR ESTE TODO ATE AO FIM, NAO RETIRAR AS TEXTURAS DO GITIGNORE