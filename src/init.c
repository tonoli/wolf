/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 23:27:55 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/08 03:13:08 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void	init_val(t_env *e)
{
	e->me_x = 2;
	e->me_y = 2;
	e->me_dirx = -1;
	e->me_diry = 0;
	e->mapx = 0;
	e->mapy = 0;
	e->planex = 0;
	e->planey = 0.66;
	e->speed = 0.2;
	e->wh = 2;
}

void		init(t_env *e)
{
	e->mlx = mlx_init();
	init_val(e);
	e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, WIN_NAME);
	e->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
	e->img_data = (int *)mlx_get_data_addr(e->img, &e->bpp,
		&e->size_line, &e->endian);
}
