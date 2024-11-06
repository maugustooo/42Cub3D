/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:22:35 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/06 11:57:00 by gude-jes         ###   ########.fr       */
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

void	check_order(char *file, t_game *game)
{
	int		fd;
	int		map_start;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		sepuku(game, ERROR_FILE);
	tmp = get_next_line(fd);
	while(tmp != NULL)
	{
		while(ft_is_wspace(*tmp) && *tmp != '\n')
			tmp++;
		if(ft_isdigit(*tmp))
			map_start = 1;
		else if (is_texture(tmp) && map_start == 1)
		{
			free(tmp);
			close(fd);
			sepuku(game, ERROR_ORDER);
		}
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
}
