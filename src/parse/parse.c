/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:32:53 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/26 11:01:01 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file parse.c
 * @brief Parsing functions
 */

#include "cub3d.h"

/**
 * @brief Parsing the file
 * @param argv Argument vector
 * @param game Struct with game information
*/
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
}

/**@} */