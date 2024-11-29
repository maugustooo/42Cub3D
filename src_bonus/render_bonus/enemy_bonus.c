/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:55:18 by maugusto          #+#    #+#             */
/*   Updated: 2024/11/29 15:04:15 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_enemy1_5(t_game *game, int i)
{
	double	direction_x;
	double	direction_y;
	double	magnitude;
	double	new_x;
	double	new_y;

	direction_x = game->player.x - game->enemy[i].x;
	direction_y = game->player.y - game->enemy[i].y;
	magnitude = sqrt(direction_x * direction_x + direction_y * direction_y);
	if (magnitude != 0)
	{
		direction_x /= magnitude;
		direction_y /= magnitude;
	}
	new_x = game->enemy[i].x + direction_x * 0.04;
	new_y = game->enemy[i].y + direction_y * 0.04;
	if (is_path_clear(game, i))
	{
		game->enemy[i].x = new_x;
		game->enemy[i].y = new_y;
	}
}

void	check_enemy(t_game *game, int i)
{
	if (!game->enemy[i].died && !game->enemy[i].attacking)
	{
		if (is_path_clear(game, i))
		{
			check_enemy1_5(game, i);
			game->enemy[i].moving = true;
		}
		else
			game->enemy[i].moving = false;
	}
}

void	sort_enemies_by_distance(t_game *game)
{
	int		i;
	int		j;
	double	dist1;
	double	dist2;
	t_enemy	temp;

	i = -1;
	while (++i < game->enemy_count - 1)
	{
		j = 0;
		while (j < game->enemy_count - i - 1)
		{
			dist1 = pow(game->enemy[j].x - game->player.x, 2)
				+ pow(game->enemy[j].y - game->player.y, 2);
			dist2 = pow(game->enemy[j + 1].x - game->player.x, 2)
				+ pow(game->enemy[j + 1].y - game->player.y, 2);
			if (dist1 < dist2)
			{
				temp = game->enemy[j];
				game->enemy[j] = game->enemy[j + 1];
				game->enemy[j + 1] = temp;
			}
			j++;
		}
	}
}

void	render_enemy(t_game *game, int i, t_render *render)
{
	int				x;
	int				y;
	unsigned int	color;

	x = render->start_x - 1;
	while (++x < render->end_x)
	{
		render->tex_x = calculate_tex_x(render, x);
		if (should_render_pixel(game, i, x))
		{
			y = render->start_y - 1;
			while (++y < render->end_y)
			{
				calculate_enemy_tex(game, render, y, i);
				color = get_color(game, game->enemy[i].curr_frame
						* game->enemy[i].frame_width + render->tex_x + 2,
						(render->tex_y + 2) + render->sprite_line_offset, ENEM);
				if (color != 0x00FF12)
					put_pixel(game, x, y, color);
			}
			game->enemy_near = true;
		}
		else
			game->enemy_near = false;
	}
}

void	handle_enemy(t_game *game)
{
	int			i;
	t_render	render;

	i = 0;
	sort_enemies_by_distance(game);
	while (i < game->enemy_count)
	{
		check_enemy(game, i);
		enemy_math(game, i, &render);
		render_enemy(game, i, &render);
		i++;
	}
}
