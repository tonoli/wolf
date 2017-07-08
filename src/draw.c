/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:20:59 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/06 22:29:52 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void where_draw(t_env *e)
{
	e->lineHeight = fabs(WIN_H / e->perpWallDist);
	if((e->draw_start = -e->lineHeight / e->wh + WIN_H / 2) < 0)
		e->draw_start = 0;
	if((e->draw_end = e->lineHeight / 2 + WIN_H / 2) >= WIN_H)
		e->draw_end = WIN_H - 1;
}

void draw_wall(t_env *e, int y)
{
	if (e->side == 0 && e->rayDirX >= 0)
		mlx_put_pixel(e->img, e->x, y, RED);
	else if (e->side == 0 && e->rayDirX < 0)
		mlx_put_pixel(e->img, e->x, y, GREY);
	else if (e->side == 1 && e->rayDirY >= 0)
		mlx_put_pixel(e->img, e->x, y, ORANGE);
	else
		mlx_put_pixel(e->img, e->x, y, GREEN);
}

void draw_lines(t_env *e)
{
	int y;

	y = -1;
	while (++y < WIN_H)
	{
		if (y < e->draw_start)
			mlx_put_pixel(e->img, e->x, y, SKY);
		else if (y > e->draw_end)
			mlx_put_pixel(e->img, e->x, y, BROWN);
		else
		{
			if (e->hit == 1)
				draw_wall(e, y);
		}
	}
}

void	fill_img(t_env *e)
{
	e->x = -1;
	while (++e->x < WIN_W)
	{
		raycast(e);
		where_draw(e);
		draw_lines(e);
	}
	mlx_put_img_to_win(e->mlx, e->win, e->img, 0, 0);
}
