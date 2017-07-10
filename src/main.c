/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 19:17:50 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/08 15:25:53 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

void	file_error(char *argv)
{
	int			len;
	const char	*last_four;

	len = strlen(argv);
	last_four = &argv[len - 4];
	if (len < 5 || ft_strncmp(".w3d", last_four, 5) != 0)
		ft_error(2);
}

int		main(int ac, char **av)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (ft_error(1));
	if (ac != 2)
		return (ft_error(0));
	file_error(av[1]);
	init(e);
	parse(av[1], e);
	raycast(e);
	fill_img(e);
	mlx_hook(e->win, 17, (1L << 17), kill_program, e);
	mlx_hook(e->win, 2, (1L << 0), key_hook, e);
	mlx_loop(e->mlx);
	mlx_destroy_window(e->mlx, e->win);
}
