/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:29:59 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/06 12:39:33 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_colors(t_game *game, t_textr *textr)
{
	if(!textr->ceiling || !textr->floor)
		sepuku(game, ERROR_COLOR);
	check_rgb(textr->ceiling, game, 1);
	check_rgb(textr->floor, game, 0);	
}

void	check_textures(t_game *game, t_textr *textr)
{
	if(!textr->north || !textr->south || !textr->east || !textr->west)
		sepuku(game, ERROR_TEXTURE);
	check_file(textr->north, game);
	check_file(textr->south, game);
	check_file(textr->east, game);
	check_file(textr->west, game);
	check_duplicate_text(game, textr);
}

void	check_map_content(t_game *game)
{
	int	i;
	int j;

	i = -1;
	while(game->map[++i])
	{
		j = 0;
		while(game->map[i][j++])
		{
			while(ft_is_wspace(game->map[i][j]))
				j++;
			if(!(ft_strchr("10NSEW", game->map[i][j])))
				sepuku(game, ERROR_MAP);
		}
	}
}
