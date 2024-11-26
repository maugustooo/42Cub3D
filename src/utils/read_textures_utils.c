/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:35:54 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/26 10:42:35 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file read_textures_utils.c
 * @brief Read textures utils functions.
*/

#include "cub3d.h"

/**
 * @brief Check if all textures are present.
 * 
 * @param game Struct with all game information.
 * @param i Index of the line being read.
*/
void	check_text_content(t_game *game, int *i)
{
	if (game->textr.north && game->textr.south && game->textr.west
		&& game->textr.east
		&& game->textr.floor && game->textr.ceiling && game->mapflag == false)
	{
		game->mapstart = (*i) + 1;
		game->mapflag = true;
	}
}

/**
 * @brief Return a string without extra spaces.
 * 
 * @param tmp Temporary string.
 * @return char* New string without extra spaces.
*/
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

/**@} */