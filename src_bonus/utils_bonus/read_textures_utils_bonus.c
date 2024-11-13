/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:35:54 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/13 01:20:58 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_text_content(t_game *game, int i)
{
	if (game->textr.north && game->textr.south && game->textr.west
		&& game->textr.east
		&& game->textr.floor && game->textr.ceiling && game->mapflag == false)
	{
		game->mapstart = i + 1;
		game->mapflag = true;
	}
}

char	*return_no_extra_spaces(char *tmp)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * (ft_strlen(tmp) + 1));
	if (!new)
		return (NULL);
	while (tmp[i])
	{
		while (!ft_is_wspace(tmp[i]) && tmp[i])
			new[j++] = tmp[i++];
		while (ft_is_wspace(tmp[i]) && tmp[i])
			i++;
	}
	new[j] = '\0';
	free(tmp);
	return (new);
}
