/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_math_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:48:26 by maugusto          #+#    #+#             */
/*   Updated: 2024/12/02 10:24:46 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	calculate_enemy_tex(t_game *game, t_render *render, int y, int i)
{
	render->d = (y - render->vmovescreen) * 256 - SCREEN_HEIGHT * 128
		+ (int)render->sprite_height * 128;
	render->tex_y = ((render->d * game->enemy[i].frame_height)
			/ (int)render->sprite_height) / 256;
	render->sprite_line_offset = game->enemy[i].sprite_line
		* game->enemy[i].frame_height;
	if (game->enemy[i].die)
		render->sprite_line_offset += 22;
	if (game->enemy[i].die && game->enemy[i].sprite_line == 10)
		render->sprite_line_offset -= 2;
	if (game->enemy[i].died)
		render->sprite_line_offset += 22;
	if (game->enemy[i].sprite_line == 8)
		render->sprite_line_offset += 16;
	if (game->enemy[i].sprite_line == 9)
		render->sprite_line_offset += 18;
	if (game->enemy[i].sprite_line == 10 && !game->enemy[i].die)
		render->sprite_line_offset += 20;
}

int	calculate_tex_x(t_render *render, int x)
{
	return ((int)(256 * (x - (-(int)render->sprite_width / 2
				+ render->screen_x)) * 64
		/ (int)render->sprite_width) / 256);
}

int	should_render_pixel(t_game *game, int i, int x)
{
	return (-game->enemy[i].transform_y > 0 && x > 0 && x < SCREEN_WIDTH
		&& - game->enemy[i].transform_y < game->z_buffer[x]);
}

void	calculate_tranform(t_game *game, int i)
{
	double	inv_det;

	inv_det = 1.0 / (game->plane_x * game->player.dir_y - game->plane_y
			* game->player.dir_x);
	game->enemy[i].transform_x = inv_det * (game->player.dir_y
			* (game->player.x - game->enemy[i].x) - game->player.dir_x
			* (game->player.y - game->enemy[i].y));
	game->enemy[i].transform_y = inv_det * (-game->plane_y
			* (game->player.x - game->enemy[i].x) + game->plane_x
			* (game->player.y - game->enemy[i].y));
}

void	enemy_math(t_game *game, int i, t_render *render)
{
	calculate_tranform(game, i);
	render->vmovescreen = (int)(-200 / game->enemy[i].transform_y);
	render->screen_x = (int)((SCREEN_WIDTH / 2) * (1
				+ game->enemy[i].transform_x / game->enemy[i].transform_y));
	render->sprite_height = fabs((SCREEN_HEIGHT / game->enemy[i].transform_y));
	render->sprite_width = render->sprite_height;
	render->sprite_height /= 1.5;
	render->sprite_width /= 1.5;
	render->start_x = (int)-render->sprite_width / 2 + render->screen_x;
	if (render->start_x < 0)
		render->start_x = 0;
	render->end_x = (int)render->sprite_width / 2 + render->screen_x;
	if (render->end_x >= SCREEN_WIDTH)
		render->end_x = SCREEN_WIDTH - 1;
	render->start_y = -(int)render->sprite_height / 2 + SCREEN_HEIGHT
		/ 2 + render->vmovescreen;
	if (render->start_y < 0)
		render->start_y = 0;
	render->end_y = SCREEN_HEIGHT / 2 + (int)render->sprite_height
		/ 2 + render->vmovescreen;
	if (render->end_y >= SCREEN_HEIGHT)
		render->end_y = SCREEN_HEIGHT - 1;
}
