/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:32:53 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/07 10:28:33 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse(char **argv, t_game *game, t_textr *textr)
{
	check_order(argv[1], game);
	read_textures(argv[1], game, textr);
	read_map(argv[1], game);
	check_textures(game, textr);
	check_colors(game, textr);
	check_map_content(game);
	game->heightmap = game->mapend - game->mapstart;
	map_content_validation(game);
}
