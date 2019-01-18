/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:21:20 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/18 17:21:22 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_place_mi_u(char *num, t_par *params)
{
	int			i;

	i = -1;
	if (params->width == -1 && num[0] == '0' && params->len == 1)
		return ;
	if (params->width <= params->len && params->precision <= params->len)
		g_result = ft_strjoin(g_result, num);
	if (params->precision > params->len)
	{
		while (++i < params->precision - params->len)
			g_result = ft_strjoin_my(g_result, "0");
	}
	g_result = ft_strjoin(g_result, num);
	i = (params->below_zero > 0) ? 0 : -1;
	while (++i < params->width - ((params->precision > params->len) ?
		params->precision : params->len))
		g_result = ft_strjoin_my(g_result, " ");
}

void	ft_u_place(unsigned int n)
{
	int			i;
	char		*result;
	t_par		*params;

	i = 0;
	params = ft_ini_struct();
	while (g_flags[i])
	{
		params->minus += (g_flags[i] == '-') ? 1 : 0;
		params->plus += (g_flags[i] == '+') ? 1 : 0;
		params->space += (g_flags[i] == ' ') ? 1 : 0;
		params->hash += (g_flags[i] == '#') ? 1 : 0;
		if (g_flags[i] == '0' && ((g_flags[i - 1] > '9' ||
			g_flags[i - 1] < '0') || i == 0))
			params->zeroes = 1;
		i++;
	}
	params->zero += (n == 0) ? 1 : 0;
	result = ft_itol(n);
	params->len = (int)ft_strlen(result);
	ft_width_precision_u(result, params);
}

void	ft_ul_place(unsigned long int n)
{
	int			i;
	char		*result;
	t_par		*params;

	i = 0;
	params = ft_ini_struct();
	while (g_flags[i])
	{
		params->minus += (g_flags[i] == '-') ? 1 : 0;
		params->plus += (g_flags[i] == '+') ? 1 : 0;
		params->space += (g_flags[i] == ' ') ? 1 : 0;
		params->hash += (g_flags[i] == '#') ? 1 : 0;
		if (g_flags[i] == '0' && ((g_flags[i - 1] > '9' ||
			g_flags[i - 1] < '0') || i == 0))
			params->zeroes = 1;
		i++;
	}
	params->zero += (n == 0) ? 1 : 0;
	result = ft_itol(n);
	params->len = (int)ft_strlen(result);
	ft_width_precision_u(result, params);
}

void			ft_hu_place(unsigned short int n)
{
	int			i;
	char		*result;
	t_par		*params;

	i = 0;
	params = ft_ini_struct();
	while (g_flags[i])
	{
		params->minus += (g_flags[i] == '-') ? 1 : 0;
		params->plus += (g_flags[i] == '+') ? 1 : 0;
		params->space += (g_flags[i] == ' ') ? 1 : 0;
		params->hash += (g_flags[i] == '#') ? 1 : 0;
		if (g_flags[i] == '0' && ((g_flags[i - 1] > '9' ||
			g_flags[i - 1] < '0') || i == 0))
			params->zeroes = 1;
		i++;
	}
	params->zero += (n == 0) ? 1 : 0;
	result = ft_itol(n);
	params->len = (int)ft_strlen(result);
	ft_width_precision_u(result, params);
}

void			ft_hhu_place(unsigned int n)
{
	char		*result;

	result = ft_itol(n);
	g_result = ft_strjoin(g_result, result);
}