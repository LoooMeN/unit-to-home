/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_place.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:23:08 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/24 08:07:11 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_place_str(char *num, t_par *params)
{
	int			i;

	i = -1;
	if (M_PAR(len) > M_PAR(width) && M_PAR(precision) == -1)
	{
		g_result = ft_strjoin(g_result, num);
		return ;
	}
	while (++i < M_PAR(width) - (M_PAR(len) > M_PAR(precision) &&
		M_PAR(precision) != -1 ? M_PAR(precision) : M_PAR(len)))
	{
		if (M_PAR(zeroes) > 0)
			g_result = ft_strjoin_my(g_result, "0");
		else
			g_result = ft_strjoin_my(g_result, " ");
	}
	if (M_PAR(precision) == -1)
			g_result = ft_strjoin(g_result, num);
	i = -1;
	// while (M_PAR(precision) != -1 && M_PAR(precision) < M_PAR(len) &&
	// 	++i < M_PAR(precision))
	// 	g_result = ft_strjoin_my(g_result, "0");
	while (M_PAR(precision) != -1 && M_PAR(precision) < M_PAR(len) &&
		++i < M_PAR(precision))
		g_result = ft_strjoin_my(g_result, &num[i]);
}

void			ft_place_mi_str(char *num, t_par *params)
{
	int			i;

	i = -1;
	while (M_PAR(precision) != -1 && M_PAR(precision) < M_PAR(len) &&
		++i < M_PAR(precision))
		g_result = ft_strjoin_my(g_result, &num[i]);
	if (M_PAR(precision == -1))
	{
		g_result = ft_strjoin(g_result, num);
		M_PAR(width) -= M_PAR(len) + 1;
	}
	i = -1;
	while (++i < M_PAR(width) - (M_PAR(len) > M_PAR(precision) ?
		M_PAR(precision) : M_PAR(len)))
		g_result = ft_strjoin_my(g_result, " ");
}

void			ft_width_precision_str(char *num, t_par *params)
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
	if (ft_strchr(g_flags, '.'))
		params->precision = ft_atoi(ft_strrchr(g_flags, '.') + 1);
	if (params->minus == 0)
		ft_place_str(num, params);
	else if (params->minus > 0)
		ft_place_mi_str(num, params);
}

void			ft_string_place(char *str)
{
	t_par		*params;

	params = ft_fill_struct(ft_ini_struct());
	if (str == NULL)
		str = ft_strdup("(null)");
	M_PAR(len) = ft_strlen(str);
	ft_width_precision_str(str, params);
}
