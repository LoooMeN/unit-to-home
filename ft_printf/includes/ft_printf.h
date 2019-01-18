/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:06:27 by kbakhari          #+#    #+#             */
/*   Updated: 2018/12/05 15:06:28 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/Includes/libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define M_PAR(x) params->x

int		g_minus;
int		g_plus;
char	*g_result;
char	*g_flags;

typedef	struct	s_par
{
	int			minus;
	int			plus;
	int			zeroes;
	int			below_zero;
	int			space;
	int			width;
	int			precision;
	int			hash;
	int			len;
	int			zero;
}				t_par;

void	ft_char_place(char n);
void	ft_string_place(char *str);
char	*ft_strjoin_my(char const *s1, char const *s2);
void	ft_int_place(int n);
void	ft_lint_place(long int n);
void	ft_hint_place(int n);
t_par	*ft_ini_struct(void);
char	*ft_itol(long int n);
int		ft_width_precision_int(char *num, t_par *params);
int		ft_printf(char *format, ...);
void	ft_place_int(char *num, t_par *params);
void	ft_place_plmi_int(char *num, t_par *params);
void	ft_place_mi_int(char *num, t_par *params);
void	ft_place_pl_int(char *num, t_par *params);
void	ft_hhint_place(int n);
char	*ft_cut_one(char *s1);
void	ft_u_place(unsigned int (n));
void	ft_place_u(char *num, t_par *params);
void	ft_place_mi_u(char *num, t_par *params);
void	ft_ul_place(unsigned long int n);
void	ft_hu_place(unsigned short int n);
void	ft_hhu_place(unsigned int n);

#endif
