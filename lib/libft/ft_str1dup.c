/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str1dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:17:13 by maugusto          #+#    #+#             */
/*   Updated: 2024/11/06 09:18:24 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup added Added
 * @{
 * @file ft_str1dup.c
 * @brief Duplicate a string
*/

#include "libft.h"

/**
 * @brief Duplicate a string
 * 
 * @param s String
 * @param len Length to duplicate
 * @return char* New string
*/
char	*ft_str1dup(char *s, int len)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!str)
		return (0);
	while (i <= len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**@} */