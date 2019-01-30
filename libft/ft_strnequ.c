/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:08:31 by kbakhari          #+#    #+#             */
/*   Updated: 2018/10/29 14:10:17 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	nb;

	nb = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[nb] && n > 0)
	{
		if (!s2[nb] || s1[nb] > s2[nb])
			return (0);
		else if (s1[nb] < s2[nb])
			return (0);
		nb++;
		n--;
	}
	if (s2[nb] && n != 0)
		return (0);
	return (1);
}
