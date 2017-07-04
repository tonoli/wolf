/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:22:20 by itonoli-          #+#    #+#             */
/*   Updated: 2017/06/26 20:51:50 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	len_little;

	i = 0;
	if (ft_strcmp(little, "") == 0)
		return ((char *)&big[i]);
	len_little = ft_strlen(little);
	while (big[i] != '\0' && len >= len_little)
	{
		if (ft_strncmp(&big[i], little, len_little) == 0)
			return ((char *)&big[i]);
		i++;
		len--;
	}
	return (NULL);
}
