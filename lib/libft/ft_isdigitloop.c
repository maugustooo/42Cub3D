/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigitloop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:28:36 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/06 09:12:32 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup added Added
 * @{
 * @file ft_isdigitloop.c
 * @brief Check if all characters in a string are digits
*/

#include "libft.h"

/**
 * @brief Check if all characters in a string are digits.
 * @param str The string to check.
 * @return int 1 if all characters are digits, 0 otherwise.
*/
int	ft_isdigitloop(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**@} */