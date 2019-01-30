/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:08:31 by kbakhari          #+#    #+#             */
/*   Updated: 2018/10/29 14:05:29 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	n;

	n = 0;
	while (s1[n])
	{
		if (!s2[n] || s1[n] > s2[n])
			return ((unsigned char)s1[n] - (unsigned char)s2[n]);
		else if (s1[n] < s2[n])
			return ((unsigned char)s1[n] - (unsigned char)s2[n]);
		n++;
	}
	if (s2[n])
		return ((unsigned char)s1[n] - (unsigned char)s2[n]);
	return (0);
}
