/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:17:14 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/05 10:27:24 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	count_endmap(t_game *game)
{
	int i;

	i = game->tlines;
	while(game->map[i] != '\n')
		i--;
	game->mapend = i;
}

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

	i = 0;
	while (i < game->mapstart)
	{
		temp = get_next_line(fd);
		free(temp);
		i++;
	}
	while(i < game->mapend)
	{
		temp = get_next_line(fd);
		game->map[i] = temp;
		free(temp);
		i++;
	}
	game->map[i] = NULL;
}

void	read_map(char *file, t_game *game)
{
	int	fd;

	game->tlines = count_lines(file, game);
	count_endmap(game);
	if (game->tlines <= 0)
		sepuku(game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		sepuku(game);
	game->map = ft_calloc((game->tlines - game->mapstart) + 1, sizeof(char *));
	if (!game->map)
		sepuku(game);
	fill_map(fd, game);
	close(fd);
}
