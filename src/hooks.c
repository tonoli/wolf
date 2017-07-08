/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:01:51 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/08 03:20:01 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void	rotation(t_env *e, int key)
{
	double old_dirx;
	double old_planex;
	double rot_sp;

	rot_sp = 0.05;
	if (key == LEFT)
	{
		old_dirx = e->me_dirx;
		e->me_dirx = e->me_dirx * cos(rot_sp) - e->me_diry * sin(rot_sp);
		e->me_diry = old_dirx * sin(rot_sp) + e->me_diry * cos(rot_sp);
		old_planex = e->planex;
		e->planex = e->planex * cos(rot_sp) - e->planey * sin(rot_sp);
		e->planey = old_planex * sin(rot_sp) + e->planey * cos(rot_sp);
	}
	if (key == RIGHT)
	{
		old_dirx = e->me_dirx;
		e->me_dirx = e->me_dirx * cos(-rot_sp) - e->me_diry * sin(-rot_sp);
		e->me_diry = old_dirx * sin(-rot_sp) + e->me_diry * cos(-rot_sp);
		old_planex = e->planex;
		e->planex = e->planex * cos(-rot_sp) - e->planey * sin(-rot_sp);
		e->planey = old_planex * sin(-rot_sp) + e->planey * cos(-rot_sp);
	}
}

static void	motion(t_env *e, int key)
{
	if (key == UP)
	{
		if (e->map[(int)(e->me_x + e->me_dirx * e->speed)][(int)e->me_y] != '1')
			e->me_x += e->me_dirx * e->speed;
		if (e->map[(int)e->me_x][(int)(e->me_y + e->me_diry * e->speed)] != '1')
			e->me_y += e->me_diry * e->speed;
	}
	else if (key == DOWN)
	{
		if (e->map[(int)(e->me_x - e->me_dirx * e->speed)][(int)e->me_y] != '1')
			e->me_x -= e->me_dirx * e->speed;
		if (e->map[(int)e->me_x][(int)(e->me_y - e->me_diry * e->speed)] != '1')
			e->me_y -= e->me_diry * e->speed;
	}
	else if (key == LEFT || key == RIGHT)
		rotation(e, key);
	fill_img(e);
}

int			key_hook(int key, t_env *e)
{
	if (key == ESC_KEY)
		kill_program();
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		motion(e, key);
	return (0);
}
