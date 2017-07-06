/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:20:59 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/05 23:10:08 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void where_draw(t_env *e)
{
//Calculate height of line to draw on screen
	e->lineHeight = (int)(WIN_H / e->perpWallDist);

//calculate lowest and highest pixel to fill in current stripe
	e->draw_start = -e->lineHeight / 2 + WIN_H / 2;
	if(e->draw_start < 0)
		e->draw_start = 0;
	e->draw_end = e->lineHeight / 2 + WIN_H / 2;
	if(e->draw_end >= WIN_H)
		e->draw_end = WIN_H - 1;
}

void draw_wall(t_env *e, int y)
{
//	if (e->me_dirx < 0 && e->rayDirX < 0)
		mlx_put_pixel(e->img, e->x, y, RED);
/*	else if (e->me_dirx < 0 && e->rayDirX < 0)
		mlx_put_pixel(e->img, e->x, y, GREY);
	else if (e->me_dirx < 0 && e->rayDirX < 0)
		mlx_put_pixel(e->img, e->x, y, ORANGE);
	else if (e->me_dirx < 0 && e->rayDirX < 0)
		mlx_put_pixel(e->img, e->x, y, GREEN);*/
}

void draw_lines(t_env *e)
{
	int y;

	e->x = -1;
	while (++e->x < WIN_W)
	{
		y = -1;
		while (++y < WIN_H)
		{
			if (y < e->draw_start)
				mlx_put_pixel(e->img, e->x, y, SKY);
			else if (e->draw_start < y && y < e->draw_end)
				draw_wall(e, y);
			else if (y > e->draw_end)
				mlx_put_pixel(e->img, e->x, y, BROWN);
		}
	}
}

void	fill_img(t_env *e)
{
	where_draw(e);
	draw_lines(e);
	mlx_put_img_to_win(e->mlx, e->win, e->img, 0, 0);
}
