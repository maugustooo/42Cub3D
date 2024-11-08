/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:22:35 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/08 10:59:29 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_texture(char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (1);
	if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (1);
	if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (1);
	if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (1);
	if(line[0] == 'F' && line[1] == ' ')
		return (1);
	if(line[0] == 'C' && line[1] == ' ')
		return (1);
	return (0);
}

void check_order2(int fd, t_game *game)
{
	int		map_start;
	char	*tmp;
	char	*ptr;
	
	tmp = get_next_line(fd);
	map_start = 0;
	while(tmp != NULL)
	{
		ptr = tmp;
		while(ft_is_wspace(*ptr) && *tmp != '\n')
			ptr++;
		if(ft_isdigit(*ptr))
			map_start = 1;
		if (is_texture(ptr) && map_start == 1)
		{
			free(tmp);
			close(fd);
			sepuku(game, ERROR_ORDER);
		}
		free(tmp);
		tmp = get_next_line(fd);
	}
}

void	check_order(char *file, t_game *game)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		sepuku(game, ERROR_FILE);
	check_order2(fd, game);
	close(fd);
}
