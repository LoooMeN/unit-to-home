
#include "../includes/ft_printf.h"

t_par		*ft_ini_struct(void)
{
	t_par	*params;

	if (!(params = (t_par*)malloc(sizeof(t_par))))
		return (NULL);
	params->minus = 0;
	params->plus = 0;
	params->below_zero = 0;
	params->zeroes = 0;
	params->space = 0;
	params->width = -1;
	params->precision = -1;
	params->hash = 0;
	params->len = 0;
	params->zero = 0;
	return (params);
}

int				ft_width_precision_int(char *num, t_par *params)
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
		else if (g_flags[i] == '.' && (g_flags[i + 1] >= '0' && g_flags[i + 1] <= '9'))
			while (g_flags[i + 1] >= '0' && g_flags[i + 1] <= '9')
				i++;
		i++;
	}
	if (ft_strchr(g_flags, '.'))
		params->precision = ft_atoi(ft_strrchr(g_flags, '.') + 1);
	if (params->plus == 0 && params->minus == 0)
		ft_place_int(num, params);
	else if (params->plus > 0 && params->minus > 0)
		ft_place_plmi_int(num, params);
	else if (params->minus > 0)
		ft_place_mi_int(num, params);
	else
		ft_place_pl_int(num, params);
	return (0);
}

char	*ft_cut_one(char *s1)
{
	char	*temp;

	temp = s1;
	s1 = ft_strsub(s1, 1, ft_strlen(s1) - 1);
	free(temp);
	return (s1);
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