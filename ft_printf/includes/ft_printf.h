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

int		g_minus;
int		g_plus;
char	*g_result;
char	*g_flags;

void	ft_char_place(char c);
void	ft_string_place(char *str);
char	*ft_strjoin_my(char const *s1, char const *s2);
void	ft_int_place(int n);
void	ft_death(char *str);
char	*ft_itol(long int n);
int		ft_width_precision(char *num, int flag);

#endif
