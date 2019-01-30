/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:21:20 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/24 08:07:25 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_u_place(unsigned int n)
{
	int			i;
	char		*result;
	t_par		*params;

	i = 0;
	params = ft_fill_struct(ft_ini_struct());
	params->zero += (n == 0) ? 1 : 0;
	result = ft_itol(n);
	params->len = (int)ft_strlen(result);
	ft_width_precision_u(result, params);
}

void			ft_ul_place(unsigned long int n)
{
	int			i;
	char		*result;
	char		*temp;
	t_par		*params;

	i = 0;
	params = ft_fill_struct(ft_ini_struct());
	params->zero += (n == 0) ? 1 : 0;
	result = ft_itol(n);
	if (result[0] == '-')
	{
		temp = result;
		result = ft_strsub(result, 1, ft_strlen(result) - 1);
		free(temp);
	}
	params->len = (int)ft_strlen(result);
	ft_width_precision_u(result, params);
}

void			ft_hu_place(unsigned short int n)
{
	int			i;
	char		*result;
	t_par		*params;

	i = 0;
	params = ft_fill_struct(ft_ini_struct());
	params->zero += (n == 0) ? 1 : 0;
	result = ft_utoa(n);
	params->len = (int)ft_strlen(result);
	ft_width_precision_u(result, params);
}

void			ft_hhu_place(unsigned int n)
{
	int			i;
	char		*result;
	t_par		*params;

	i = 0;
	params = ft_fill_struct(ft_ini_struct());
	params->zero += (n == 0) ? 1 : 0;
	result = ft_utoa((unsigned char)n);
	params->len = (int)ft_strlen(result);
	ft_width_precision_u(result, params);
}

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
		else if (g_flags[i] == '.' && (g_flags[i + 1] >= '0' &&
			g_flags[i + 1] <= '9'))
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
