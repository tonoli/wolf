/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 03:10:27 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/08 01:37:31 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void compute(t_env *e)
{
	e->cameraX = 2 * e->x / (double)WIN_W - 1;
	e->side = 0;
	e->hit = 0;
	e->rayPosX = e->me_x;
	e->rayPosY = e->me_y;
	e->rayDirX = e->me_dirx + e->planeX * e->cameraX;
	e->rayDirY = e->me_diry + e->planeY * e->cameraX;
	e->mapx = (int)e->rayPosX;
	e->mapy = (int)e->rayPosY;
	e->deltaDistX = sqrt(1 + pow(e->rayDirY / e->rayDirX, 2));
	e->deltaDistY = sqrt(1 + pow(e->rayDirX / e->rayDirY, 2));
}

static void step(t_env *e)
{
	if (e->rayDirX < 0)
	{
		e->stepX = -1;
		e->sideDistX = (e->rayPosX - (double)e->mapx) * e->deltaDistX;
	}
	else
	{
		e->stepX = 1;
		e->sideDistX = ((double)e->mapx + 1.0 - e->rayPosX) * e->deltaDistX;
	}
	if (e->rayDirY < 0)
	{
		e->stepY = -1;
		e->sideDistY = (e->rayPosY - (double)e->mapy) * e->deltaDistY;
	}
	else
	{
		e->stepY = 1;
		e->sideDistY = ((double)e->mapy + 1.0 - e->rayPosY) * e->deltaDistY;
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
		e->hit = (e->map[e->mapx][e->mapy] == '1') ? 1 : 0;
	}
	e->perpWallDist = (e->side == 0) ?
	fabs((e->mapx - e->rayPosX + (1 - e->stepX) / 2) / e->rayDirX) :
	fabs((e->mapy - e->rayPosY + (1 - e->stepY) / 2) / e->rayDirY);
	if (e->perpWallDist <= 0.05)
		e->perpWallDist = 0.05;
}

void raycast(t_env *e)
{
	compute(e);
	step(e);
	dda(e);
}
