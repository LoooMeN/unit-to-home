/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:59:57 by kbakhari          #+#    #+#             */
/*   Updated: 2018/10/28 17:48:12 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		leng;
	size_t		a;

	i = 0;
	leng = ft_strlen(needle);
	if (ft_strlen(needle) <= ft_strlen(haystack))
	{
		while (i < len)
		{
			a = 0;
			while (needle[a] == haystack[i + a] && i + a < len)
			{
				a++;
				if (a == leng)
					return ((char *)&haystack[i]);
			}
			i++;
		}
	}
	if (ft_strlen(needle) <= 0)
		return ((char*)haystack);
	return (NULL);
}
