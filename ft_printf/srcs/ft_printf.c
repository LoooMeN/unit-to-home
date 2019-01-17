/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:55:07 by kbakhari          #+#    #+#             */
/*   Updated: 2018/12/04 16:55:07 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_check_type(va_list list, char format)
{
	if (format == 'c')
		ft_char_place(va_arg(list, int));
	else if (format == 's')
		ft_string_place(va_arg(list, char*));
	else if (format == 'p')
		ft_char_place(va_arg(list, int));
	else if (format == 'd' || format == 'i')
	{
		// if (ft_strchr(g_flags, 'l'))
		// 	ft_iint_place(va_arg(list, long));
		// else
		ft_int_place(va_arg(list, int));
	}
}

char		*ft_get_flags(char *format, int i)
{
	int		j;
	char	*res;

	j = i;
	while (format[i] != 'c' && format[i] != 's' && format[i] != 'p' && format[i] != 'i'  && format[i] != 'd')
		i++;
	i -= j;
	res = (char*)malloc(sizeof(char) * i + 1);
	i = 0;
	while (format[j] != 'c' && format[j] != 's' && format[j] != 'p' && format[j] != 'i'  && format[j] != 'd')
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

	i = 0;
	g_result = (char*)malloc(sizeof(char));
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			i++;
			g_flags = ft_get_flags(format, i);
			i += ft_strlen(g_flags);
			ft_check_type(list, format[i]);
			free(g_flags);
		}
		else
		{
			g_result = ft_strjoin_my(g_result, &format[i]);
			if (format[i] == '%')
				i++;
		}
		i++;
	}
	ft_putstr(g_result);
	va_end(list);
	reslen = ft_strlen(g_result);
	free(g_result);
	return (reslen);
}

int			main(void)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	i = printf("Hello |%4.7d|\n", 12345);
	n = ft_printf("Hello |%4.7d|\n", 12345);
	printf("%d||%d\n", i, n);
	return (0);
}