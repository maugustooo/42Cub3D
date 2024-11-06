/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_wspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:04:10 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/06 09:06:56 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup added Added
 * @{
 * @file ft_is_wspace.c
 * @brief Check if the character is a whitespace
*/
#include "libft.h"

/**
 * @brief Check if the character is a whitespace
 * 
 * @param c Character to check
 * @return int 1 if it is a whitespace, 0 otherwise
*/
int	ft_is_wspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

/**@}*/