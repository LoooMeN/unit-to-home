/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:13:38 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/24 08:06:21 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	int_len(long int n)
{
	int			i;

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

static char		*fill_res(char *res, long int n)
{
	long int	i;

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

char			*ft_itol(long int n)
{
	char		*res;

	if (n < -9223372036854775807)
	{
		res = ft_strdup("-9223372036854775808");
		return (res);
	}
	if (!(res = (char *)malloc(sizeof(char) * int_len(n) + 1)))
		return (NULL);
	if (n < 0)
		res[0] = '-';
	return (fill_res(res, n));
}
