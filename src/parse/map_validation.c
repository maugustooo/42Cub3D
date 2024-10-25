/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:29:59 by gude-jes          #+#    #+#             */
/*   Updated: 2024/10/25 12:32:21 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_textures(t_game *game)
{
	int i;

	i = -1;
	while(game->textures[++i])
	{
		
	}
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
			if(!(ft_strchr("1ONSEW", game->map[i])))
				sepuku(game);
		}
	}
}
