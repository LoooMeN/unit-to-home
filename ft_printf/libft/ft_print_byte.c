/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_byte.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:35:32 by kbakhari          #+#    #+#             */
/*   Updated: 2018/10/25 18:41:46 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_byte(unsigned char c)
{
	int		count;

	count = 8;
	while (count--)
	{
		if ((c >> count & 1) == 0)
			write(1, "0", 1);
		else
			write(1, "1", 1);
	}
}
