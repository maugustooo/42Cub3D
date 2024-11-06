/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:35:54 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/06 12:36:07 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_text_content(t_game *game, t_textr *textures, int i)
{
	if(textures->north && textures->south && textures->west && textures->east
		&& textures->floor && textures->ceiling && game->mapflag == false)
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
	if ((tmp[0] == 'F' && tmp[1] == ' ') || (tmp[0] == 'C' && tmp[1] == ' '))
		return (tmp);
	new = malloc(sizeof(char) * (ft_strlen(tmp) + 1));
	if (!new)
		return (NULL);
	while (tmp[i])
	{
		while(!ft_is_wspace(tmp[i]) && tmp[i])
			new[j++] = tmp[i++];
		while(ft_is_wspace(tmp[i]) && tmp[i])
			i++;
	}
	new[j] = '\0';
	free(tmp);
	return (new);
}
