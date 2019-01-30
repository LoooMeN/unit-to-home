/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:55:07 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/24 08:06:58 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_get_flags(char *format, int i)
{
	int		j;
	char	*res;

	j = i;
	while (format[i] != 'c' && format[i] != 's' && format[i] != 'p' &&
		format[i] != 'i' && format[i] != 'd' && format[i] != 'u' && format[i]
		!= 'o' && format[i] != 'x' && format[i] != 'X' && format[i] != 'f'
		&& format[i] != 'F' && format[i] != '%')
		i++;
	i -= j;
	res = (char*)malloc(sizeof(char) * i + 1);
	i = 0;
	while (format[j] != 'c' && format[j] != 's' && format[j] != 'p' &&
		format[j] != 'i' && format[j] != 'd' && format[j] != 'u' && format[j]
		!= 'o' && format[j] != 'x' && format[j] != 'X' && format[j] != 'f'
		&& format[j] != 'F' && format[j] != '%')
	{
		res[i] = format[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

int			ft_printf(char *format, ...)
{
	va_list list;
	int		i;
	int		reslen;

	i = -1;
	g_kostil = 0;
	g_result = (char*)malloc(sizeof(char));
	va_start(list, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			g_flags = ft_get_flags(format, i);
			ft_check_type(list, format[i += ft_strlen(g_flags)]);
			free(g_flags);
		}
		else
			g_result = ft_strjoin_my(g_result, &format[i]);
	}
	ft_putstr(g_result);
	va_end(list);
	reslen = ft_strlen(g_result) + g_kostil;
	ft_bzero(g_result, ft_strlen(g_result));
	free(g_result);
	return (reslen);
}
