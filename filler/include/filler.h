/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:46:29 by kbakhari          #+#    #+#             */
/*   Updated: 2019/02/04 15:46:30 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"

# define M_ABS(value) value >= 0 ? value : -value

typedef struct 		s_cord
{
	int				x;
	int				y;
}					t_cord;

typedef struct		s_pos
{
	int 			pl_rows;
	int				pl_cols;
	int				player;
	int				fig_x;
	int				fig_y;
	char			*plateau;
	char			**map;
	char			**piece;
	int				**resmap;
}					t_pos;

t_pos				*ft_start_list(void);
t_cord				*ft_start_coord(void);
int					ft_check_player(void);
int					ft_check_plateau(t_pos **list);
int					ft_check_map(t_pos **lst);
int					ft_check_piece(t_pos **list);
int					ft_get_piece(t_pos **lst);
void				ft_start_resmap(t_pos **lst);

#endif
