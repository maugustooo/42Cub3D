/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:55:00 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/05 11:54:47 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @file colors_bonus.c
 * @brief Check and create colors
*/

#include "cub3d_bonus.h"

/**
 * @brief Free the rgb values
 * 
 * @param rgb RGB values
 */
void	free_rgb(char **rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i])
			free(rgb[i]);
		i++;
	}
	free(rgb);
}

/**
 * @brief Check the rgb values
 * 
 * @param color Color to check
 * @param game Pointer to the game structure
 * @param type Type of color
 */
void	check_rgb(char *color, t_game *game, int type)
{
	char	**rgb;
	int		i;

	i = -1;
	rgb = ft_split(color, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
	{
		free_rgb(rgb);
		sepuku(game, ERROR_COLOR);
	}
	if ((ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255)
		|| (ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[1]) > 255)
		|| (ft_atoi(rgb[2]) < 0 || ft_atoi(rgb[2]) > 255))
	{
		free_rgb(rgb);
		sepuku(game, ERROR_COLOR);
	}
	while (++i < 3)
	{
		if (type == 0)
			game->rgb_floor[i] = ft_atoi(rgb[i]);
		else
			game->rgb_sky[i] = ft_atoi(rgb[i]);
	}
	free_rgb(rgb);
}

/**
 * @brief Create a rgb object
 * 
 * @param t Transparency
 * @param r Red
 * @param g Green
 * @param b Blue
 * @return int Return the color
 */
int	create_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/**
 * @brief Get the color of a pixel
 * 
 * @param game Pointer to the game structure
 * @param x X coordinate of the pixel
 * @param y y coordinate of the pixel
 * @param i index of the image
 * @return int return the color of the pixel
 */
int	get_color(t_game *game, int x, int y, int i)
{
	return (*(int *)(game->img[i].addr
		+ (y * game->img[i].line_len + x * (game->img[i].bpp / 8))));
}

/**@} */