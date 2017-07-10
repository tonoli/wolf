/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memctab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 02:04:13 by itonoli-          #+#    #+#             */
/*   Updated: 2017/07/08 05:51:24 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	**ft_memctab(int lines, int col)
{
	int		i;
	int		j;
	char	**tab;

	tab = NULL;
	if (!(tab = malloc(sizeof(char *) * lines)))
		ft_puterror("error: Dynamic memory allocation failed.");
	i = -1;
	while (++i < lines)
	{
		if (!(tab[i] = malloc(sizeof(char) * col)))
			ft_puterror("error: Dynamic memory allocation failed.");
		j = -1;
		while (++j < col)
		{
			tab[i][j] = 0;
		}
		tab[i][j] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}
