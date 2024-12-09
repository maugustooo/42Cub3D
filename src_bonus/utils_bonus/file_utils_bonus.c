/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:05:24 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/05 11:59:25 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file file_utils_bonus.c
 * @brief Checks for file extensions and directories
*/

#include "cub3d_bonus.h"

/**
 * @brief Check if the file has the .cub extension
 * 
 * @param file The file to check
 */
void	check_extension(char *file)
{
	if (ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4) != 0)
		sepuku(NULL, ERROR_FILE);
}

/**
 * @brief Check if the file is a directory
 * 
 * @param file The file to check
 * @return true If the file is a directory
 * @return false If the file is not a directory
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
 * @param file The file to check
 * @return true If the file is a xpm file
 * @return false If the file is not a xpm file
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
 * @param game The game structure
 */
void	check_duplicate_text(t_game *game)
{
	if (game->textr.north == game->textr.south || game->textr.north
		== game->textr.east || game->textr.north == game->textr.west
		|| game->textr.north == game->textr.door || game->textr.north
		== game->textr.enemy)
		sepuku(game, ERROR_TEXTURE);
	if (game->textr.south == game->textr.east
		|| game->textr.south == game->textr.west || game->textr.south
		== game->textr.door || game->textr.south == game->textr.enemy)
		sepuku(game, ERROR_TEXTURE);
	if (game->textr.east == game->textr.west || game->textr.east
		== game->textr.door || game->textr.east == game->textr.enemy)
		sepuku(game, ERROR_TEXTURE);
	if (game->textr.west == game->textr.door
		|| game->textr.west == game->textr.enemy)
		sepuku(game, ERROR_TEXTURE);
	if (game->textr.door == game->textr.enemy)
		sepuku(game, ERROR_TEXTURE);
}

/**
 * @brief Check if the file is a valid texture file
 * 
 * @param file The file to check
 * @param game The game structure
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