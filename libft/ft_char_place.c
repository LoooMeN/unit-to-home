/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:19:11 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/24 08:05:03 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_place_char(char *num, t_par *params)
{
	int			i;

	i = -1;
	if (M_PAR(minus) > 0)
		g_result = ft_strjoin(g_result, num);
	while (++i < M_PAR(width) - M_PAR(len))
	{
		if (M_PAR(zeroes) > 0 && M_PAR(minus) == 0)
			g_result = ft_strjoin_my(g_result, "0");
		else
			g_result = ft_strjoin_my(g_result, " ");
	}
	if (num[0] == 0)
	{
		g_result = ft_strjoin_my(g_result, "");
		return ;
	}
	if (M_PAR(minus) == 0)
		g_result = ft_strjoin(g_result, num);
}

void			ft_width_precision_c(char *num, t_par *params)
{
	int			i;

	i = 0;
	while (g_flags[i])
	{
		if (g_flags[i] > '0' && g_flags[i] <= '9')
		{
			params->width = ft_atoi(&g_flags[i]);
			while (g_flags[i + 1] >= '0' && g_flags[i + 1] <= '9')
				i++;
		}
		else if (g_flags[i] == '.' && (g_flags[i + 1] >= '0' &&
			g_flags[i + 1] <= '9'))
			while (g_flags[i + 1] >= '0' && g_flags[i + 1] <= '9')
				i++;
		i++;
	}
	if (ft_strcmp(num, "") == 0)
		M_PAR(width)--;
	ft_place_char(num, params);
}

void			ft_char_place(char n)
{
	int			i;
	char		*result;
	t_par		*params;

	i = 0;
	params = ft_fill_struct(ft_ini_struct());
	params->below_zero += (n < 0) ? 1 : 0;
	params->zero += (n == 0) ? 1 : 0;
	result = (char*)malloc(sizeof(char) + 1);
	result[0] = n;
	if (ft_strcmp(result, "") == 0)
		g_kostil++;
	if (ft_strchr(g_flags, '.'))
		params->precision = ft_atoi(ft_strrchr(g_flags, '.') + 1);
	params->len = (int)ft_strlen(result);
	ft_width_precision_c(result, params);
}
