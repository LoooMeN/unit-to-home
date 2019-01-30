/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:34:21 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/24 10:34:42 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int			ft_pow(int num1, int num2)
{
	int					i;

	i = num1;
	num2--;
	while (num2)
	{
		num1 *= i;
		num2--;
	}
	return (num1);
}

char					*ft_get_float(long double n, int afterpoint)
{
	int					num1;
	long double			num2;
	char				*res;
	int					i;
	char				*temp;

	num1 = (int)n;
	num2 = n - (long double)num1;
	res = ft_itoa(num1);
	i = ft_strlen(res);
	if (afterpoint != 0)
	{
		res = ft_strjoin_my(res, ".");
		num2 = num2 * ft_pow(10, afterpoint + 1);
		if ((int)num2 % 10 >= 5)
			num2 += 10;
		temp = ft_itoa(num2);
		res = ft_strjoin(res,
			ft_strsub(temp, 0, ft_strlen(temp) - 1));
		free(temp);
	}
	return (res);
}

t_par					*ft_ini_struct(void)
{
	t_par				*params;

	if (!(params = (t_par*)malloc(sizeof(t_par))))
		return (NULL);
	params->minus = 0;
	params->plus = 0;
	params->below_zero = 0;
	params->zeroes = 0;
	params->space = 0;
	params->width = -1;
	params->precision = -1;
	params->hash = 0;
	params->len = 0;
	params->zero = 0;
	return (params);
}

t_par					*ft_fill_struct(t_par *params)
{
	int					i;

	i = 0;
	while (g_flags[i])
	{
		params->minus += (g_flags[i] == '-') ? 1 : 0;
		params->plus += (g_flags[i] == '+') ? 1 : 0;
		params->space += (g_flags[i] == ' ') ? 1 : 0;
		params->hash += (g_flags[i] == '#') ? 1 : 0;
		if (g_flags[i] == '0' && g_flags[i - 1] != '.' && ((g_flags[i - 1]
			> '9' || g_flags[i - 1] < '0') || i == 0))
			params->zeroes = 1;
		i++;
	}
	return (params);
}

unsigned long int		ft_o_convert(unsigned long int num)
{
	unsigned long int	place;
	unsigned long int	remainder;
	unsigned long int	octal;

	place = 1;
	remainder = 0;
	octal = 0;
	while (num != 0)
	{
		remainder = num % 8;
		num /= 8;
		octal += remainder * place;
		place *= 10;
	}
	return (octal);
}
