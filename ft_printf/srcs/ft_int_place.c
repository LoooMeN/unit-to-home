
#include "../includes/ft_printf.h"

int		ft_width_precision(char *num)
{
	int		i;
	int		width;
	int		zeroes;
	int		precision;

	i = 0;
	width = -1;
	zeroes = 0;
	precision = 0;
	while ((g_flags[i] == '0' || g_flags[i] < '0' || g_flags[i] > '9') && g_flags[i] != '\0')
	{
		if (g_flags[i] == '0' && g_flags[i + 1] != '.')
			zeroes = 1;
		else if (g_flags[i] == '0' && g_flags[i + 1] == '.')
			break;
		else if (g_flags[i] == '.')
			zeroes = -1;
		i++;
	}
	if (g_flags[i] >= '0' && g_flags[i] <= '9' && g_flags[i] != '\0' && zeroes >= 0)
		width = ft_atoi(&g_flags[i]);
	while (g_flags[i] >= '0' && g_flags[i] <= '9' && g_flags[i] != '\0' && zeroes >= 0)
		i++;
	if (g_flags[i] == '.')
		i++;
	if (g_flags[i] >= '0' && g_flags[i] <= '9' && g_flags[i] != '\0')
		precision = ft_atoi(&g_flags[i]);
	while (width - precision > (int)ft_strlen(num) || (width > precision && precision != 0))
	{
		if (zeroes == 1)
			g_result = ft_strjoin_my(g_result, "0");
		else
			g_result = ft_strjoin_my(g_result, " ");
		width--;
	}
	while (precision > (int)ft_strlen(num))
	{
		g_result = ft_strjoin_my(g_result, "0");
		precision--;
	}
	return (1);
}

void	ft_int_place(int n)
{
	int		i;
	int		error;
	char	*result;
	char	*temp;

	i = 0;
	error = 0;
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
	temp = g_result;
	g_result = ft_strjoin(g_result, result);
	free(temp);
}