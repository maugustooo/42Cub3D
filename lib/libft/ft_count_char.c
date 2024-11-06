/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:20:05 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/06 09:08:10 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup added Added
 * @{
 * @file ft_count_char.c
 * @brief Count the number of a specific character in a string
 */

#include "libft.h"

/**
 * @brief Count the number of a specific character in a string
 * 
 * @param str String to search
 * @param sep Character to search
 * @param n Number of characters to search
 * @return int Number of characters found
 */
int	ft_count_char(char *str, char sep, int n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < n)
	{
		if (str[i] == sep)
			count++;
		i++;
	}
	return (count);
}

/**@}*/