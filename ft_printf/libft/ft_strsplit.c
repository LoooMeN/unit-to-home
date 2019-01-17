/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:58:10 by kbakhari          #+#    #+#             */
/*   Updated: 2018/10/31 17:34:29 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_word_count(char	const *s, char c)
{
	size_t		j;
	size_t		i;

	j = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c) || s[i + 1] == '\0')
			j++;
		i++;
	}
	return (j);
}

static size_t		ft_word_len(char const *s, char c, size_t i)
{
	size_t		j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t		i;
	char		**res;
	size_t		word;
	int			j;

	i = 0;
	word = -1;
	if (s)
	{
		if (!(res = (char**)malloc(sizeof(char*) * ft_word_count(s, c) + 1)))
			return (NULL);
		while (++word < ft_word_count(s, c))
		{
			while (s[i] == c)
				i++;
			res[word] = MYLLOC(ft_word_len(s, c, i) + 1);
			j = 0;
			while (i < (i + ft_word_len(s, c, i)) && s[i] != c)
				res[word][j++] = s[i++];
			res[word][j] = '\0';
		}
		res[word] = NULL;
		return (res);
	}
	return (NULL);
}
