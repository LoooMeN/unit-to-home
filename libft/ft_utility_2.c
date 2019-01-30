/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:34:46 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/24 10:35:04 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_set_hash(t_par **params)
{
	g_result = ft_strjoin(g_result, (g_format == 'X' ? "0X" : "0x"));
	(*params)->hash = 0;
}

char		*ft_shift(char *str, char flag)
{
	int		i;
	char	*result;

	if (!(result = (char*)malloc(sizeof(char) * ft_strlen(str) +
		((flag == 'o') ? 2 : 3))))
		return (NULL);
	if (flag == 'o')
	{
		result[0] = '0';
		i = 1;
	}
	else
	{
		result[0] = '0';
		result[1] = 'x';
		i = 2;
	}
	while (str[i - (flag == 'x' ? 2 : 1)])
	{
		result[i] = str[i - (flag == 'x' ? 2 : 1)];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char		*ft_cut_one(char *s1)
{
	char	*temp;

	temp = s1;
	s1 = ft_strsub(s1, 1, ft_strlen(s1) - 1);
	free(temp);
	return (s1);
}
