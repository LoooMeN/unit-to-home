/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:07:46 by kbakhari          #+#    #+#             */
/*   Updated: 2018/11/09 14:22:11 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		reslen;
	int		i;
	int		j;

	if (s1 != NULL && s2 != NULL)
	{
		i = -1;
		j = -1;
		reslen = ft_strlen(s1) + ft_strlen(s2);
		if (!(res = (char*)malloc(sizeof(char) * reslen + 1)))
			return (NULL);
		while (i < reslen)
		{
			while (s1[++i])
				res[i] = s1[i];
			while (s2[++j])
				res[i++] = s2[j];
		}
		res[i] = '\0';
		return (res);
	}
	return (0);
}
