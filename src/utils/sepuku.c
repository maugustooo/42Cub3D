/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sepuku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:21:22 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/05 12:38:09 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	freedom(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[++i])
		free(game->map[i]);
	free(game->map);
}

int	sepuku(t_game *game)
{
	if (game->map)
		freedom(game);
	ft_printf("Error\n");	
	exit(EXIT_SUCCESS);
}
