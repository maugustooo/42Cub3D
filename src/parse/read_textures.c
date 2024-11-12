/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:51:55 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/12 11:09:47 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_dup2(int *arr, t_game *game)
{
	int	i;

	i = 0;
	while(i < 6)
	{
		if (arr[i] > 1)
			sepuku(game, ERROR_DUP);
		i++;
	}
}

void	check_dup(int fd, t_game *game, int *arr)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while(tmp != NULL)
	{
		tmp = return_no_extra_spaces(tmp);
		if (tmp[0] == 'N' && tmp[1] == 'O')
			arr[0]++;
		else if (tmp[0] == 'S' && tmp[1] == 'O')
			arr[1]++;
		else if (tmp[0] == 'W' && tmp[1] == 'E')
			arr[2]++;
		else if (tmp[0] == 'E' && tmp[1] == 'A')
			arr[3]++;
		else if (tmp[0] == 'F' && tmp[1] == ' ')
			arr[4]++;
		else if (tmp[0] == 'C' && tmp[1] == ' ')
			arr[5]++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	check_dup2(arr, game);
}

void	read_textures2(int fd, t_game *game)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = get_next_line(fd);
	while (tmp != NULL && game->mapflag == false)
	{
		tmp = return_no_extra_spaces(tmp);	
		if (tmp[0] == 'N' && tmp[1] == 'O')
			game->textr.north = ft_strndup(&tmp[2], ft_strclen(&tmp[2], '\n'));
		else if (tmp[0] == 'S' && tmp[1] == 'O')
			game->textr.south = ft_strndup(&tmp[2], ft_strclen(&tmp[2], '\n'));
		else if (tmp[0] == 'W' && tmp[1] == 'E')
			game->textr.west = ft_strndup(&tmp[2], ft_strclen(&tmp[2], '\n'));
		else if (tmp[0] == 'E' && tmp[1] == 'A')
			game->textr.east = ft_strndup(&tmp[2], ft_strclen(&tmp[2], '\n'));
		else if (tmp[0] == 'F' && tmp[1] != ' ')
			game->textr.floor = ft_strndup(&tmp[1] + 1, ft_strclen(&tmp[1] + 1, '\n'));
		else if (tmp[0] == 'C' && tmp[1] != ' ')
			game->textr.ceiling = ft_strndup(&tmp[1] + 1, ft_strclen(&tmp[1] + 1, '\n'));
		free(tmp);
		tmp = get_next_line(fd);
		i++;
		check_text_content(game, i);
	}
	while(tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
}

void	read_textures(char *file, t_game *game)
{
	int		fd;
	int		arr[6];
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		sepuku(game, ERROR_FILE);
	game->mapflag = false;
	while(i < 6)
		arr[i++] = 0;
	check_dup(fd, game, arr);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		sepuku(game, ERROR_FILE);
	read_textures2(fd, game);
	close(fd);
}
