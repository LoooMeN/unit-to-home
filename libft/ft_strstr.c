/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:01:55 by kbakhari          #+#    #+#             */
/*   Updated: 2018/10/28 15:55:10 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		len;
	char	*res;
	int		a;

	res = (char *)haystack;
	i = 0;
	len = ft_strlen(needle);
	if (ft_strlen(needle) > 0)
	{
		while (haystack[i])
		{
			a = 0;
			while (needle[a] == haystack[i + a])
			{
				a++;
				if (a == len)
					return (&res[i]);
			}
			i++;
		}
	}
	else
		return (res);
	return (NULL);
}
