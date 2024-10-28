/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:51:55 by gude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 10:02:31 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_textures2(int fd, t_game *game,  t_textr *textures)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		if (tmp[0] == 'N' && tmp[1] == 'O')
			textures->north = ft_strdup(tmp + 2);
		else if (tmp[0] == 'S' && tmp[1] == 'O')
			textures->south = ft_strdup(tmp + 2);
		else if (tmp[0] == 'W' && tmp[1] == 'E')
			textures->west = ft_strdup(tmp + 2);
		else if (tmp[0] == 'E' && tmp[1] == 'A')
			textures->east = ft_strdup(tmp + 2);
		else if (tmp[0] == 'F' && tmp[0] == ' ')
			textures->floor = ft_strdup(tmp + 1);
		else if (tmp[0] == 'C' && tmp[0] == ' ')
			textures->ceiling = ft_strdup(tmp + 1);
		free(tmp);
		i++;
	}
	game->mapstart = i;
}

void	read_textures(char *file, t_game *game, t_textr *textures)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		sepuku(game);
	read_textures2(fd, game, textures);
	close(fd);
}
