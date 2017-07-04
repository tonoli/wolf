/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:07:08 by itonoli-          #+#    #+#             */
/*   Updated: 2017/06/26 20:52:01 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)big;
	if (little[0] == '\0')
		return (&str[0]);
	while (str[i] != '\0')
	{
		while (little[j] == str[i + j])
		{
			if (little[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
