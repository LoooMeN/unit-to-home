/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:39:10 by kbakhari          #+#    #+#             */
/*   Updated: 2018/10/30 15:28:41 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n <= -2147483648)
			write(fd, "-2147483648", 11);
		else
		{
			n = -n;
			write(fd, "-", 1);
		}
	}
	if (n <= 9 && n >= 0 && n >= 0)
		ft_putchar_fd(n + '0', fd);
	else if (n >= 0)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}