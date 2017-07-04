/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 19:18:31 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/03 18:10:55 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libft/inc/libft.h"
# include "../minilibx/includes/mlx.h"
# include "macros.h"

typedef struct		s_env
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

	int		me_x;
	int		me_y;
	int		me_view;

	char	**map;
}					t_env;

int		ft_error(int i);
int		kill_program(void);
void	init(t_env *e);
int		mouse_hook(int button, int x, int y, t_env *e);
int		key_hook(int key, t_env *env);
int		mouse_move(int x, int y, t_env *e);

#endif
