/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:05:24 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/06 12:39:42 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_extension(char *file)
{
	if (ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4) != 0)
		sepuku(NULL, ERROR_FILE);
}

bool    is_dir(char *file)
{
    int     fd;
    bool    ret;

    fd = open(file, O_DIRECTORY);
    if(fd < 0)
        ret = false;
    else
        ret = true;
    close(fd);
    return (ret);
}

bool    is_xpm(char *file)
{
    if (ft_strncmp(file + ft_strlen(file) - 4, ".xpm", 4) == 0)
        return (true);
    return (false);
}

void	check_duplicate_text(t_game *game, t_textr *textr)
{
	if(textr->north == textr->south || textr->north == textr->east
		|| textr->north == textr->west)
		sepuku(game, ERROR_TEXTURE);
	if(textr->south == textr->east || textr->south == textr->west)
		sepuku(game, ERROR_TEXTURE);
	if(textr->east == textr->west)
		sepuku(game, ERROR_TEXTURE);
}

void    check_file(char *file, t_game *game)
{
    int fd;

    if(is_dir(file))
        sepuku(game, ERROR_TEXTURE);
    fd = open(file, O_RDONLY);
    if (fd < 0)
        sepuku(game, ERROR_FILE);
    if (!is_xpm(file))
        sepuku(game, ERROR_TEXTURE);
    close(fd);
}
