/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:57:01 by gude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 10:26:18 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	t_textr	*textr;
	int		fd;

	if(argc == 2)
	{
		check_extension(argv[1]);
		textr = init_textr();
		game = init_game();
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			sepuku(game);
		parse(argv, game, textr);
		ft_printf("Went Through\n");
	}
	return(EXIT_SUCCESS);
}
