/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:01:51 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/03 15:21:28 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void rotation (t_env *e, int key)
{
	(void)e;
	if (key == LEFT)
	{
		//Rotate the vision to the left
	}
	else
	{
		//Rotate the vision to the right
	}
}

static void motion(t_env *e,int key)
{
	if (key == UP)
		e->me_y -= 1;
	else if (key == DOWN)
		e->me_y += 1;
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
