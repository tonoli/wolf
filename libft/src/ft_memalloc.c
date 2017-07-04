/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:22:35 by itonoli-          #+#    #+#             */
/*   Updated: 2017/06/26 20:49:08 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*a;

	a = NULL;
	a = (void *)malloc(sizeof(void) * size);
	if (a)
	{
		ft_bzero(a, size);
		return (a);
	}
	return (NULL);
}
