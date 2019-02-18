/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 14:04:31 by kbakhari          #+#    #+#             */
/*   Updated: 2018/11/03 14:32:18 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(unsigned char *c, unsigned char *b)
{
	unsigned char	*a;

	a = (unsigned char *)malloc(sizeof(char));
	*a = *c;
	*c = *b;
	*b = *a;
	free(a);
}
