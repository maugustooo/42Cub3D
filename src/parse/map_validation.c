/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:29:59 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/04 18:19:09 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	check_colors(t_game *game, t_textr *textr)
// {
	
// }

void	check_textures(t_game *game, t_textr *textr)
{
	if(!textr->north || !textr->south || !textr->east || !textr->west)
		sepuku(game);
	check_file(textr->north);
	check_file(textr->south);
	check_file(textr->east);
	check_file(textr->west);
}

void	check_map_content(t_game *game)
{
	int	i;
	int j;

	i = -1;
	while(game->map[++i])
	{
		j = -1;
		while(game->map[i][++j])
		{
			while(ft_isempty(game->map[i][j]))
				j++;
			if(!(ft_strchr("1ONSEW", game->map[i][j])))
				sepuku(game);
		}
	}
}
