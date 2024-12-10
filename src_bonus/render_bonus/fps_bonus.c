/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:59:05 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/10 10:23:15 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file fps_bonus.c
 * @brief Handle the FPS counter.
 */

#include "cub3d_bonus.h"

/**
 * @brief Put a pixel to the image.
 * 
 * @param game Pointer to the game structure.
 * @param x X position.
 * @param y Y position.
 * @param color Color of the pixel.
*/
void	put_pixel_to_image(t_game *game, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	pixel = (game->fps_img.addr + (y * game->fps_img.line_len
				+ x * (game->fps_img.bpp / 8)));
	*(int *)pixel = color;
}

/**
 * @brief Draw a filled rectangle to the image.
 * 
 * @param game Pointer to the game structure.
 * @param x X position.
 * @param y Y position.
 * @param width Width of the rectangle.
*/
void	draw_filled_rectangle(t_game *game, int x, int y,
		int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < width)
		{
			put_pixel_to_image(game, x + j, y + i, 0x000000);
			j++;
		}
		i++;
	}
}

/**
 * @brief Draw a character to the image.
 * @param game Pointer to the game structure.
 * @param c Character to draw.
 * @param x X position.
 * @param y Y position.
*/
void	draw_char_to_image(t_game *game, char c, int x, int y)
{
	int		row;
	int		col;
	uint8_t	row_data;

	if (!ft_isascii(c))
		return ;
	row = 0;
	while (row < 8)
	{
		row_data = game->bitmap[(int)c][row];
		col = 0;
		while (col < 8)
		{
			if (row_data & (1 << (7 - col)))
				put_pixel_to_image(game, x + col, y + row, 0xFFFFFF);
			col++;
		}
		row++;
	}
}

/**
 * @brief Update the FPS counter.
 * @param game Pointer to the game structure.
*/
void	update_fps(t_game *game)
{
	struct timeval	current_time;
	double			delta_time;

	gettimeofday(&current_time, NULL);
	delta_time = (current_time.tv_sec - game->fps.last_time.tv_sec)
		+ (current_time.tv_usec - game->fps.last_time.tv_usec) / 1000000.0;
	game->fps.elapsed_time += delta_time;
	game->fps.frame_count++;
	game->fps.last_time = current_time;
	if (game->fps.elapsed_time >= 1.0)
	{
		game->fps.fps = game->fps.frame_count;
		game->fps.frame_count = 0;
		game->fps.elapsed_time = 0.0;
	}
}

/**
 * @brief Render the FPS counter.
 * @param game Pointer to the game structure.
*/
void	render_fps(t_game *game)
{
	char	fps_str[10];
	int		x;
	int		y;
	int		i;

	x = 5;
	y = 5;
	i = 0;
	snprintf(fps_str, sizeof(fps_str), "FPS: %d", game->fps.fps);
	draw_filled_rectangle(game, x, y, 8 * ft_strlen(fps_str));
	while (fps_str[i] != '\0')
	{
		draw_char_to_image(game, fps_str[i], x + i * 8, y);
		i++;
	}
}

/**@} */