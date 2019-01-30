/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 08:07:53 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/24 08:07:55 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_starter_int(t_par *params, char *num)
{
	if (params->plus == 0 && params->minus == 0)
		ft_place_int(num, params);
	else if (params->plus > 0 && params->minus > 0)
		ft_place_plmi_int(num, params);
	else if (params->minus > 0)
		ft_place_mi_int(num, params);
	else
		ft_place_pl_int(num, params);
}

void	ft_starter_p(t_par *params, char *num)
{
	if (M_PAR(precision) == 0 && num[0] == '0' && M_PAR(len) == 1 &&
		M_PAR(width) <= 0)
	{
		ft_set_hash(&params);
		return ;
	}
	if (params->minus > 0)
		ft_place_mi_p(num, params, -1);
	else
		ft_place_p(num, params);
}

void	ft_starter_f(t_par *params, char *num)
{
	if (M_PAR(minus) == 0 && M_PAR(plus) == 0)
		ft_place_f(num, params, 0);
	else if (M_PAR(minus) == 0 && M_PAR(plus) > 0)
		ft_place_pl_f(num, params);
	else if (M_PAR(minus) > 0 && M_PAR(plus) == 0)
		ft_place_mi_f(num, params);
	else
		ft_place_plmi_f(num, params);
}

char	*ft_strjoin_my(char const *s1, char const *s2)
{
	char	*res;
	int		reslen;
	int		i;

	if (s1 != NULL && s2 != NULL)
	{
		i = -1;
		reslen = ft_strlen(s1) + 1;
		if (!(res = (char*)malloc(sizeof(char) * reslen + 1)))
			return (NULL);
		while (s1[++i])
			res[i] = s1[i];
		res[i++] = s2[0];
		res[i] = '\0';
		free((char*)s1);
		return (res);
	}
	return (0);
}

char	*ft_itoa_base(long int value, int base, char format)
{
	char	*s;
	long	n;
	int		sign;
	int		i;

	n = (value < 0) ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (i-- + sign)
	{
		if (n % base < 10)
			s[i] = n % base + '0';
		else
			s[i] = n % base + (format == 'X' ? 'A' : 'a') - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}
