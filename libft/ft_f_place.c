/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 08:05:16 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/24 08:05:21 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_place_plmi_f(char *num, t_par *params)
{
	int			i;

	i = -1;
	if (params->width == -1 && num[0] == '0' && params->len == 1)
		return ;
	g_result = ft_strjoin_my(g_result, (M_PAR(below_zero) > 0 ? "-" : "+"));
	if (params->width <= params->len && params->precision <= params->len)
	{
		g_result = ft_strjoin(g_result, num);
		if (M_PAR(hash) > 0)
			g_result = ft_strjoin_my(g_result, ".");
		return ;
	}
	if (params->precision > params->len)
		while (++i < params->precision - params->len)
			g_result = ft_strjoin_my(g_result, "0");
	g_result = ft_strjoin(g_result, num);
	if (M_PAR(hash) > 0)
		g_result = ft_strjoin_my(g_result, ".");
	i = 0;
	while (++i < params->width - ((params->precision > params->len) ?
		params->precision : params->len))
		g_result = ft_strjoin_my(g_result, " ");
}

void			ft_place_pl_f(char *num, t_par *params)
{
	int			i;

	if (params->width == -1 && num[0] == '0' && params->len == 1)
		return ;
	i = 0;
	while (++i < params->width - ((params->precision > params->len) ?
		params->precision : params->len))
		g_result = ft_strjoin_my(g_result, " ");
	g_result = ft_strjoin_my(g_result, (M_PAR(below_zero) > 0 ? "-" : "+"));
	if (params->width <= params->len && params->precision <= params->len)
	{
		g_result = ft_strjoin(g_result, num);
		if (M_PAR(hash) > 0)
			g_result = ft_strjoin_my(g_result, ".");
		return ;
	}
	i = -1;
	if (params->precision > params->len)
		while (++i < params->precision - params->len)
			g_result = ft_strjoin_my(g_result, "0");
	g_result = ft_strjoin(g_result, num);
	if (M_PAR(hash) > 0)
		g_result = ft_strjoin_my(g_result, ".");
}

void			ft_width_precision_f(char *num, double n, t_par *params)
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
	M_PAR(precision) += M_PAR(precision) == -1 ? 7 : 0;
	num = ft_get_float(n, M_PAR(precision));
	M_PAR(precision) = -1;
	M_PAR(width) -= M_PAR(space) > 0 ? 1 : 0;
	M_PAR(len) = ft_strlen(num);
	M_PAR(hash) = ft_strchr(num, '.') ? 0 : M_PAR(hash);
	ft_starter_f(params, num);
}

void			ft_f_place(double n, char format)
{
	int			i;
	char		*result;
	t_par		*params;

	i = 0;
	result = NULL;
	params = ft_fill_struct(ft_ini_struct());
	params->zero += (n == 0) ? 1 : 0;
	g_format = format;
	ft_width_precision_f(result, n, params);
}

void			ft_fl_place(long double n, char format)
{
	int			i;
	char		*result;
	t_par		*params;

	i = 0;
	result = NULL;
	params = ft_fill_struct(ft_ini_struct());
	params->zero += (n == 0) ? 1 : 0;
	g_format = format;
	ft_width_precision_f(result, n, params);
}
