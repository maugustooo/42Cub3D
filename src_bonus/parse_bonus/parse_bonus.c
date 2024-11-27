/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:32:53 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/27 11:07:28 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	parse(char **argv, t_game *game)
{
	check_order(argv[1], game);
	read_textures(argv[1], game);
	check_colors(game);
	check_textures(game);
	read_map(argv[1], game);
	check_map_content(game);
	get_map_width(game);
	game->heightmap = game->mapend;
	map_content_validation(game);
	init_enemy(game);
	init_door(game);
}
