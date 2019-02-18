/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:45:49 by kbakhari          #+#    #+#             */
/*   Updated: 2019/02/11 06:10:49 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

t_cord		*ft_start_coord(void)
{
	t_cord	*new;

	new = (t_cord*)malloc(sizeof(t_cord));
	new->x = 0;
	new->y = 0;
	return (new);
}

int			ft_find_closest(t_cord *coor, t_pos **lst)
{
	int		i;
	int		j;
	int		enemy;
	int		res;
	int		temp;

	res = 100000;
	i = 0;
	enemy = (*lst)->player == 1 ? -1 : -2;
	while (i < (*lst)->pl_rows)
	{
		j = 0;
		while (j < (*lst)->pl_cols)
		{
			if ((*lst)->resmap[i][j] == enemy)
			{
				temp = (i - coor->x > 0 ?  i - coor->x : coor->x - i) +
				(j - coor->y > 0 ?  j - coor->y : coor->y - j);
				res =  temp > res ? res : temp;
			}
			j++;
		}
		i++;
	}
	return (res);
}

t_pos		*ft_populate_res(t_pos *lst)
{
	t_cord	*coor;
	int		i;

	i = 0;

	coor = ft_start_coord();
	while (coor->x < lst->pl_rows)
	{
		coor->y = 0;
		while (coor->y < lst->pl_cols)
		{
			if (lst->resmap[coor->x][coor->y] >= 0)
				lst->resmap[coor->x][coor->y] = ft_find_closest(coor, &lst);
			coor->y++;
		}
		coor->x++;
	}
	free(coor);
	return (lst);
}

// lst->map -> карта дефолт
// lst->resmap -> карта с расстояниями

int			main(void)
{
	t_pos	*lst;

	lst = ft_start_list();
	lst->player = ft_check_player();
	while(1)
	{
		if (ft_check_plateau(&lst) < 0)
			break ;
		if (ft_check_map(&lst) < 0 || ft_check_piece(&lst) < 0 ||
			ft_get_piece(&lst) < 0)
			return (1);
		ft_start_resmap(&lst);
		lst = ft_populate_res(lst);
		// printf("ROWS: %d| COLS: %d\n", lst->pl_rows, lst->pl_cols);
		// printf("\nX: %d| Y: %d\n", lst->fig_x, lst->fig_y);
		// for (int i = 0; lst->map[i]; i++)
		// 	printf("|%s|\n", lst->map[i]);
		// printf("\n_______________\n");
		// for (int i = 0; lst->piece[i]; i++)
		// 	printf("|%s|\n", lst->piece[i]);
		// printf("\n_______________\n");
		// for (int i = 0; i < lst->pl_rows; i++)
		// {
		// 	for (int j = 0; j < lst->pl_cols; j++)
		// 		printf("|%d|	", lst->resmap[i][j]);
		// 	printf("\n");
		// }
		// break ;
	}
	system("leaks kbakhari.filler");
	return (0);
}
