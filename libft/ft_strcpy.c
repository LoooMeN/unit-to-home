/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:05:07 by kbakhari          #+#    #+#             */
/*   Updated: 2018/10/26 13:16:05 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*source;
	int		i;

	i = 0;
	source = (char *)src;
	while (source[i])
	{
		dst[i] = source[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
