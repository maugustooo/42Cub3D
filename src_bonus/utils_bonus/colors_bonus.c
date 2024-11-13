/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:55:00 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/13 00:29:32 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_rgb(char **rgb)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i])
			free(rgb[i]);
		i++;
	}
	free(rgb);
}
void	check_rgb(char *color, t_game *game, int type)
{
	char **rgb;
	int 	i;

	i = -1;
	rgb = ft_split(color, ',');
	if(!rgb || !rgb[0] || !rgb[1] || !rgb[2])
	{
		free_rgb(rgb);
		sepuku(game, ERROR_COLOR);
	}
	if((ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255)
		|| (ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[1]) > 255)
		|| (ft_atoi(rgb[2]) < 0 || ft_atoi(rgb[2]) > 255))
	{
		free_rgb(rgb);
		sepuku(game, ERROR_COLOR);
	}
	while (++i < 3)
	{
		if(type == 0)
			game->rgb_floor[i] = ft_atoi(rgb[i]);
		else
			game->rgb_sky[i] = ft_atoi(rgb[i]);
	}
	free_rgb(rgb);
}
