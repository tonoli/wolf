/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:20:59 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/08 15:51:58 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void	where_draw(t_env *e)
{
	e->lineheight = abs((int)(WIN_H / e->perpwalldist));
	e->draw_start = -e->lineheight / e->wh + WIN_H / 2;
	e->draw_end = e->lineheight / 2 + WIN_H / 2;
	if (e->draw_start < 0)
		e->draw_start = 0;
	if (e->draw_end >= WIN_H)
		e->draw_end = WIN_H - 1;
}

int		draw_wall(t_env *e)
{
	int color;

	if (e->side == 0 && e->raydirx >= 0)
		color = MURA;
	else if (e->side == 0 && e->raydirx < 0)
		color = MURB;
	else if (e->side == 1 && e->raydiry >= 0)
		color = MURC;
	else
		color = MURD;
	return (color);
}

void	draw_line(t_env *e)
{
	int y;
	int color;

	y = -1;
	while (++y < WIN_H)
	{
		if (y < e->draw_start)
			color = SKY;
		else if (y > e->draw_end)
			color = BROWN;
		else
		{
			if (e->hit == 1)
				color = draw_wall(e);
		}
		e->img_data[y * WIN_W + e->x] = color;
	}
}

void	fill_img(t_env *e)
{
	e->x = -1;
	while (++e->x < WIN_W)
	{
		raycast(e);
		where_draw(e);
		draw_line(e);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
