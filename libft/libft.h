/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:45:35 by kbakhari          #+#    #+#             */
/*   Updated: 2018/11/03 16:41:43 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define MYLLOC(value) (char *)malloc(sizeof(char) * value);
# define M_PAR(x) params->x
# define M_PR_LN M_PAR(precision) > M_PAR(len)

int						g_minus;
int						g_plus;
char					*g_result;
char					*g_flags;
char					g_format;
int						g_kostil;

typedef	struct			s_par
{
	int					minus;
	int					plus;
	int					zeroes;
	int					below_zero;
	int					space;
	int					width;
	int					precision;
	int					hash;
	int					len;
	int					zero;
}						t_par;

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

void					ft_print_byte(unsigned char c);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
void					*ft_memset(void	*str, int c, size_t n);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c,
	size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
size_t					ft_strlen(const char *s);
char					*ft_strdup(char *src);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t n);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t dstsize);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
int						ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, char(*f)(unsigned int,
	char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start, size_t
	len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_itoa(int n);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)(void *,
	size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int						ft_arraycmp(char **a1, char **a2);
char					*ft_find_replace(char *s, char old, char new);
int						ft_sqrt(int nb);
void					ft_swap(unsigned char *c, unsigned char *b);

/*
**	utility
*/
void					ft_set_hash(t_par **params);
t_par					*ft_ini_struct(void);
char					*ft_itol(long int n);
char					*ft_utoa(unsigned long int n);
char					*ft_shift(char *str, char flag);
char					*ft_cut_one(char *s1);
char					*ft_itoa_base(long int value, int base, char format);
t_par					*ft_fill_struct(t_par *params);
char					*ft_get_float(long double n, int afterpoint);
long long int			ft_pow(int num1, int num2);
char					*ft_strjoin_my(char const *s1, char const *s2);
void					ft_starter_int(t_par *params, char *num);
void					ft_starter_f(t_par *params, char *num);
void					ft_starter_p(t_par *params, char *num);

/*
**	main
*/
int						ft_printf(char *format, ...);
void					ft_check_type(va_list list, char format);

/*
**	char
*/
void					ft_char_place(char n);

/*
**	int
*/
void					ft_int_place(int n);
void					ft_lint_place(long int n);
void					ft_hint_place(int n);
void					ft_width_precision_int(char *num, t_par *params);
void					ft_place_int(char *num, t_par *params);
void					ft_place_plmi_int(char *num, t_par *params);
void					ft_place_mi_int(char *num, t_par *params);
void					ft_place_pl_int(char *num, t_par *params);
void					ft_hhint_place(int n);

/*
**	unsigned
*/
int						ft_width_precision_u(char *num, t_par *params);
void					ft_u_place(unsigned int (n));
void					ft_place_u(char *num, t_par *params);
void					ft_place_mi_u(char *num, t_par *params);
void					ft_ul_place(unsigned long int n);
void					ft_hu_place(unsigned short int n);
void					ft_hhu_place(unsigned int n);

/*
**	octal
*/
void					ft_o_place(unsigned int n);
unsigned long int		ft_o_convert(unsigned long int num);
void					ft_ol_place(unsigned long int n);
void					ft_ho_place(unsigned short int n);
void					ft_hho_place(unsigned int n);

/*
**	hex
*/
void					ft_x_place(unsigned int n, char format);
void					ft_place_mi_x(char *num, t_par *params, int i);
void					ft_place_x(char *num, t_par *params);
void					ft_xl_place(unsigned long int n, char format);
void					ft_hhx_place(unsigned int n, char format);
void					ft_hx_place(unsigned short int n, char format);
void					ft_width_precision_x(char *num, t_par *params);

/*
**	string
*/
void					ft_string_place(char *str);

/*
**	float
*/
void					ft_f_place(double n, char format);
void					ft_fl_place(long double n, char format);
void					ft_place_f(char *num, t_par *params, int i);
void					ft_place_mi_f(char *num, t_par *params);
void					ft_place_plmi_f(char *num, t_par *params);
void					ft_place_pl_f(char *num, t_par *params);

/*
**	pointer
*/
void					ft_p_place(int n);
void					ft_place_p(char *num, t_par *params);
void					ft_place_mi_p(char *num, t_par *params, int i);

/*
**	percent
*/
void					ft_per_place(char n);

#endif
