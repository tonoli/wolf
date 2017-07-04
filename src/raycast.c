/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 03:10:27 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/04 03:49:09 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void compute(t_env *e)
{
	//calculate ray position and direction
	e->cameraX = 2 * e->x / (double)WIN_W - 1; //x-coordinate in camera space
	e->rayPosX = e->me_x;
	e->rayPosY = e->me_y;
	e->rayDirX = e->me_dirx + e->planeX * e->cameraX;
	e->rayDirY = e->me_diry + e->planeY * e->cameraX;
}
