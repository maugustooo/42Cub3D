/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:51:55 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/06 11:23:26 by gude-jes         ###   ########.fr       */
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

void	read_textures2(int fd, t_game *game,  t_textr *textures)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = get_next_line(fd);
	while (tmp != NULL && game->mapflag == false)
	{
		tmp = return_no_extra_spaces(tmp);	
		if (tmp[0] == 'N' && tmp[1] == 'O')
			textures->north = ft_strndup(&tmp[2], ft_strclen(&tmp[2], '\n'));
		else if (tmp[0] == 'S' && tmp[1] == 'O')
			textures->south = ft_strndup(&tmp[2], ft_strclen(&tmp[2], '\n'));
		else if (tmp[0] == 'W' && tmp[1] == 'E')
			textures->west = ft_strndup(&tmp[2], ft_strclen(&tmp[2], '\n'));
		else if (tmp[0] == 'E' && tmp[1] == 'A')
			textures->east = ft_strndup(&tmp[2], ft_strclen(&tmp[2], '\n'));
		else if (tmp[0] == 'F' && tmp[1] == ' ')
			textures->floor = ft_strndup(&tmp[1] + 1, ft_strclen(&tmp[1] + 1, '\n'));
		else if (tmp[0] == 'C' && tmp[1] == ' ')
			textures->ceiling = ft_strndup(&tmp[1] + 1, ft_strclen(&tmp[1] + 1, '\n'));
		free(tmp);
		tmp = get_next_line(fd);
		i++;
		check_text_content(game, textures, i);
	}
}

void	read_textures(char *file, t_game *game, t_textr *textures)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		sepuku(game, ERROR_FILE);
	game->mapflag = false;
	read_textures2(fd, game, textures);
	close(fd);
}
