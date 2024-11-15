/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:18:37 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/15 11:19:52 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_duplicate_text2(t_game *game)
{
	if(game->textr.west == game->textr.door || game->textr.west == game->textr.enemy1
		|| game->textr.west == game->textr.enemy2 || game->textr.west == game->textr.enemyd1
		|| game->textr.west == game->textr.enemyd2)
		sepuku(game, ERROR_TEXTURE);
	if(game->textr.door == game->textr.enemy1 || game->textr.door
		== game->textr.enemy2 || game->textr.door == game->textr.enemyd1
		|| game->textr.door == game->textr.enemyd2)
		sepuku(game, ERROR_TEXTURE);
	if(game->textr.enemy1 == game->textr.enemy2 || game->textr.enemy1
		== game->textr.enemyd1 || game->textr.enemy1 == game->textr.enemyd2)
		sepuku(game, ERROR_TEXTURE);
	if(game->textr.enemy2 == game->textr.enemyd1 || game->textr.enemy2
		== game->textr.enemyd2)
		sepuku(game, ERROR_TEXTURE);
	if(game->textr.enemyd1 == game->textr.enemyd2)
		sepuku(game, ERROR_TEXTURE);
}
