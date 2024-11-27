/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:50:16 by gude-jes          #+#    #+#             */
/*   Updated: 2024/11/27 16:03:17 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_fps(t_fps *fps)
{
    gettimeofday(&fps->last_time, NULL);
    fps->frame_count = 0;
    fps->elapsed_time = 0.0;
    fps->fps = 0;
}

