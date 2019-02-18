/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:10:47 by kbakhari          #+#    #+#             */
/*   Updated: 2019/02/12 15:10:50 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_check_player(void)
{
	int		player;
	char	*str;

	get_next_line(0, &str);
	player = 0;
	if (ft_strstr(str, "p1"))
	{
		if (ft_strstr(str, "kbakhari"))
			player = 1;
		else
			player = 2;
	}
	else
	{
		if (ft_strstr(str, "kbakhari"))
			player = 2;
		else
			player = 1; 
	}
	free(str);
	return (player);
}

int			ft_check_piece(t_pos **list)
{
	int		i;
	char	*line;

	get_next_line(0, &line);
	if (!ft_strstr(line, "Piece"))
	{
		free(line);
		return (-1);
	}
	i = 0;
	while (line[i] > '9' || line[i] < '0')
		i++;
	if ((*list)->fig_x == 0)
	{
		(*list)->fig_x = ft_atoi(&line[i]);
		while (line[i] <= '9' && line[i] >= '0')
			i++;
	}
	if ((*list)->fig_x != 0)
		(*list)->fig_y = ft_atoi(&line[i]);
	free(line);
	if ((*list)->fig_y == 0 || (*list)->fig_y == 0)
		return (-1);
	return (0);
}

int			ft_check_plateau(t_pos **list)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	if (ft_strcmp(line, "\0") == 0 || !ft_strstr(line, (*list)->plateau))
	{
		free(line);
		return (-1);
	}
	i = 0;
	while (line[i] > '9' || line[i] < '0')
		i++;
	if ((*list)->pl_rows == 0)
	{
		(*list)->pl_rows = ft_atoi(&line[i]);
		while (line[i] <= '9' && line[i] >= '0')
			i++;
	}
	if ((*list)->pl_rows != 0)
		(*list)->pl_cols = ft_atoi(&line[i]);
	free(line);
	if ((*list)->pl_cols == 0 || (*list)->pl_rows == 0)
		return (-1);
	return (0);
}

int			ft_check_map(t_pos **lst)
{
	int		i;
	int		j;
	char	*line;

	(*lst)->map = (char**)malloc(sizeof(char*) * (*lst)->pl_rows);
	get_next_line(0, &line);
	free(line);
	i = -1;
	while (++i < (*lst)->pl_rows)
	{
		j = 0;
		get_next_line(0, &line);
		(*lst)->map[i] = ft_strsub(line, 4, (int)ft_strlen(line) - 4);
		while ((*lst)->map[i][j])
		{
			if ((*lst)->map[i][j] != '.' && (*lst)->map[i][j] != 'X' &&
				(*lst)->map[i][j] != 'O' && (*lst)->map[i][j] != 'x' &&
				(*lst)->map[i][j] != 'o' && (*lst)->map[i][j] != '\n')
				return (-1);
			j++;
		}
		free(line);
	}	
	(*lst)->map[i] = NULL;
	return (0);
}

t_pos		*ft_start_list(void)
{
	t_pos	*new;

	new = (t_pos*)malloc(sizeof(t_pos));
	new->pl_rows = 0;
	new->pl_cols = 0;
	new->player = 0;
	new->fig_x = 0;
	new->fig_y = 0;
	new->plateau = "Plateau";
	new->map = NULL;
	return (new);
}

int			ft_get_piece(t_pos **lst)
{
	int		i;
	int		j;
	char	*line;

	(*lst)->piece = (char**)malloc(sizeof(char*) * (*lst)->fig_y);
	i = -1;
	while (++i < (*lst)->fig_x)
	{
		j = 0;
		get_next_line(0, &line);
		(*lst)->piece[i] = ft_strdup(line);
		while ((*lst)->piece[i][j])
		{
			if ((*lst)->piece[i][j] != '.' && (*lst)->piece[i][j] != '*' &&
				(*lst)->piece[i][j] != '\n')
				return (-1);
			j++;
		}
		free(line);
	}
	(*lst)->piece[i] = NULL;
	return (0);
}

void		ft_start_resmap(t_pos **lst)
{
	int		i;
	int		j;

	i = 0;
	(*lst)->resmap = (int**)malloc(sizeof(int*) * (*lst)->pl_rows + 1);
	while (i < (*lst)->pl_rows)
	{
		j = 0;
		(*lst)->resmap[i] = (int*)malloc(sizeof(int) * (*lst)->pl_cols + 1);
		while (j < (*lst)->pl_cols)
		{
			if ((*lst)->map[i][j] == 'X' || (*lst)->map[i][j] == 'x')
				(*lst)->resmap[i][j] = -2;
			else if ((*lst)->map[i][j] == 'O' || (*lst)->map[i][j] == 'o')
				(*lst)->resmap[i][j] = -1;
			else
				(*lst)->resmap[i][j] = 0;
			j++;
		}
		(*lst)->resmap[i][j] = 0;
		i++;
	}
	(*lst)->resmap[i] = 0;
}
