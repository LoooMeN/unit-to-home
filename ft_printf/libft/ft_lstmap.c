/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:41:21 by kbakhari          #+#    #+#             */
/*   Updated: 2018/11/02 15:14:44 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst2;

	if (lst != NULL && f != NULL)
	{
		if (!(lst2 = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		if (lst != NULL)
		{
			lst2 = f(lst);
			lst2->next = ft_lstmap(lst->next, f);
		}
		else
			(lst2->next = NULL);
		return (lst2);
	}
	return (NULL);
}
