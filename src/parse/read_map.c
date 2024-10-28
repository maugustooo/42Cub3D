/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:17:14 by gude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 10:27:50 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_lines(char *file, t_game *game)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		sepuku(game);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

void	fill_map(int fd, t_game *game)
{
	int		i;
	char	*temp;

	i = -1;
	while (++i < game->tlines)
		game->map[i] = get_next_line(fd);
	temp = get_next_line(fd);
	free(temp);
	game->map[i] = NULL;
}

void	read_map(char *file, t_game *game)
{
	int	fd;

	game->tlines = count_lines(file, game) - game->mapstart;
	if (game->tlines <= 0)
		sepuku(game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		sepuku(game);
	game->map = ft_calloc(game->tlines + 1, sizeof(char *));
	if (!game->map)
		sepuku(game);
	fill_map(fd, game);
	close(fd);
}
