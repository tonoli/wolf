/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 23:27:55 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/04 19:19:02 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void init_val(t_env *e) {
	e->me_x = 14;
	e->me_y = 17;
	e->me_dirx = -1;
	e->me_diry = 0;
	e->mapx = 0;
	e->mapy = 0;
	e->planeX = 0;
	e->planeY = 0;
	e->x = 0;
	e->time = 0;
	e->oldTime = 0;
	e->hit = 0;
}

void		init(t_env *e)
{
	e->mlx = mlx_init();
	init_val(e);
	e->win = mlx_new_win(e->mlx, -1, -1, WIN_W, WIN_H, WIN_NAME);
	e->img = mlx_new_img(e->mlx, WIN_W, WIN_H, BLACK);
	e->img_data = (int *)mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
}
