/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_place.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:23:08 by kbakhari          #+#    #+#             */
/*   Updated: 2018/12/05 15:23:10 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_string_place(char *str)
{
	char	*temp;

	temp = g_result;
	g_result = ft_strjoin(g_result, str);
	free(temp);
}

