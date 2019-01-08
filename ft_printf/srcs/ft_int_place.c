
#include "../includes/ft_printf.h"

static void	ft_place(char *num, int zeroes, int precision, int width)
{
	int 	i;
	int		minus;
	char	*temp;

	i = 0;
	minus = 0;
	if (num[0] == '-' && zeroes == 0)
	{
		temp = num;
		num = ft_strsub(num, 1, ft_strlen(num) - 1);
		g_result = ft_strjoin_my(g_result, "-");
		width--;
	}
	if (ft_strchr(g_flags, '-'))
		minus = 1;
	if (precision >= width)
	{
		if (minus > 0)
			g_result = ft_strjoin(g_result, num);
		while (precision - (int)ft_strlen(num) > 0)
		{
			if (zeroes != 0)
				g_result = ft_strjoin_my(g_result, " ");
			else
				g_result = ft_strjoin_my(g_result, "0");
			precision--;
		}
		if (minus == 0)
			g_result = ft_strjoin(g_result, num);
	}
	else if (width > precision)
	{
		if (minus > 0)
			g_result = ft_strjoin(g_result, num);
		if (width > (int)ft_strlen(num))
		{
			while (width > precision && precision > (int)ft_strlen(num))
			{
				g_result = ft_strjoin_my(g_result, " ");
				width--;
			}
		}
		while (width - (int)ft_strlen(num) > 0)
		{
			if (zeroes == 0)
				g_result = ft_strjoin_my(g_result, " ");
			else if (precision < (int)ft_strlen(num))
				g_result = ft_strjoin_my(g_result, "0");
			width--;
		}
		if (minus == 0)
			g_result = ft_strjoin(g_result, num);
	}
}

int			ft_width_precision(char *num)
{
	int		i;
	int		width;
	char	*dot;
	int		precision;
	int		zeroes;

	i = 0;
	width = -1;
	precision = 0;
	zeroes = 0;
	while (g_flags[i])
	{
		if (g_flags[i] >= '0' && g_flags[i] <= '9' && width == -1 && g_flags[i - 1] != '.')
			width = ft_atoi(&g_flags[i]);
		if (g_flags[i] == '.' && (g_flags[i + 1] < '0' || g_flags[i + 1] > '9'))
			width = ft_atoi(&g_flags[i + 1]);
		i++;
	}
	if ((dot = ft_strrchr(g_flags, '.')))
	{
		while (dot[zeroes] < '0' || dot[zeroes] > '9')
			zeroes++;
		precision = ft_atoi(&dot[zeroes]);
	}
	zeroes = 0;
	i = 0;
	while (g_flags[i])
	{
		if (g_flags[i] == '0')
			if (i == 0 || (g_flags[i - 1] == '.' ||
			 g_flags[i - 1] >= '0' || g_flags[i - 1] <= '9'))
				zeroes = 1;
		i++;
	}
	// if (g_minus == 1)
	// {
	// 	width -= (width == -1) ? 0 : 1;
	// 	precision -= (precision == 0) ? 0 : 1;
	// }
	ft_place(num, zeroes, precision, width);
	return (1);
}

void		ft_int_place(int n)
{
	int		i;
	int		error;
	char	*result;

	i = 0;
	error = 0;
	g_minus = 0;
	while (g_flags[i])
	{
		if (g_flags[i] == '+')
		{
			if (error == 1)
				ft_death("error: space ignored because of +");
			error = 1;
			if (n > 0)
			{
				g_result = ft_strjoin_my(g_result, "+");
				g_res_num++;
			}
		}
		else if (g_flags[i] == ' ')
		{
			if (error == 1)
				ft_death("error: space ignored because of +");
			error = 1;
			if (n >= 0)
				g_result = ft_strjoin_my(g_result, " ");
			g_res_num++;
		}
		else if (g_flags[i] == '#')
			ft_death("# incompatible with d/i");
		i++;
	}
	result = ft_itoa(n);
	ft_width_precision(result);
}