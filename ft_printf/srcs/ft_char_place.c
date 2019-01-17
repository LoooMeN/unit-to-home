/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:19:11 by kbakhari          #+#    #+#             */
/*   Updated: 2018/12/05 15:19:12 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_char_place(char c)
{
	char	*temp;

	temp = g_result;
	g_result = ft_strjoin_my(g_result, &c);
	free(temp);
}