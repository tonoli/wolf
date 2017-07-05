/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:20:59 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/04 19:34:59 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void draw_lines(t_env *e)
{
	int y;

	y = 0;
	while (y < WIN_H)
	{
		if (y < e->draw_start)
			mlx_put_pixel(e->img, e->x, y, SKY);
		if (e->draw_start < y && y < e->draw_end)
			
	}
}


void	fill_img(t_env *e)
{
	draw_lines(e);
	mlx_put_img_to_win(e->mlx, e->win, e->img, 0, 0);
}
