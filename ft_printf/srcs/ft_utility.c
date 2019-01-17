
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
	params->precision = 0;
	params->hash = 0;
	params->len = 0;
	return (params);
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