/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:38:09 by gude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 10:26:14 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_textr *init_textr(void)
{
	t_textr	*textr;

	textr = malloc((1) * sizeof(t_textr));
	if (!textr)
		sepuku(NULL);
	ft_memset(textr, 0, sizeof(t_textr));
	return (textr);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc((1) * sizeof(t_game));
	if (!game)
		sepuku(game);
	ft_memset(&game, 0, sizeof(t_game));
	ft_memset(&game->img, 0, sizeof(t_img));
	game->mlx_ptr = mlx_init();
	return (game);
}