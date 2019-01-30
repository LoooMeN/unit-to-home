/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_placetwo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:38:45 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/24 08:06:00 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_int_place(int n)
{
	int			i;
	char		*result;
	t_par		*params;

	i = 0;
	params = ft_fill_struct(ft_ini_struct());
	params->below_zero += (n < 0) ? 1 : 0;
	params->zero += (n == 0) ? 1 : 0;
	result = ft_itoa(n);
	if (n < 0)
		result = ft_cut_one(result);
	params->len = (int)ft_strlen(result);
	M_PAR(plus) += ft_strchr(result, '+') ? 1 : 0;
	M_PAR(space) += ft_strchr(result, ' ') ? 1 : 0;
	ft_width_precision_int(result, params);
}

void			ft_lint_place(long int n)
{
	int			i;
	char		*result;
	t_par		*params;

	i = 0;
	params = ft_fill_struct(ft_ini_struct());
	params->below_zero += (n < 0) ? 1 : 0;
	params->zero += (n == 0) ? 1 : 0;
	result = ft_itol((long int)n);
	if (n < 0)
		result = ft_cut_one(result);
	params->len = (int)ft_strlen(result);
	M_PAR(plus) += ft_strchr(result, '+') ? 1 : 0;
	M_PAR(space) += ft_strchr(result, ' ') ? 1 : 0;
	ft_width_precision_int(result, params);
}

void			ft_hint_place(int n)
{
	int			i;
	char		*result;
	t_par		*params;

	i = 0;
	params = ft_fill_struct(ft_ini_struct());
	params->below_zero += (n < 0) ? 1 : 0;
	params->zero += (n == 0) ? 1 : 0;
	result = ft_itoa((short int)n);
	if (n < 0)
		result = ft_cut_one(result);
	params->len = (int)ft_strlen(result);
	M_PAR(plus) += ft_strchr(result, '+') ? 1 : 0;
	M_PAR(space) += ft_strchr(result, ' ') ? 1 : 0;
	ft_width_precision_int(result, params);
}

void			ft_hhint_place(int n)
{
	char		*result;
	t_par		*params;
	int			i;
	char		*temp;

	i = 0;
	params = ft_fill_struct(ft_ini_struct());
	params->zero += (n == 0) ? 1 : 0;
	result = ft_itol((signed char)n);
	params->len = (int)ft_strlen(result);
	M_PAR(space) += ft_strchr(result, ' ') ? 1 : 0;
	M_PAR(plus) += ft_strchr(result, '+') ? 1 : 0;
	if (n < 0 && ft_strcmp(result, "0") == 0)
		params->len++;
	ft_width_precision_int(result, params);
}

void			ft_width_precision_int(char *num, t_par *params)
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
	M_PAR(width) -= (M_PAR(space) > 0 && num[0] != '0') ? 1 : 0;
	if (ft_strchr(g_flags, '.'))
		params->precision = ft_atoi(ft_strrchr(g_flags, '.') + 1);
	ft_starter_int(params, num);
}
