/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_placetwo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:38:45 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/18 16:38:55 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_int_place(int n)
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
	params->below_zero += (n < 0) ? 1 : 0;
	params->zero += (n == 0) ? 1 : 0;
	result = ft_itoa(n);
	if (n < 0)
		result = ft_cut_one(result);
	params->len = (int)ft_strlen(result);
	ft_width_precision_int(result, params);
}

void			ft_lint_place(long int n)
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
	params->below_zero += (n < 0) ? 1 : 0;
	params->zero += (n == 0) ? 1 : 0;
	result = ft_itol(n);
	if (n < 0)
		result = ft_cut_one(result);
	params->len = (int)ft_strlen(result);
	ft_width_precision_int(result, params);
}

void			ft_hint_place(int n)
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
	params->below_zero += (n < 0) ? 1 : 0;
	params->zero += (n == 0) ? 1 : 0;
	result = ft_itoa(n);
	if (n < 0)
		result = ft_cut_one(result);
	params->len = (int)ft_strlen(result);
	ft_width_precision_int(result, params);
}

void			ft_hhint_place(int n)
{
	char		*result;

	result = ft_itoa(n);
	g_result = ft_strjoin(g_result, result);
}
