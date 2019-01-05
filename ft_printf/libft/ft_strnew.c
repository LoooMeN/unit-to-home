/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:40:54 by kbakhari          #+#    #+#             */
/*   Updated: 2018/10/29 16:56:51 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (size-- > 0)
		res[i++] = 0;
	res[i] = '\0';
	return (res);
}
