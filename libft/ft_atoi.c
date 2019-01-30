/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:04:39 by kbakhari          #+#    #+#             */
/*   Updated: 2018/11/03 17:05:56 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	res;
	size_t	i;
	size_t	flag;

	flag = 1;
	i = 0;
	res = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' ||
			str[i] == ' ' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+' || str[i] == '0')
		if (str[i++] == '-')
			flag = -1;
	while ((str[i] >= 48 && str[i] <= 57))
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	if ((res > 9223372036854775807) ? 1 : 0)
		return (flag == 1 ? -1 : 0);
	return (res * flag);
}
