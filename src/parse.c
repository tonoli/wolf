/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 02:00:43 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/04 03:08:52 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

static int		get_size(char *path, t_env *e)
{
	int		fd;
	int		i;
	char	*line;
	char	**tab;

	if ((fd = open(path, O_RDONLY)) == -1)
		ft_error(4);
	while (get_next_line(fd, &line) > 0)
	{
		tab = ft_strsplit(line, ' ');
		i = ft_tablen(tab);
		(i > e->mapy++ && e->mapx == 0) ? e->mapx = i : 0;
		if (i != e->mapx)
			return (1);
	}
	free(tab);
	((close(fd)) == -1) ? ft_error(4) : 0;
	return (0);
}

void get_values(char *path, t_env *e)
{
	int     fd;
	int		x;
	int		y;
	char    *line;
	char	**tab;

	if ((fd = open(path, O_RDONLY)) == -1)
		ft_error(4);
	y = -1;
	while (++y < e->mapy)
	{
		get_next_line(fd, &line);
		tab = ft_strsplit(line, ' ');
		x = -1;
		while (++x < e->mapx)
			e->map[y][x] = tab[x][0];
	}
	free(tab);
}

void parse(char *path, t_env *e)
{
	if (get_size(path, e))
		ft_error(2);
	e->map = ft_memctab(e->mapy, e->mapx);
	get_values(path, e);
}
