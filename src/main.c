/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:57:01 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/04 18:36:58 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_functions(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->window = mlx_new_window(game->mlx_ptr, game->widthmap,
			game->heightmap, "Cub3D");
	mlx_key_hook(game->window, controls, &game);
	mlx_hook(game->window, 17, 0, sepuku, &game);
	mlx_loop(game->mlx_ptr);
}
int	main(int argc, char **argv)
{
	//TODO:NAO SE INICIALIZA A STRUCT COM POINTER, TEM AQUI ALGUMAS SYNTAX MAL, TEMOS QUE PASSAR O ADDRESS DA STRUCT PARA TRABALHAR COM ELA, TEMOS QUE VER DEPOIS
	t_game	game;
	t_textr	textr;
	int		fd;
	
	//TODO:MANO, EU VI QUE NAO PODEMOS USAR O "ADDSUFIX", TEMOS QUE METER OS FILES 1 A 1?? DEPOIS TEMOS QUE VER ISSO
	if(argc == 2)
	{
		check_extension(argv[1]);
		ft_memset(&textr, 0, sizeof(t_textr));
		ft_memset(&game, 0, sizeof(t_game));
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			sepuku(&game);
		//TODO:PRECISO QUE METAS O TAMANHO DO MAPA NO PARSE(GAME->WIDTHMAP E GAME->HEIGHTMAP)
		parse(argv, &game, &textr);
		game.heightmap = 500;
		game.widthmap = 500;
		mlx_functions(&game);
		ft_printf("Went Through\n");
	}
	return(EXIT_SUCCESS);
}
