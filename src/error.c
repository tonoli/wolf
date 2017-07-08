/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 23:21:45 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/04 01:23:21 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

int		kill_program(void)
{
	exit(0);
	return (0);
}

int		ft_error(int i)
{
	if (i == 0)
		ft_puterror("Usage : ./wolf3d <map>");
	else if (i == 1)
		ft_puterror("error: Dynamic memory allocation failed.");
	else if (i == 2)
		ft_puterror("error: The imput file is not valid.");
	else if (i == 3)
		ft_puterror("error: The map can't be read");
	else if (i == 4)
		ft_puterror(ft_strjoin("error: ", strerror(errno)));
	return (0);
}
