/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 19:17:50 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/03 17:51:22 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void parse(char *path, t_env *e)
{
	int     fd;
	int		x;
	char    *line;

	x = 0;

	if ((fd = open(path, O_RDONLY)) == -1)
		ft_error(4);
	while (get_next_line(fd, &line) > 0)
	{
			e->map[x++]= line;
	}
	ft_strdel(&line);
	if ((close(fd)) == -1)
		ft_error(4);
}

static void wolf(t_env *e)
{
	(void)e;
}

int		main(int ac, char **av)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (ft_error(1));
	if (ac != 2)
		return (ft_error(0));
	parse(av[1], e);
	//test parsing
	int x = 0;
	while (e->map[x] != '\0')
	{
		ft_putendl(e->map[x]);
		x++;
	}
	//fin du test
	init(e);
	wolf(e);
	mlx_hook(e->win, 6, (1L << 6), mouse_move, e);
	mlx_hook(e->win, 17, (1L << 17), kill_program, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->mlx);
}
