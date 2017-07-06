/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:01:51 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/05 22:29:45 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void rotation (t_env *e, int key)
{
	double oldDirX;
	double oldPlaneX;
	double rotSpeed;

	rotSpeed = 0.8;
	if (key == LEFT)
	{
		oldDirX = e->me_dirx;
		e->me_x = e->me_x * cos(rotSpeed) - e->me_diry * sin(rotSpeed);
		e->me_diry = oldDirX * sin(rotSpeed) + e->me_diry * cos(rotSpeed);
		oldPlaneX = e->planeX;
		e->planeX = e->planeX * cos(rotSpeed) - e->planeY * sin(rotSpeed);
		e->planeY = oldPlaneX * sin(rotSpeed) + e->planeY * cos(rotSpeed);
	}
	else
	{
		oldDirX = e->me_dirx;
		e->me_dirx = e->me_dirx * cos(-rotSpeed) - e->me_diry * sin(-rotSpeed);
		e->me_diry = oldDirX * sin(-rotSpeed) + e->me_diry * cos(-rotSpeed);
		oldPlaneX = e->planeX;
		e->planeX = e->planeX * cos(-rotSpeed) - e->planeY * sin(-rotSpeed);
		e->planeY = oldPlaneX * sin(-rotSpeed) + e->planeY * cos(-rotSpeed);
	}
}

static void motion(t_env *e,int key)
{
	if (key == UP)
	{
		if(e->map[(int)(e->me_x + e->me_dirx * e->speed)][(int)e->me_y] == 0)
			e->me_x += e->me_dirx * e->speed;
		if(e->map[(int)e->me_x][(int)(e->me_y + e->me_diry * e->speed)] == 0)
			e->me_y += e->me_diry * e->speed;
	}
	else if (key == DOWN)
	{
		if(e->map[(int)(e->me_x - e->me_dirx * e->speed)][(int)e->me_y] == 0)
			e->me_x -= e->me_dirx * e->speed;
		if(e->map[(int)e->me_x][(int)(e->me_y - e->me_diry * e->speed)] == 0)
			e->me_y -= e->me_diry * e->speed;
	}
	else if (key == LEFT || key == RIGHT)
		rotation(e, key);
}

int			key_hook(int key, t_env *env)
{
	if (key == ESC_KEY)
		kill_program();
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		motion(env, key);
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	(void)button;
	(void)e;
	return (0);
}

int			mouse_move(int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	(void)e;
	return (0);
}
