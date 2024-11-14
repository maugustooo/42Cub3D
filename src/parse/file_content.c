/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:22:35 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/14 12:29:31 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_texture(char *line)
{
	int	i;

	i = 0;
	while (ft_is_wspace(line[i]))
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		return (1);
	if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		return (1);
	if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		return (1);
	if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		return (1);
	if (line[i] == 'F' && line[i + 1] == ' ')
		return (1);
	if (line[i] == 'C' && line[i + 1] == ' ')
		return (1);
	return (0);
}

void	check_order2(int fd, t_game *game)
{
	int		map_start;
	bool	flag;
	char	*tmp;
	char	*ptr;

	tmp = get_next_line(fd);
	map_start = 0;
	flag = false;
	while (tmp != NULL)
	{
		ptr = tmp;
		while (ft_is_wspace(*ptr) && *tmp != '\n')
			ptr++;
		if (ft_isdigit(*ptr) && flag == false)
			map_start = 1;
		if (is_texture(ptr) && map_start == 1 && flag == false)
			flag = true;
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	if (flag)
		sepuku(game, ERROR_ORDER);
}

void	check_random2(int fd, char *tmp)
{
	int	i;

	i = 0;
	while (tmp && (is_texture(tmp) || *tmp == '\n'))
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
	while (ft_is_wspace(tmp[i]))
		i++;
	while (tmp && ft_isdigit(tmp[i]))
	{
		free(tmp);
		tmp = get_next_line(fd);
		i = 0;
		while (tmp != NULL && ft_is_wspace(tmp[i]) && tmp[i] != '\n')
			i++;
	}
	free(tmp);
}

void	check_random(int fd, t_game *game)
{
	char	*tmp;

	tmp = get_next_line(fd);
	check_random2(fd, tmp);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		if (ft_isdigit(*tmp) || ft_isalpha(*tmp))
		{
			while (tmp != NULL)
			{
				free(tmp);
				tmp = get_next_line(fd);
			}
			free(tmp);
			sepuku(game, ERROR_ORDER);
		}
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
}

void	check_order(char *file, t_game *game)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		sepuku(game, ERROR_FILE);
	check_order2(fd, game);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		sepuku(game, ERROR_FILE);
	check_random(fd, game);
	close(fd);
}
