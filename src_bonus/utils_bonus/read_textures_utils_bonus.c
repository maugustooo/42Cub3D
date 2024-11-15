/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:35:54 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/15 11:12:42 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

void	check_dup_arr(int *arr, t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (arr[i] > 1)
		{
			if(i == 7)
			{
				if (arr[i] > 4)
					sepuku(game, ERROR_DUP);
			}
			sepuku(game, ERROR_DUP);
		}
		i++;
	}
}

void	put_textures(t_game *game, char *tmp)
{
	if (tmp[0] == 'N' && tmp[1] == 'O')
		game->textr.north = ft_strndup(&tmp[2], ft_strclen(&tmp[2], '\n'));
	else if (tmp[0] == 'S' && tmp[1] == 'O')
		game->textr.south = ft_strndup(&tmp[2], ft_strclen(&tmp[2], '\n'));
	else if (tmp[0] == 'W' && tmp[1] == 'E')
		game->textr.west = ft_strndup(&tmp[2], ft_strclen(&tmp[2], '\n'));
	else if (tmp[0] == 'E' && tmp[1] == 'A')
		game->textr.east = ft_strndup(&tmp[2], ft_strclen(&tmp[2], '\n'));
	else if (tmp[0] == 'F' && tmp[1] != ' ')
		game->textr.floor = ft_strndup(&tmp[1], ft_strclen(&tmp[1], '\n'));
	else if (tmp[0] == 'C' && tmp[1] != ' ')
		game->textr.ceiling = ft_strndup(&tmp[1], ft_strclen(&tmp[1], '\n'));
	else if (tmp[0] == 'D' && tmp[1] != ' ')
		game->textr.door = ft_strndup(&tmp[1], ft_strclen(&tmp[1], '\n'));
	else if (tmp[0] == 'E' && tmp[1] == '1')
		game->textr.enemy1 = ft_strndup(&tmp[2], ft_strclen(&tmp[2], '\n'));
	else if (tmp[0] == 'E' && tmp[1] == '2')
		game->textr.enemy2 = ft_strndup(&tmp[2], ft_strclen(&tmp[2], '\n'));
	else if (tmp[0] == 'E' && tmp[1] == 'D' && tmp[2] == '1')
		game->textr.enemyd1 = ft_strndup(&tmp[3], ft_strclen(&tmp[3], '\n'));
	else if (tmp[0] == 'E' && tmp[1] == 'D' && tmp[2] == '2')
		game->textr.enemyd2 = ft_strndup(&tmp[3], ft_strclen(&tmp[3], '\n'));
}
