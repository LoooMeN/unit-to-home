/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lint_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:11:42 by kbakhari          #+#    #+#             */
/*   Updated: 2019/01/08 12:11:44 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_lint_place(long int n)
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
	result = ft_itol(n);
	ft_width_precision(result);
	temp = g_result;
	g_result = ft_strjoin(g_result, result);
	free(temp);
}