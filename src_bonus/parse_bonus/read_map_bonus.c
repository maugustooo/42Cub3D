/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:17:14 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/05 11:21:03 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file read_map.c
 * @brief Read the map from the file and store it in the game struct.
*/

#include "cub3d_bonus.h"

/**
 * @brief Continue counting the end of the map.
 * @param temp Temporary string to store the line.
 * @param fd File descriptor.
 * @param i Index to store the number of lines.
*/
void	count_endmap2(char *temp, int fd, int *i)
{
	while (1)
	{
		temp = get_next_line(fd);
		if (!ft_find_c('1', temp))
			break ;
		if (temp)
			free(temp);
		(*i)++;
	}
	if (temp)
		free(temp);
}

/**
 * @brief Find the end of the map.
 * @param game Struct to store the map.
 * @param fd File descriptor.
*/
void	count_endmap(t_game *game, int fd)
{
	int		i;
	char	*temp;

	i = 0;
	while (game->mapstart > i)
	{
		temp = get_next_line(fd);
		free(temp);
		i++;
	}
	count_endmap2(temp, fd, &i);
	while (temp != NULL)
	{
		temp = get_next_line(fd);
		free(temp);
	}
	game->mapend = i - game->mapstart;
}

/**
 * @brief Count the number of lines in the file.
 * @param file File to count the lines.
 * @param game Struct to store the map.
 * @return int Number of lines in the file.
*/
int	count_lines(char *file, t_game *game)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		sepuku(game, ERROR_FILE);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	free(tmp);
	close(fd);
	return (i);
}

/**
 * @brief Fill the map with the content of the file.
 * @param fd File descriptor.
 * @param game Struct to store the map.
*/
void	fill_map(int fd, t_game *game)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (i < game->mapstart)
	{
		temp = get_next_line(fd);
		free(temp);
		i++;
	}
	i = 0;
	while (i < game->mapend)
	{
		temp = get_next_line(fd);
		game->map[i] = ft_strdup(temp);
		free(temp);
		i++;
	}
	game->map[i] = NULL;
	while (temp != NULL)
	{
		temp = get_next_line(fd);
		free(temp);
	}
}

/**
 * @brief Read the map from the file and store it in the game struct.
 * @param file File to read the map from.
 * @param game Struct to store the map.
*/
void	read_map(char *file, t_game *game)
{
	int	fd;

	game->tlines = count_lines(file, game);
	if (game->tlines <= 0)
		sepuku(game, ERROR_FILE);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		sepuku(game, ERROR_FILE);
	count_endmap(game, fd);
	close(fd);
	game->map = ft_calloc((game->tlines - game->mapstart) + 1, sizeof(char *));
	if (!game->map)
		sepuku(game, ERROR_MALLOC);
	fd = open(file, O_RDONLY);
	fill_map(fd, game);
	close(fd);
}

/**@} */