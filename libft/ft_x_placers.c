/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_placers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 08:08:12 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/24 08:08:17 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_place_mi_x(char *num, t_par *params, int i)
{
	if (params->width == -1 && num[0] == '0' && params->len == 1)
		return ;
	if (params->width <= params->len && params->precision <= params->len)
	{
		if (params->hash > 0)
			ft_set_hash(&params);
		g_result = ft_strjoin(g_result, num);
		return ;
	}
	if (params->precision > params->len)
	{
		if (params->hash > 0)
			ft_set_hash(&params);
		while (++i < params->precision - params->len)
			g_result = ft_strjoin_my(g_result, "0");
	}
	if (params->hash > 0)
		ft_set_hash(&params);
	g_result = ft_strjoin(g_result, num);
	i = (params->below_zero > 0) ? 0 : -1;
	while (++i < params->width - ((params->precision > params->len) ?
		params->precision : params->len))
		g_result = ft_strjoin_my(g_result, " ");
}

static int		ft_place_x_two(char *num, t_par *params, int i, int *flag)
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
	return (i);
}

void			ft_place_x(char *num, t_par *params)
{
	int			i;
	int			flag;

	if (params->precision == 0 && num[0] == '0' && params->len == 1 &&
		params->width <= 0)
		return ;
	else if (M_PAR(width) <= M_PAR(len) && M_PAR(precision) <= M_PAR(len))
	{
		if (params->hash > 0 && params->precision != 0 && num[0] != '0' &&
			params->len != 1)
			ft_set_hash(&params);
		g_result = ft_strjoin(g_result, num);
		return ;
	}
	else if (params->width > params->len)
		i = ft_place_x_two(num, params, i, &flag);
	if (params->precision == 0 && num[0] == '0' && params->len == 1)
		return ;
	i = -1;
	if (params->hash > 0 && params->precision != 0 && num[0] != '0' &&
		params->len != 1)
		ft_set_hash(&params);
	while (++i < params->precision - params->len)
		g_result = ft_strjoin_my(g_result, "0");
	g_result = ft_strjoin(g_result, num);
}
