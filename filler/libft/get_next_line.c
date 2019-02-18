/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 15:14:52 by kbakhari          #+#    #+#             */
/*   Updated: 2018/11/12 15:50:39 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*fd_ex(size_t fd, t_list **head)
{
	t_list	*tempo;
	t_list	*new;

	tempo = *head;
	if (tempo)
	{
		if (tempo->content_size == fd)
			return (tempo);
		while (tempo != NULL)
		{
			if (tempo->content_size == fd)
				return (tempo);
			tempo = tempo->next;
		}
	}
	new = ft_lstnew("", fd);
	ft_lstadd(head, new);
	return (new);
}

static void		deletion(size_t fd, t_list **head)
{
	t_list	*to_del;
	t_list	*to_save;

	to_save = *head;
	if (to_save->content_size == fd)
	{
		(*head) = (*head)->next;
		free(to_save->content);
		free(to_save);
		return ;
	}
	while (to_save->next->content_size != fd && to_save->next)
		to_save = to_save->next;
	to_del = to_save->next;
	to_save->next = to_save->next->next;
	free(to_del->content);
}

static int		read_it(int fd, t_list **current)
{
	char	*temp;
	char	*temp2;
	int		res;

	if (!(temp = ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	while ((res = read(fd, temp, BUFF_SIZE)))
	{
		temp[res] = '\0';
		temp2 = (*current)->content;
		(*current)->content = ft_strjoin((*current)->content, temp);
		free(temp2);
		if (ft_strchr((*current)->content, '\n'))
			break ;
	}
	free(temp);
	return (0);
}

static int		fill_line(char ***line, t_list **current)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (*current)->content;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	if (ft_strlen((*current)->content) == 0)
		return (0);
	**line = ft_strsub((*current)->content, 0, i);
	if (tmp[ft_strlen(**line)] != '\n')
		(*current)->content = ft_strdup(ft_strrchr(tmp, '\0'));
	else
		(*current)->content = ft_strdup(ft_strchr(tmp, '\n') + 1);
	free(tmp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*current;
	char			c;

	if (fd < 0 || !line || read(fd, &c, 0 || BUFF_SIZE < 1))
		return (-1);
	if (list == NULL)
		if (!(list = ft_lstnew("", fd)))
			return (-1);
	current = fd_ex(fd, &list);
	read_it(fd, &current);
	if (fill_line(&line, &current) == 0)
	{
		deletion(fd, &list);
		return (0);
	}
	return (1);
}
