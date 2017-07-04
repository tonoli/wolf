/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 21:58:35 by itonoli-          #+#    #+#             */
/*   Updated: 2017/06/26 20:49:42 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str;
	char	*dest;
	size_t	i;

	i = 0;
	str = (char *)src;
	dest = (char *)dst;
	if (str >= dest)
	{
		while (i < len)
		{
			dest[i] = str[i];
			i++;
		}
	}
	else
	{
		while (len)
		{
			dest[len - 1] = str[len - 1];
			len--;
		}
	}
	return (dest);
}
