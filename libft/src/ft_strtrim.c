/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 20:41:06 by itonoli-          #+#    #+#             */
/*   Updated: 2017/06/26 20:52:10 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char		*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	len;
	unsigned int	start;
	unsigned int	end;

	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	end = 0;
	start = 0;
	if (len + 1 <= 0)
		return (ft_strdup(""));
	while (ft_iswhite(s[start]) == 1)
		start++;
	if (s[start] == '\0')
		return (ft_strdup(""));
	while (ft_iswhite(s[len]) == 1)
	{
		len--;
		end++;
	}
	len = ft_strlen(s) - start - end;
	str = ft_strsub(s, start, len);
	return (str);
}
