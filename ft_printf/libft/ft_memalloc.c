/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:09:54 by kbakhari          #+#    #+#             */
/*   Updated: 2018/10/29 12:29:17 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;
	int		i;

	i = 0;
	if (!(res = (void*)malloc(sizeof(void) * size)))
		return (NULL);
	while (size-- > 0)
		((unsigned char *)res)[i++] = 0;
	return (res);
}
