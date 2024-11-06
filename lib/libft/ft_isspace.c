/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:17:11 by maugusto          #+#    #+#             */
/*   Updated: 2024/11/06 09:09:55 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup added Added
 * @{
 * @file ft_isspace.c
 * @brief Check if the character is a space
*/

#include "libft.h"

/**
 * @brief 
 * 
 * @param c Character to check
 * @return int 1 if it is a space, 0 otherwise
*/
int	ft_isspace(char c)
{
	return (c == ' ');
}

/**@} */