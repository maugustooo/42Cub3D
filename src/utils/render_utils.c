/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:49:42 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/26 10:44:23 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file render_utils.c
 * @brief 
*/

#include "cub3d.h"

/**
 * @brief Get the color object
 * @param game Struct with all game information
 * @param x X coordinate
 * @param y Y coordinate
 * @param i Number of the image
 * @return int Color of the pixel
*/
int	get_color(t_game *game, int x, int y, int i)
{
	return (*(int *)(game->img[i].addr
		+ (y * game->img[i].line_len + x * (game->img[i].bpp / 8))));
}

/**
 * @brief Put a pixel in the screen
 * @param game Struct with all game information
 * @param x X coordinate
 * @param y Y coordinate
 * @param color Color of the pixel
*/
void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > game->screen_height - 1 || x < 0
		|| x > game->screen_width - 1)
		return ;
	pixel = (game->img[4].addr + (y * game->img[4].line_len
				+ x * (game->img[4].bpp / 8)));
	*(int *)pixel = color;
}

/**@} */