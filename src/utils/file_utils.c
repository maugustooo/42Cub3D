/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:05:24 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/26 10:37:33 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file file_utils.c
 * @brief File utilities
*/

#include "cub3d.h"

/**
 * @brief Check if the file has the correct extension
 * @param file File to be checked
 */
void	check_extension(char *file)
{
	if (ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4) != 0)
		sepuku(NULL, ERROR_FILE);
}

/**
 * @brief Check if the file is a directory
 * 
 * @param file File to be checked
 * @return true Is a directory
 * @return false Is not a directory
 */
bool	is_dir(char *file)
{
	int		fd;
	bool	ret;

	fd = open(file, O_DIRECTORY);
	if (fd < 0)
		ret = false;
	else
	{
		ret = true;
		close(fd);
	}
	return (ret);
}

/**
 * @brief Check if the file is a xpm file
 * 
 * @param file File to be checked
 * @return true Is a xpm file
 * @return false Is not a xpm file
 */
bool	is_xpm(char *file)
{
	if (ft_strncmp(file + ft_strlen(file) - 4, ".xpm", 4) == 0)
		return (true);
	return (false);
}

/**
 * @brief Check if the textures are duplicated
 * 
 * @param game Struct with game information
*/
void	check_duplicate_text(t_game *game)
{
	if (game->textr.north == game->textr.south || game->textr.north
		== game->textr.east || game->textr.north == game->textr.west)
		sepuku(game, ERROR_TEXTURE);
	if (game->textr.south == game->textr.east
		|| game->textr.south == game->textr.west)
		sepuku(game, ERROR_TEXTURE);
	if (game->textr.east == game->textr.west)
		sepuku(game, ERROR_TEXTURE);
}

/**
 * @brief Check if the file is a valid texture
 * 
 * @param file File to be checked
 * @param game Struct with game information
*/
void	check_file(char *file, t_game *game)
{
	int	fd;

	if (is_dir(file))
		sepuku(game, ERROR_TEXTURE);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		sepuku(game, ERROR_FILE);
	else
		close(fd);
	if (!is_xpm(file))
		sepuku(game, ERROR_TEXTURE);
}

/**@} */