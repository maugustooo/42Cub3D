/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:05:24 by gude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 11:54:51 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_extension(char *file)
{
	if (ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4) != 0)
		sepuku(NULL);
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

void    check_file(char *file)
{
    int fd;

    if(is_dir(file))
        sepuku(NULL);
    fd = open(file, O_RDONLY);
    if (fd < 0)
        sepuku(NULL);
    if (!is_xpm(file))
        sepuku(NULL);
    close(fd);
}
