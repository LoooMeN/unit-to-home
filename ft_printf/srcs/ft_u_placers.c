/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_placers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:04:50 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/18 18:04:51 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_width_precision_u(char *num, t_par *params)
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
		else if (g_flags[i] == '.' && (g_flags[i + 1] >= '0' && g_flags[i + 1] <= '9'))
			while (g_flags[i + 1] >= '0' && g_flags[i + 1] <= '9')
				i++;
		i++;
	}
	if (ft_strchr(g_flags, '.'))
		params->precision = ft_atoi(ft_strrchr(g_flags, '.') + 1);
	if (params->minus > 0)
		ft_place_mi_u(num, params);
	else
		ft_place_u(num, params);
	return (0);
}

static int		ft_place_u_two(char *num, t_par *params, int i, int *flag)
{
	i = 0;
	*flag = 0;
	if (params->zero != 0)
		i -= (params->precision == 0) ? 1 : 0;
	while (i < params->width - ((params->precision > params->len) ?
		params->precision : params->len))
	{
		if (params->zeroes > 0 && params->precision == -1)
			g_result = ft_strjoin_my(g_result, "0");
		else
			g_result = ft_strjoin_my(g_result, " ");
		i++;
	}
	return (i);
}

void			ft_place_u(char *num, t_par *params)
{
	int			i;
	int			flag;

	if (params->precision == 0 && num[0] == '0' && params->len == 1 &&
		params->width <= 0)
		return ;
	else if (M_PAR(width) <= M_PAR(len) && M_PAR(precision) <= M_PAR(len))
	{
		g_result = ft_strjoin(g_result, num);
		return ;
	}
	else if (params->width > params->len)
		i = ft_place_u_two(num, params, i, &flag);
	if (params->precision == 0 && num[0] == '0' && params->len == 1)
		return ;
	i = -1;
	while (++i < params->precision - params->len)
		g_result = ft_strjoin_my(g_result, "0");
	g_result = ft_strjoin(g_result, num);
}