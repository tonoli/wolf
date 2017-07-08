/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 19:17:50 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/05 23:10:12 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void wolf(t_env *e)
{
	raycast(e);
	fill_img(e);
}

int		main(int ac, char **av)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (ft_error(1));
	if (ac != 2)
		return (ft_error(0));
	init(e);
	parse(av[1], e);
	int i = 0;
	while(i < 10)
		ft_putendl(e->map[i++]);
	wolf(e);
	mlx_hook(e->win, 6, (1L << 6), mouse_move, e);
	mlx_hook(e->win, 17, (1L << 17), kill_program, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->mlx);
}
