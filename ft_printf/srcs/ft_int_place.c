
#include "../includes/ft_printf.h"

static	void	ft_place(char *num, t_par *params)
{
	int		i;

	i = -1;
	if (params->below_zero == 0 && params->space > 0)
		g_result = ft_strjoin_my(g_result, " ");
	if (params->width <= (int)ft_strlen(num) && params->precision <= (int)ft_strlen(num))
	{
		if (params->width == -1 && num[0] == 0 && ft_strlen(num) == 1)
			g_result = ft_strjoin_my(g_result, "");
		else
		{
			if (params->below_zero > 0)
				g_result = ft_strjoin_my(g_result, "-");
			g_result = ft_strjoin(g_result, num);
		}
	}
	else if ((int)ft_strlen(num) > params->precision && params->zeroes > 0)
	{
		while (++i < params->width - (int)ft_strlen(num))
		{
			if (params->precision == 0)
				g_result = ft_strjoin_my(g_result, "0");
			else
				g_result = ft_strjoin_my(g_result, " ");
		}
		i = -1;
	}
	else if ((int)ft_strlen(num) > params->precision)
	{
		while (++i < params->width - (int)ft_strlen(num))
		{
			if (params->precision == 0)
				g_result = ft_strjoin_my(g_result, "0");
			else
				g_result = ft_strjoin_my(g_result, " ");
		}
		i = -1;
	}
	else if (params->precision > (int)ft_strlen(num))
	{
		while (++i < params->width - (int)ft_strlen(num))
			g_result = ft_strjoin_my(g_result, " ");
		if (params->below_zero > 0)
				g_result = ft_strjoin_my(g_result, "-");
	}
	else
	{
		g_result = ft_strjoin_my(g_result, " ");
		if (params->below_zero > 0)
			g_result = ft_strjoin_my(g_result, "-");
	}
	if (params->width == -1 && num[0] == 0 && ft_strlen(num) == 1)
		g_result = ft_strjoin_my(g_result, "");
	else
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
	ft_place(num, params);
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
	if (n < 0)
	{
		temp = result;
		result = ft_strsub(result, 1, ft_strlen(result) + 1);
		free(temp);
	}
	// printf("TEST: %s\n", result);
	ft_width_precision(result, params);
}