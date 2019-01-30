/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_per_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 08:51:38 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/24 08:51:41 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_place_per(char *num, t_par *params)
{
	int			i;

	i = -1;
	if (M_PAR(minus) > 0)
		g_result = ft_strjoin(g_result, num);
	while (++i < M_PAR(width) - M_PAR(len))
		g_result = ft_strjoin_my(g_result, " ");
	if (M_PAR(minus) == 0)
		g_result = ft_strjoin(g_result, num);
}

void			ft_width_precision_per(char *num, t_par *params)
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
	ft_place_per(num, params);
}

void			ft_per_place(char n)
{
	int			i;
	char		*result;
	t_par		*params;

	i = 0;
	params = ft_fill_struct(ft_ini_struct());
	result = (char*)malloc(sizeof(char) + 1);
	result[0] = n;
	params->len = (int)ft_strlen(result);
	ft_width_precision_per(result, params);
}
