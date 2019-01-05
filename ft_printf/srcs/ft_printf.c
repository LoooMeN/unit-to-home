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
		ft_int_place(va_arg(list, int));
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

char	*ft_strjoin_my(char const *s1, char const *s2)
{
	char	*res;
	int		reslen;
	int		i;

	if (s1 != NULL && s2 != NULL)
	{
		i = -1;
		reslen = ft_strlen(s1) + 1;
		if (!(res = (char*)malloc(sizeof(char) * reslen + 1)))
			return (NULL);
		while (s1[++i])
			res[i] = s1[i];
		res[i++] = s2[0];
		res[i] = '\0';
		free((char*)s1);
		return (res);
	}
	return (0);
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

void		ft_death(char *str)
{
	ft_putstr(str);
	write(1, "\n", 1);
	if (g_flags)
		free(g_flags);
	exit(1);
}

int			main(void)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	i = printf("Hello %5.5d, SUKA, %d\n", 123, 456);
	n = ft_printf("Hello %5.5d, SUKA, %d\n", 123, 456);
	// printf("%d||%d\n", i, n);
	return (0);
}