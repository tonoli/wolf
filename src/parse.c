
#include "../inc/wolf.h"

void parse(char *path, t_env *e)
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
