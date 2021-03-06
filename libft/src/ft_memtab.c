/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 13:10:28 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/04 01:50:13 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	**ft_memtab(int lines, int col)
{
	int i;
	int j;
	int **tab;

	if (!(tab = malloc(sizeof(int *) * lines)))
		ft_puterror("error: Dynamic memory allocation failed.");
	i = -1;
	while (++i < lines)
	{
		if (!(tab[i] = malloc(sizeof(int) * col)))
			ft_puterror("error: Dynamic memory allocation failed.");
		j = -1;
		while (++j < col)
		{
			tab[i][j] = 0;
		}
	}
	return (tab);
}
