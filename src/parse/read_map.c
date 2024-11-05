/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:17:14 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/05 12:40:14 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	count_endmap(t_game *game, int fd)
{
	int i;
	char *temp;
	
	i = 0;
	while (game->mapstart > i)
	{
		temp = get_next_line(fd);
		free(temp);
		i++;
	}
	i = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if(!ft_find_c('1', temp))
			break ;
		if(temp)
			free(temp);
		i++;
	}
	if (temp)
		free(temp);
	game->mapend = i -1;
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
	i = 0;
	while(i < game->mapend)
	{
		temp = get_next_line(fd);
		game->map[i] = ft_strdup(temp);
		free(temp);
		i++;
	}
	game->map[i] = NULL;
	int o = 0 ;
	while(game->map[o])
	{
		ft_printf("%s\n", game->map[o]);
		o++;
	}
}

void	read_map(char *file, t_game *game)
{
	int	fd;

	game->tlines = count_lines(file, game);
	if (game->tlines <= 0)
		sepuku(game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		sepuku(game);
	count_endmap(game, fd);
	game->map = ft_calloc((game->tlines - game->mapstart) + 1, sizeof(char *));
	if (!game->map)
		sepuku(game);
	close(fd);
	fd = open(file, O_RDONLY);
	fill_map(fd, game);
	close(fd);
}
