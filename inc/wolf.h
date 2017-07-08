/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 19:18:31 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/08 03:13:03 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libft/inc/libft.h"
# include "../minilibx/mlx.h"
# include "macros.h"

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*img_data;
	void	*menu;
	int		*menu_data;
	int		image_w;
	int		image_h;

	int		bpp;
	int		size_line;
	int		endian;

	char	**map;
	int		mapx;
	int		mapy;

	double	me_x;
	double	me_y;
	double	me_dirx;
	double	me_diry;

	double	speed;

	double	planex;
	double	planey;

	int		x;
	int		y;

	double	camerax;
	double	rayposx;
	double	rayposy;
	double	raydirx;
	double	raydiry;

	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;

	int		stepx;
	int		stepy;

	int		hit;
	int		side;

	int		lineheight;
	int		draw_start;
	int		draw_end;

	double	wh;
}				t_env;

int				ft_error(int i);
int				kill_program(void);
void			init(t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
int				key_hook(int key, t_env *env);
int				mouse_move(int x, int y, t_env *e);
void			parse(char *path, t_env *e);
void			raycast(t_env *e);
void			fill_img(t_env *e);

#endif
