/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:08:31 by kbakhari          #+#    #+#             */
/*   Updated: 2018/10/28 17:02:34 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	nb;

	nb = 0;
	while (s1[nb] && nb < n)
	{
		if (!s2[nb] || s1[nb] > s2[nb])
			return ((unsigned char)s1[nb] - (unsigned char)s2[nb]);
		else if (s1[nb] < s2[nb])
			return ((unsigned char)s1[nb] - (unsigned char)s2[nb]);
		nb++;
	}
	if (s2[nb] && nb < n)
		return ((unsigned char)s1[nb] - (unsigned char)s2[nb]);
	return (0);
}
