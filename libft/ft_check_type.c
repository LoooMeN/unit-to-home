/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:22:53 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/24 10:23:08 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_next_4(va_list list, char format)
{
	if (format == 'f' || format == 'F')
	{
		if (ft_strchr(g_flags, 'L'))
			ft_f_place(va_arg(list, long double), format);
		else
			ft_f_place(va_arg(list, double), format);
	}
}

static void	ft_next_3(va_list list, char format)
{
	if (format == 'x' || format == 'X')
	{
		if (ft_strchr(g_flags, 'l'))
			ft_xl_place(va_arg(list, unsigned long int), format);
		else if (ft_strchr(g_flags, 'h'))
		{
			if (ft_strchr(g_flags, 'h') && ft_strchr(ft_strchr(g_flags, 'h')
				+ 1, 'h'))
				ft_hhx_place(va_arg(list, unsigned int), format);
			else
				ft_hx_place((unsigned short int)va_arg(list, unsigned int),
					format);
		}
		else
			ft_x_place(va_arg(list, unsigned int), format);
	}
	ft_next_4(list, format);
}

static void	ft_next_2(va_list list, char format)
{
	if (format == 'o')
	{
		if (ft_strchr(g_flags, 'l'))
			ft_ol_place(va_arg(list, unsigned long int));
		else if (ft_strchr(g_flags, 'h'))
		{
			if (ft_strchr(g_flags, 'h') && ft_strchr(ft_strchr(g_flags, 'h')
				+ 1, 'h'))
				ft_hho_place(va_arg(list, unsigned int));
			else
				ft_ho_place((unsigned short int)va_arg(list, unsigned int));
		}
		else
			ft_o_place(va_arg(list, unsigned int));
	}
	ft_next_3(list, format);
}

static void	ft_next_1(va_list list, char format)
{
	if (format == 'u')
	{
		if (ft_strchr(g_flags, 'l'))
			ft_ul_place(va_arg(list, unsigned long int));
		else if (ft_strchr(g_flags, 'h'))
		{
			if (ft_strchr(g_flags, 'h') && ft_strchr(ft_strchr(g_flags, 'h')
				+ 1, 'h'))
				ft_hhu_place(va_arg(list, unsigned int));
			else
				ft_hu_place((unsigned short int)va_arg(list, unsigned int));
		}
		else
			ft_u_place(va_arg(list, unsigned int));
	}
	ft_next_2(list, format);
}

void		ft_check_type(va_list list, char format)
{
	if (format == 'c')
		ft_char_place(va_arg(list, int));
	else if (format == '%')
		ft_per_place('%');
	else if (format == 's')
		ft_string_place(va_arg(list, char*));
	else if (format == 'p')
		ft_p_place(va_arg(list, int));
	else if (format == 'd' || format == 'i')
	{
		if (ft_strchr(g_flags, 'l'))
			ft_lint_place(va_arg(list, long long int));
		else if (ft_strchr(g_flags, 'h'))
		{
			if (ft_strchr(g_flags, 'h') && ft_strchr(ft_strchr(g_flags, 'h')
				+ 1, 'h'))
				ft_hhint_place((short int)va_arg(list, int));
			else
				ft_hint_place(va_arg(list, int));
		}
		else
			ft_int_place(va_arg(list, int));
	}
	ft_next_1(list, format);
}
