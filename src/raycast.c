/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 03:10:27 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/08 03:13:10 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void	compute(t_env *e)
{
	e->camerax = 2 * e->x / (double)WIN_W - 1;
	e->side = 0;
	e->hit = 0;
	e->rayposx = e->me_x;
	e->rayposy = e->me_y;
	e->raydirx = e->me_dirx + e->planex * e->camerax;
	e->raydiry = e->me_diry + e->planey * e->camerax;
	e->mapx = (int)e->rayposx;
	e->mapy = (int)e->rayposy;
	e->deltadistx = sqrt(1 + pow(e->raydiry / e->raydirx, 2));
	e->deltadisty = sqrt(1 + pow(e->raydirx / e->raydiry, 2));
}

static void	step(t_env *e)
{
	if (e->raydirx < 0)
	{
		e->stepx = -1;
		e->sidedistx = (e->rayposx - (double)e->mapx) * e->deltadistx;
	}
	else
	{
		e->stepx = 1;
		e->sidedistx = ((double)e->mapx + 1.0 - e->rayposx) * e->deltadistx;
	}
	if (e->raydiry < 0)
	{
		e->stepy = -1;
		e->sidedisty = (e->rayposy - (double)e->mapy) * e->deltadisty;
	}
	else
	{
		e->stepy = 1;
		e->sidedisty = ((double)e->mapy + 1.0 - e->rayposy) * e->deltadisty;
	}
}

static void	dda(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->sidedistx < e->sidedisty)
		{
			e->sidedistx += e->deltadistx;
			e->mapx += e->stepx;
			e->side = 0;
		}
		else
		{
			e->sidedisty += e->deltadisty;
			e->mapy += e->stepy;
			e->side = 1;
		}
		e->hit = (e->map[e->mapx][e->mapy] == '1') ? 1 : 0;
	}
	e->perpwalldist = (e->side == 0) ?
	fabs((e->mapx - e->rayposx + (1 - e->stepx) / 2) / e->raydirx) :
	fabs((e->mapy - e->rayposy + (1 - e->stepy) / 2) / e->raydiry);
	if (e->perpwalldist <= 0.05)
		e->perpwalldist = 0.05;
}

void		raycast(t_env *e)
{
	compute(e);
	step(e);
	dda(e);
}
