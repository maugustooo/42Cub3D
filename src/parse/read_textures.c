/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:51:55 by gude-jes          #+#    #+#             */
/*   Updated: 2024/10/25 12:17:44 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_textures2(int fd, t_game *game)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		if (tmp[0] == 'N' && tmp[1] == 'O')
			game->textures[i++] = ft_strdup(tmp + 2);
		else if (tmp[0] == 'S' && tmp[1] == 'O')
			game->textures[i++] = ft_strdup(tmp + 2);
		else if (tmp[0] == 'W' && tmp[1] == 'E')
			game->textures[i++] = ft_strdup(tmp + 2);
		else if (tmp[0] == 'E' && tmp[1] == 'A')
			game->textures[i++] = ft_strdup(tmp + 2);
		else if (tmp[0] == 'F' && tmp[0] == ' ')
			game->textures[i++] = ft_strdup(tmp + 1);
		else if (tmp[0] == 'C' && tmp[0] == ' ')
			game->textures[i++] = ft_strdup(tmp + 1);
		free(tmp);
	}
	game->textures[i] = NULL;
	game->mapstart = i + 1;
}

void	read_textures(char *file, t_game *game)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		sepuku(game);
	read_textures2(fd, game);
	close(fd);
}
