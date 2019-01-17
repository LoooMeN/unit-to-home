/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 11:52:59 by kbakhari          #+#    #+#             */
/*   Updated: 2018/10/31 15:00:52 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		int_len(int n)
{
	int		i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (i + 1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char		*fill_res(char *res, int n)
{
	int		i;

	i = int_len(n);
	if (n < 0)
		n = -n;
	res[i--] = '\0';
	if (n == 0)
		res[i] = '0';
	while (n != 0)
	{
		res[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	return (res);
}

char			*ft_itoa(int n)
{
	char	*res;

	if (n == -2147483648)
	{
		res = ft_strdup("-2147483648");
		return (res);
	}
	if (!(res = (char *)malloc(sizeof(char) * int_len(n) + 1)))
		return (NULL);
	if (n < 0)
		res[0] = '-';
	return (fill_res(res, n));
}
