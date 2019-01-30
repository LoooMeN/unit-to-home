/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraycmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:55:47 by kbakhari          #+#    #+#             */
/*   Updated: 2018/10/30 17:06:55 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_arraycmp(char **a1, char **a2)
{
	int		i;

	i = 0;
	while (a1[i])
	{
		if (!a2[i] || ft_strcmp(a1[i], a2[i]) > 1)
			return (1);
		else if (ft_strcmp(a1[i], a2[i]) < 0)
			return (-1);
		i++;
	}
	if (a2[i])
		return (a1[i] - a2[i]);
	return (0);
}
