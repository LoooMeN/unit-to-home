/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_placers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:47:00 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/24 08:06:12 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_place_int_two(char *num, t_par *params, int i, int *flag)
{
	i = 0;
	*flag = 0;
	if (params->zeroes > 0 && params->below_zero > 0 &&
		params->precision == -1)
	{
		g_result = ft_strjoin_my(g_result, "-");
		*flag = 1;
	}
	i += (params->below_zero > 0) ? 1 : 0;
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

void			ft_place_int(char *num, t_par *params)
{
	int			i;
	int			flag;

	if (params->space > 0 && params->below_zero == 0)
		g_result = ft_strjoin_my(g_result, " ");
	if (params->precision == 0 && num[0] == '0' && params->len == 1 &&
		params->width <= 0)
		return ;
	else if (M_PAR(width) <= M_PAR(len) && M_PAR(precision) <= M_PAR(len))
	{
		if (params->below_zero > 0)
			g_result = ft_strjoin_my(g_result, "-");
		g_result = ft_strjoin(g_result, num);
		return ;
	}
	else if (params->width > params->len)
		i = ft_place_int_two(num, params, i, &flag);
	if (params->precision == 0 && num[0] == '0' && params->len == 1)
		return ;
	i = -1;
	if (params->below_zero > 0 && flag != 1)
		g_result = ft_strjoin_my(g_result, "-");
	while (++i < params->precision - params->len)
		g_result = ft_strjoin_my(g_result, "0");
	g_result = ft_strjoin(g_result, num);
}

void			ft_place_mi_int(char *num, t_par *params)
{
	int			i;

	i = -1;
	if (params->width == -1 && num[0] == '0' && params->len == 1)
		return ;
	if (params->below_zero > 0)
		g_result = ft_strjoin_my(g_result, "-");
	if (params->width <= params->len && params->precision <= params->len)
	{
		g_result = ft_strjoin(g_result, num);
		return ;
	}
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

void			ft_place_plmi_int(char *num, t_par *params)
{
	int			i;

	i = -1;
	if (params->width == -1 && num[0] == '0' && params->len == 1)
		return ;
	if (params->below_zero > 0)
		g_result = ft_strjoin_my(g_result, "-");
	else
		g_result = ft_strjoin_my(g_result, "+");
	if (params->width <= params->len && params->precision <= params->len)
		g_result = ft_strjoin(g_result, num);
	if (params->precision > params->len)
		while (++i < params->precision - params->len)
			g_result = ft_strjoin_my(g_result, "0");
	g_result = ft_strjoin(g_result, num);
	i = 0;
	while (++i < params->width - ((params->precision > params->len) ?
		params->precision : params->len))
		g_result = ft_strjoin_my(g_result, " ");
}

void			ft_place_pl_int(char *num, t_par *params)
{
	int			i;

	// if (params->width == -1 && num[0] == '0' && params->len == 1)
	// 	return ;
	i = 0;
	while (++i < params->width - ((params->precision > params->len) ?
		params->precision : params->len) && M_PAR(zeroes) == 0)
		g_result = ft_strjoin_my(g_result, " ");
	if (params->below_zero > 0)
		g_result = ft_strjoin_my(g_result, "-");
	else
		g_result = ft_strjoin_my(g_result, "+");
	i = 0;
	while (++i < params->width - ((params->precision > params->len) ?
		params->precision : params->len) && M_PAR(zeroes) > 0)
		g_result = ft_strjoin_my(g_result, "0");
	if (params->width <= params->len && params->precision <= params->len)
	{
		g_result = ft_strjoin(g_result, num);
		return ;
	}
	i = -1;
	if (params->precision > params->len)
		while (++i < params->precision - params->len)
			g_result = ft_strjoin_my(g_result, "0");
	g_result = ft_strjoin(g_result, num);
}
