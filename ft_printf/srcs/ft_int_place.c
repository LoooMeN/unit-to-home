
#include "../includes/ft_printf.h"

void		ft_place(char *num, int zeroes, int precision, int width)
{
	int		below_zero;
	char	*temp;
	int		i;

	below_zero = 0;
	if (g_minus >= 1)
	{
		if (g_plus == 1)
		{
			g_result = ft_strjoin_my(g_result, "+");
			g_plus = -1;
		}
		g_result = ft_strjoin(g_result, num);
		zeroes = 0;
	}
	if (num[0] == '-')
	{
		below_zero = 1;
		precision++;
	}
	while (width - precision > i && precision != 0 && width - precision < (int)ft_strlen(num))
	{
		if (below_zero == 1)
			i++;
		g_result = ft_strjoin_my(g_result, " ");
		i++;
	}
	while (width - precision + ((precision > 0) ? 1 : 0) > (int)ft_strlen(num) || width -1 == (int)ft_strlen(num))
	{
		if (zeroes == 1)
		{
			if (below_zero == 1)
			{
				g_result = ft_strjoin_my(g_result, "-");
				below_zero = -1;
			}
			if (g_plus == 1)
			{
				g_result = ft_strjoin_my(g_result, "+");
				g_plus = -1;
			}
			g_result = ft_strjoin_my(g_result, "0");
		}
		else
			g_result = ft_strjoin_my(g_result, " ");
		width--;
	}
	while (precision > (int)ft_strlen(num))
	{
		if (below_zero == 1)
		{
			g_result = ft_strjoin_my(g_result, "-");
			below_zero = -1;
		}
		if (g_plus == 1)
		{
			g_result = ft_strjoin_my(g_result, "+");
			g_plus = -1;
		}
		g_result = ft_strjoin_my(g_result, "0");
		precision--;	
	}
	if (g_plus == 1)
	{
		g_result = ft_strjoin_my(g_result, "+");
		g_plus = -1;
	}
	if (g_minus != 1)
	{
		if (below_zero == -1)
			g_result = ft_strjoin(g_result, num + 1);
		else
			g_result = ft_strjoin(g_result, num);
	}
}

int			ft_width_precision(char *num, int flag)
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
	g_minus = 0;
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
			 g_flags[i - 1] < '0' || g_flags[i - 1] > '9'))
				zeroes = 1;
		if (g_flags[i] == '-')
			g_minus++;
		i++;
	}
	// printf("\nWIDTH: %d | PRECISION: %d | ZEROES: %d\n\n", width, precision, zeroes);
	if (flag == 1)
		width -= 1;
	if (g_plus == 1)
		width -= 1;
	ft_place(num, zeroes, precision, width);
	return (1);
}

void		ft_int_place(int n)
{
	int		i;
	char	*result;
	int		flag;

	i = 0;
	g_minus = 0;
	g_plus = 0;
	flag = 0;
	while (g_flags[i])
	{
		if (g_flags[i] == '+')
			if (n > 0)
				g_plus = 1;
		if (g_flags[i] == ' ' && flag != 1)
		{
			if (n >= 0)
			{
				g_result = ft_strjoin_my(g_result, " ");
				flag = 1;
			}
		}
		i++;
	}
	result = ft_itoa(n);
	ft_width_precision(result,  flag);
}