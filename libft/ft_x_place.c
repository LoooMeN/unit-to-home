/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 02:45:10 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/24 08:08:04 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_width_precision_x(char *num, t_par *params)
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
	if (params->minus > 0)
		ft_place_mi_x(num, params, -1);
	else
		ft_place_x(num, params);
}

void			ft_x_place(unsigned int n, char format)
{
	int			i;
	char		*result;
	t_par		*params;

	i = 0;
	params = ft_fill_struct(ft_ini_struct());
	params->zero += (n == 0) ? 1 : 0;
	result = ft_itoa_base(n, 16, format);
	g_format = format;
	params->len = (int)ft_strlen(result);
	ft_width_precision_x(result, params);
}

void			ft_xl_place(unsigned long int n, char format)
{
	int			i;
	char		*result;
	t_par		*params;

	i = 0;
	params = ft_fill_struct(ft_ini_struct());
	params->zero += (n == 0) ? 1 : 0;
	if ((long long int)n < -9223372036854775807)
		result = ft_strdup("8000000000000000");
	else
		result = ft_itoa_base(n, 16, format);
	g_format = format;
	params->len = (int)ft_strlen(result);
	ft_width_precision_x(result, params);
}

void			ft_hhx_place(unsigned int n, char format)
{
	int			i;
	char		*result;
	t_par		*params;

	i = 0;
	params = ft_fill_struct(ft_ini_struct());
	params->zero += (n == 0) ? 1 : 0;
	result = ft_itoa_base((unsigned char)n, 16, format);
	g_format = format;
	params->len = (int)ft_strlen(result);
	ft_width_precision_x(result, params);
}

void			ft_hx_place(unsigned short int n, char format)
{
	int			i;
	char		*result;
	t_par		*params;

	i = 0;
	params = ft_fill_struct(ft_ini_struct());
	params->zero += (n == 0) ? 1 : 0;
	result = ft_itoa_base(n, 16, format);
	g_format = format;
	params->len = (int)ft_strlen(result);
	ft_width_precision_x(result, params);
}
