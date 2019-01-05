/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:32:08 by kbakhari          #+#    #+#             */
/*   Updated: 2018/11/02 14:35:53 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_extra(char const *s)
{
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	while (s[i1] == ' ' || s[i1] == '\t' || s[i1] == '\n')
		i1++;
	while (s[i2] != '\0')
		i2++;
	while (s[i2 - 1] == ' ' || s[i2 - 1] == '\t' || s[i2 - 1] == '\n')
		i2--;
	return (i2 - i1);
}

char			*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		c;
	char		*res;

	if (s != NULL)
	{
		i = 0;
		c = 0;
		if (ft_count_extra(s) < 0)
		{
			res = (char *)malloc(sizeof(char));
			res[0] = '\0';
			return (res);
		}
		if (!(res = ft_memalloc((size_t)ft_count_extra(s) + 1)))
			return (NULL);
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		while (c < (size_t)ft_count_extra(s))
			res[c++] = s[i++];
		res[c] = '\0';
		return (res);
	}
	return (NULL);
}
