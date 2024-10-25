/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:57:01 by gude-jes          #+#    #+#             */
/*   Updated: 2024/10/25 09:19:08 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game *game;
	int		fd;

	if(argc == 2)
	{
		check_extension(argv[1]);
		game = init();
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			sepuku(game);
		parse(argv, game);
	}
	return(EXIT_SUCCESS);
}
