/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sepuku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:21:22 by gude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 10:26:27 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	freedom(t_game *game)
{
	int	i;

	i = -1;
	while(game->map[++i])
		free(game->map[i]);
	free(game->map);
}

void	sepuku(t_game *game)
{
	if(game)
		freedom(game);
	ft_printf("Error\n");	
	exit(EXIT_SUCCESS);
}