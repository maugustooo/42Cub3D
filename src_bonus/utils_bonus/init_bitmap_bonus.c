/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bitmap_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:39:29 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/05 12:01:11 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file init_bitmap_bonus.c
 * @brief Initializes the bitmap for the fps counter
*/

#include "cub3d_bonus.h"

/**
 * @brief Continue initialization of the bitmap for the fps counter
 * 
 * @param game Pointer to the game structure
*/
void	init_bitmap5(t_game *game)
{
	game->bitmap['S'][0] = 0x3C;
	game->bitmap['S'][1] = 0x66;
	game->bitmap['S'][2] = 0x60;
	game->bitmap['S'][3] = 0x3C;
	game->bitmap['S'][4] = 0x06;
	game->bitmap['S'][5] = 0x66;
	game->bitmap['S'][6] = 0x3C;
	game->bitmap['S'][7] = 0x00;
	game->bitmap[':'][0] = 0x00;
	game->bitmap[':'][1] = 0x18;
	game->bitmap[':'][2] = 0x18;
	game->bitmap[':'][3] = 0x00;
	game->bitmap[':'][4] = 0x18;
	game->bitmap[':'][5] = 0x18;
	game->bitmap[':'][6] = 0x00;
	game->bitmap[':'][7] = 0x00;
}

/**
 * @brief Continue initialization of the bitmap for the fps counter
 * 
 * @param game Pointer to the game structure
*/
void	init_bitmap4(t_game *game)
{
	game->bitmap['9'][0] = 0x3C;
	game->bitmap['9'][1] = 0x66;
	game->bitmap['9'][2] = 0x66;
	game->bitmap['9'][3] = 0x3E;
	game->bitmap['9'][4] = 0x06;
	game->bitmap['9'][5] = 0x66;
	game->bitmap['9'][6] = 0x3C;
	game->bitmap['9'][7] = 0x00;
	game->bitmap['F'][0] = 0x7E;
	game->bitmap['F'][1] = 0x60;
	game->bitmap['F'][2] = 0x60;
	game->bitmap['F'][3] = 0x7C;
	game->bitmap['F'][4] = 0x60;
	game->bitmap['F'][5] = 0x60;
	game->bitmap['F'][6] = 0x60;
	game->bitmap['F'][7] = 0x00;
	game->bitmap['P'][0] = 0x7C;
	game->bitmap['P'][1] = 0x66;
	game->bitmap['P'][2] = 0x66;
	game->bitmap['P'][3] = 0x7C;
	game->bitmap['P'][4] = 0x60;
	game->bitmap['P'][5] = 0x60;
	game->bitmap['P'][6] = 0x60;
	game->bitmap['P'][7] = 0x00;
	init_bitmap5(game);
}

/**
 * @brief Continue initialization of the bitmap for the fps counter
 * 
 * @param game Pointer to the game structure
*/
void	init_bitmap3(t_game *game)
{
	game->bitmap['6'][0] = 0x3C;
	game->bitmap['6'][1] = 0x66;
	game->bitmap['6'][2] = 0x60;
	game->bitmap['6'][3] = 0x7C;
	game->bitmap['6'][4] = 0x66;
	game->bitmap['6'][5] = 0x66;
	game->bitmap['6'][6] = 0x3C;
	game->bitmap['6'][7] = 0x00;
	game->bitmap['7'][0] = 0x7E;
	game->bitmap['7'][1] = 0x06;
	game->bitmap['7'][2] = 0x0C;
	game->bitmap['7'][3] = 0x18;
	game->bitmap['7'][4] = 0x30;
	game->bitmap['7'][5] = 0x30;
	game->bitmap['7'][6] = 0x30;
	game->bitmap['7'][7] = 0x00;
	game->bitmap['8'][0] = 0x3C;
	game->bitmap['8'][1] = 0x66;
	game->bitmap['8'][2] = 0x66;
	game->bitmap['8'][3] = 0x3C;
	game->bitmap['8'][4] = 0x66;
	game->bitmap['8'][5] = 0x66;
	game->bitmap['8'][6] = 0x3C;
	game->bitmap['8'][7] = 0x00;
	init_bitmap4(game);
}

/**
 * @brief Continue initialization of the bitmap for the fps counter
 * 
 * @param game Pointer to the game structure
*/
void	init_bitmap2(t_game *game)
{
	game->bitmap['3'][0] = 0x3C;
	game->bitmap['3'][1] = 0x66;
	game->bitmap['3'][2] = 0x06;
	game->bitmap['3'][3] = 0x1C;
	game->bitmap['3'][4] = 0x06;
	game->bitmap['3'][5] = 0x66;
	game->bitmap['3'][6] = 0x3C;
	game->bitmap['3'][7] = 0x00;
	game->bitmap['4'][0] = 0x0C;
	game->bitmap['4'][1] = 0x1C;
	game->bitmap['4'][2] = 0x3C;
	game->bitmap['4'][3] = 0x6C;
	game->bitmap['4'][4] = 0x7E;
	game->bitmap['4'][5] = 0x0C;
	game->bitmap['4'][6] = 0x0C;
	game->bitmap['4'][7] = 0x00;
	game->bitmap['5'][0] = 0x7E;
	game->bitmap['5'][1] = 0x60;
	game->bitmap['5'][2] = 0x7C;
	game->bitmap['5'][3] = 0x06;
	game->bitmap['5'][4] = 0x06;
	game->bitmap['5'][5] = 0x66;
	game->bitmap['5'][6] = 0x3C;
	game->bitmap['5'][7] = 0x00;
	init_bitmap3(game);
}

/**
 * @brief Initializes the bitmap for the fps counter
 * 
 * @param game Pointer to the game structure
 */
void	init_bitmap(t_game *game)
{
	game->bitmap['0'][0] = 0x3C;
	game->bitmap['0'][1] = 0x66;
	game->bitmap['0'][2] = 0x6E;
	game->bitmap['0'][3] = 0x76;
	game->bitmap['0'][4] = 0x66;
	game->bitmap['0'][5] = 0x66;
	game->bitmap['0'][6] = 0x3C;
	game->bitmap['0'][7] = 0x00;
	game->bitmap['1'][0] = 0x18;
	game->bitmap['1'][1] = 0x38;
	game->bitmap['1'][2] = 0x18;
	game->bitmap['1'][3] = 0x18;
	game->bitmap['1'][4] = 0x18;
	game->bitmap['1'][5] = 0x18;
	game->bitmap['1'][6] = 0x3C;
	game->bitmap['1'][7] = 0x00;
	game->bitmap['2'][0] = 0x3C;
	game->bitmap['2'][1] = 0x66;
	game->bitmap['2'][2] = 0x06;
	game->bitmap['2'][3] = 0x1C;
	game->bitmap['2'][4] = 0x30;
	game->bitmap['2'][5] = 0x60;
	game->bitmap['2'][6] = 0x7E;
	game->bitmap['2'][7] = 0x00;
	init_bitmap2(game);
}

/**@} */