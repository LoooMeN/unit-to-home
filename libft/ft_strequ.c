/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:08:31 by kbakhari          #+#    #+#             */
/*   Updated: 2018/10/29 14:05:12 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	unsigned int	n;

	n = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[n])
	{
		if (!s2[n] || s1[n] > s2[n])
			return (0);
		else if (s1[n] < s2[n])
			return (0);
		n++;
	}
	if (s2[n])
		return (0);
	return (1);
}
