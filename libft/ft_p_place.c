/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 08:29:32 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/24 08:29:33 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_place_mi_p(char *num, t_par *params, int i)
{
	if (params->width == -1 && num[0] == '0' && params->len == 1)
	{
		if (params->hash > 0)
			ft_set_hash(&params);
		return ;
	}
	if (params->width <= params->len && params->precision <= params->len)
	{
		if (params->hash > 0)
			ft_set_hash(&params);
		g_result = ft_strjoin(g_result, num);
		return ;
	}
	if (params->precision > params->len)
		while (++i < params->precision - params->len)
			g_result = ft_strjoin_my(g_result, "0");
	ft_set_hash(&params);
	g_result = ft_strjoin(g_result, num);
	i = (params->below_zero > 0) ? 0 : -1;
	while (++i < params->width - ((params->precision > params->len) ?
		params->precision : params->len))
		g_result = ft_strjoin_my(g_result, " ");
}

static int		ft_place_p_two(char *num, t_par *params, int i, int *flag)
{
	i = 0;
	*flag = 0;
	if (params->zero != 0)
		i -= (params->precision == 0) ? 1 : 0;
	if (params->hash > 0 && params->zeroes > 0 && params->precision == -1 &&
		params->precision != 0 && num[0] != '0' && params->len != 1)
		ft_set_hash(&params);
	while (i < params->width - ((params->precision > params->len) ?
		params->precision : params->len))
	{
		if (params->zeroes > 0 && params->precision == -1)
			g_result = ft_strjoin_my(g_result, "0");
		else
			g_result = ft_strjoin_my(g_result, " ");
		i++;
	}
	return (-1);
}

void			ft_place_p(char *num, t_par *params)
{
	int			i;
	int			flag;

	if (M_PAR(width) <= M_PAR(len) && M_PAR(precision) <= M_PAR(len))
	{
		ft_set_hash(&params);
		g_result = ft_strjoin(g_result, num);
		return ;
	}
	else if (params->width > params->len)
		i = ft_place_p_two(num, params, i, &flag);
	if (params->precision == 0 && num[0] == '0' && params->len == 1)
	{
		ft_set_hash(&params);
		return ;
	}
	i = -1;
	ft_set_hash(&params);
	while (++i < params->precision - params->len)
		g_result = ft_strjoin_my(g_result, "0");
	g_result = ft_strjoin(g_result, num);
}

void			ft_width_precision_p(char *num, t_par *params)
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
	params->width -= (params->hash > 0 ? 2 : 0);
	ft_starter_p(params, num);
}

void			ft_p_place(int n)
{
	int			*b;
	size_t		c;
	char		*result;
	t_par		*params;
	int			i;

	b = &n;
	c = (size_t)b;
	i = 0;
	params = ft_fill_struct(ft_ini_struct());
	params->zero += (n == 0) ? 1 : 0;
	if (n == 0)
		result = ft_strdup("0");
	else
		result = ft_itoa_base(c, 16, 'x');
	g_format = 'x';
	params->len = (int)ft_strlen(result);
	M_PAR(hash) = 1;
	ft_width_precision_p(result, params);
}
