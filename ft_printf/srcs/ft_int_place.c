
#include "../includes/ft_printf.h"

void			ft_place(char *num, t_par *params)
{
	int			i;

	i = 0;
	if (params->space > 0 && params->below_zero == 0)
		g_result = ft_strjoin_my(g_result, " ");
	if (params->width == -1 && num[0] == '0' && params->len == 1)
		return ;
	else if (params->width <= params->len && params->precision <= params->len)
	{
		if (params->below_zero > 0)
			g_result = ft_strjoin_my(g_result, "-");
		g_result = ft_strjoin(g_result, num);
	}
	else if (params->width > params->len)
	{
		i += (params->below_zero > 0) ? 1 : 0;
		while (i < params->width - ((params->precision > params->len) ? params->precision : params->len))
		{
			if (params->zeroes > 0)
				g_result = ft_strjoin_my(g_result, "0");
			else
				g_result = ft_strjoin_my(g_result, " ");
			i++;
		}
	}
	// printf("TEST: %d\n", (params->precision > len) ? params->precision : len);
	i = 0;
	if (params->below_zero > 0)
		g_result = ft_strjoin_my(g_result, "-");
	while (i < params->precision - params->len)
	{
		// printf("HELLO\n");
		g_result = ft_strjoin_my(g_result, "0");
		i++;
	}
	g_result = ft_strjoin(g_result, num);
}

void			ft_place_plmi(char *num, t_par *params)
{
	if (params->width == -1 && num[0] == '0' && params->len == 1)
		return ;
	if (params->below_zero > 0)
		g_result = ft_strjoin_my(g_result, "-");
	else
		g_result = ft_strjoin_my(g_result, "+");
	if (params->width <= params->len && params->precision <= params->len)
		g_result = ft_strjoin(g_result, num);

}

int				ft_width_precision(char *num, t_par *params)
{
	int			i;

	i = 0;
	while (g_flags[i])
	{
		if (g_flags[i] >= '0' && g_flags[i] <= '9')
		{
			params->width = ft_atoi(&g_flags[i]);
			break;
		}
		else if (g_flags[i] == '.')
			break;
		i++;
	}
	params->precision = ft_atoi(ft_strrchr(g_flags, '.') + 1);
	if (params->plus == 0 && params->minus == 0)
		ft_place(num, params);
	else if (params->plus > 0 && params->minus > 0)
		ft_place_plmi(num, params);
	// printf(" WIDTH: |%d| PRECISION: |%d|\n", params->width, params->precision);
	return (0);
}

void			ft_int_place(int n)
{
	int			i;
	char		*result;
	t_par		*params;
	char		*temp;

	i = 0;
	params = ft_ini_struct();
	while (g_flags[i])
	{
		params->minus += (g_flags[i] == '-') ? 1 : 0;
		params->plus += (g_flags[i] == '+') ? 1 : 0;
		params->space += (g_flags[i] == ' ') ? 1 : 0;
		params->hash += (g_flags[i] == '#') ? 1 : 0;
		if (g_flags[i] == '0' && (g_flags[i - 1] > '9' || g_flags[i - 1] < '0'))
			params->zeroes = 1;
		i++;
	}
	params->below_zero += (n < 0) ? 1 : 0;
	// printf("HASH: |%d| MIN: |%d| PLUS: |%d| BELOW: |%d| ZEROES: |%d| SPACE: |%d|\n", params->hash, params->minus, params->plus, params->below_zero, params->zeroes, params->space);
	result = ft_itoa(n);
	params->len = (int)ft_strlen(result);
	if (n < 0)
	{
		temp = result;
		result = ft_strsub(result, 1, ft_strlen(result) + 1);
		free(temp);
	}
	// printf("TEST: %s\n", result);
	ft_width_precision(result, params);
}