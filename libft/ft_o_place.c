/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 08:06:43 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/24 08:06:45 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_width_precision_o(char *num, t_par *params)
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
	M_PAR(precision) += (M_PAR(precision) == 0 && M_PAR(hash) > 0) ? 1 : 0;
	if (params->minus > 0)
		ft_place_mi_u(num, params);
	else
		ft_place_u(num, params);
	return (0);
}

void		ft_o_place(unsigned int n)
{
	int		i;
	char	*result;
	t_par	*params;

	i = 0;
	params = ft_fill_struct(ft_ini_struct());
	params->zero += (n == 0) ? 1 : 0;
	result = ft_itol(ft_o_convert(n));
	if (params->hash > 0 && n != 0)
		result = ft_shift(result, 'o');
	params->len = (int)ft_strlen(result);
	M_PAR(hash) += ft_strchr(result, '#') ? 1 : 0;
	ft_width_precision_o(result, params);
}

void		ft_ol_place(unsigned long int n)
{
	int		i;
	char	*result;
	t_par	*params;

	i = 0;
	params = ft_fill_struct(ft_ini_struct());
	params->zero += (n == 0) ? 1 : 0;
	if ((long long int)n < -9223372036854775807)
		result = ft_strdup("1000000000000000000000");
	else
		result = ft_itoa_base(n, 8, 'x');
	if (params->hash > 0 && n != 0)
		result = ft_shift(result, 'o');
	params->len = (int)ft_strlen(result);
	M_PAR(hash) += ft_strchr(result, '#') ? 1 : 0;
	ft_width_precision_o(result, params);
}

void		ft_ho_place(unsigned short int n)
{
	int		i;
	char	*result;
	t_par	*params;

	i = 0;
	params = ft_fill_struct(ft_ini_struct());
	params->zero += (n == 0) ? 1 : 0;
	result = ft_utoa(ft_o_convert(n));
	if (params->hash > 0 && n != 0)
		result = ft_shift(result, 'o');
	params->len = (int)ft_strlen(result);
	M_PAR(hash) += ft_strchr(result, '#') ? 1 : 0;
	ft_width_precision_o(result, params);
}

void		ft_hho_place(unsigned int n)
{
	int		i;
	char	*result;
	t_par	*params;

	i = 0;
	params = ft_fill_struct(ft_ini_struct());
	params->zero += (n == 0) ? 1 : 0;
	result = ft_utoa(ft_o_convert((unsigned char)n));
	if (params->hash > 0 && n != 0)
		result = ft_shift(result, 'o');
	params->len = (int)ft_strlen(result);
	M_PAR(hash) += ft_strchr(result, '#') ? 1 : 0;
	ft_width_precision_o(result, params);
}
