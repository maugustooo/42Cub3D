/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:55:00 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/06 10:54:42 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_rgb(char *color, t_game *game, int type)
{
	char	**rgb;
	int 	i;

	rgb = ft_split(color, ',');
	if(!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		sepuku(game, ERROR_COLOR);
	if((ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255)
		|| (ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[1]) > 255)
		|| (ft_atoi(rgb[2]) < 0 || ft_atoi(rgb[2]) > 255))
		sepuku(game, ERROR_COLOR);
	i = -1;
	while (++i < 3)
	{
		if(type == 0)
			game->rgb_floor[i] = ft_atoi(rgb[i]);
		else
			game->rgb_sky[i] = ft_atoi(rgb[i]);
	}
	i = 0;
	while(rgb[i])
		free(rgb[i++]);
	free(rgb);
}
