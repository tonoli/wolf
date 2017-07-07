/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 03:10:27 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/06 22:05:03 by itonoli-         ###   ########.fr       */
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
	e->mapx = (int)e->rayPosX;
	e->mapy = (int)e->rayPosY;
	e->deltaDistX = sqrt(1 + (e->rayDirY * e->rayDirY) / (e->rayDirX * e->rayDirX));
	e->deltaDistY = sqrt(1 + (e->rayDirX * e->rayDirX) / (e->rayDirY * e->rayDirY));
}

static void step(t_env *e)
{
	if (e->rayDirX < 0)
	{
		e->stepX = -1;
		e->sideDistX = (e->rayPosX - e->mapx) * e->deltaDistX;
	}
	else
	{
		e->stepX = 1;
		e->sideDistX = (e->mapx + 1.0 - e->rayPosX) * e->deltaDistX;
	}
	if (e->rayDirY < 0)
	{
		e->stepY = -1;
		e->sideDistY = (e->rayPosY - e->mapy) * e->deltaDistY;
	}
	else
	{
		e->stepY = 1;
		e->sideDistY = (e->mapy + 1.0 - e->rayPosY) * e->deltaDistY;
	}
}

static void dda(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->sideDistX < e->sideDistY)
		{
			e->sideDistX += e->deltaDistX;
			e->mapx += e->stepX;
			e->side = 0;
		}
		else
		{
			e->sideDistY += e->deltaDistY;
			e->mapy += e->stepY;
			e->side = 1;
		}
		e->hit = (e->map[e->mapx][e->mapy] > 0) ? 1 : 0;
	}
	e->perpWallDist = (e->side == 0) ?
	(e->mapx - e->rayPosX + (1 - e->stepX) / 2) / e->rayDirX :
	(e->mapy - e->rayPosY + (1 - e->stepY) / 2) / e->rayDirY;
}

void raycast(t_env *e)
{
	compute(e);
	step(e);
	dda(e);
}
