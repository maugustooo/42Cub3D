/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:10:20 by maugusto          #+#    #+#             */
/*   Updated: 2024/11/06 09:07:35 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup added Added
 * @file ft_find_c.c
 * @brief Checks if character c is in set
*/

#include "libft.h"

/**
 * @brief Checks if character c is in set
 * 
 * @param c Character to search
 * @param set String to be searched
 * @return int 1 if found | 0 if not
 */
int	ft_find_c(char c, char const *set)
{
	size_t	i;

	i = 0;
	if (!set || !set[0])
		return (0);
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**@}*/