/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:04:36 by maugusto          #+#    #+#             */
/*   Updated: 2024/11/06 09:13:14 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup added Added
 * @{
 * @file ft_strclen.c
 * @brief Get the length of a string until a character
*/

#include "libft.h"

/**
 * @brief Get the length of a string until a character
 * 
 * @param str String
 * @param c Character
 * @return int Length
*/
int	ft_strclen(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while ((str[i] && str[i] != c))
		i++;
	return (i);
}

/**@} */