/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_nn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:11:18 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/29 08:25:28 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup added Added
 * @{
 * @file ft_strchr_nn.c
 * @brief Same as ft_strchr but does not return the null terminator.
*/

#include "libft.h"

/**
 * @brief Returns a pointer to the first occurrence of the character c 
 * in the string s.
 * @param s String to search.
 * @param c Character to find.
 * @return char* Character found or NULL if not found.
*/
char	*ft_strchr_nn(const char *s, int c)
{
	while (*s)
	{
		if (*s != '\0' && *s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

/**@} */