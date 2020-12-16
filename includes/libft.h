/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:49:09 by thallard          #+#    #+#             */
/*   Updated: 2020/12/14 14:26:42 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_flags
{
	int		zero;
	int		minus;
	int		width;
	int		star;
	int		point;
	int		type;
}				t_flags;

unsigned int	ft_strlen(const char *str);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strchr(const char *string, int c);
char			*ft_strrchr(const char *string, int c);
char			*ft_strnstr(char *str, char *to_find, int len);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strtrim(char const *str, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strdup(char *src);

int				ft_isalpha(int character);
int				ft_isdigit(int character);
int				ft_isalnum(int character);
int				ft_isascii(int character);
int				ft_isprint(int character);
int				ft_tolower(int character);
int				ft_toupper(int character);

void			ft_putchar_fd(const char c, int fd);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			*ft_calloc(int len, int character);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int nbr);
char			**ft_split(char *str, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_bzearo(void *pointer, int size);
void			*ft_memset(void *pointer, int value, int size);
void			*ft_memcpy(void *dest, void *src, size_t len);
void			*ft_memccpy(void *dest, void *src, int character, size_t len);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *dest, int character, size_t len);
int				ft_memcmp(const void *dest, const void *source, size_t len);
int				ft_atoi(const char *nptr);

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *ne);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *ne);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *));


int				get_next_line(int fd, char **line);
char			*ft_strjoin_gnl(char *s1, char *s2, int f);
char			*ft_get_after_eol(char *save);
char			*ft_create_line(char *s);


int				ft_start_print(const char *str, va_list a, t_flags *f, int *c);
int				ft_detect_flags(const char *str, va_list a, t_flags *f, int c);
int				ft_printf(const char *format, ...);

int				ft_prepare_print(const char *str, t_flags *f, va_list a);
int				ft_set_point_width(const char *s, t_flags *f, int i, va_list a);
int				ft_set_star_width(const char *s, t_flags *f, int i, va_list a);

int				ft_print_integer_i_d(t_flags *f, va_list a);
int				ft_print_integer_first_cases(t_flags *f, long nb, int s, int i);
int				ft_filler_integer_i_d(t_flags *f, long nb, int s, int z);
int				ft_print_integer_nopoint(t_flags *f);
int				ft_print_integer_zero_no_point(long nb, int spaces);

int				ft_print_integer_u(t_flags *f, va_list a);

int				ft_print_integer_hexadecimal(t_flags *f, va_list a, int maj);
int				ft_print_hexa_first_cases(t_flags *f, char *nb);
char			*ft_calcul_hexa(unsigned int nb, int maj);

int				ft_print_char(t_flags *f, va_list a);
int				ft_print_string(t_flags *f, va_list a);
int				ft_print_percentage(t_flags *f);
int				ft_place_spaces(t_flags *f, char *res, int whitespace);
char			*ft_apply_precision(t_flags *f, char *res, int len);

int				ft_print_hexa_pointer(t_flags *f, va_list a);
char			*hexa_pointer(unsigned long long nb);

int				ft_is_flag(int c);
int				ft_is_spec(int c);
int				ft_is_digit(int character);
int				ft_is_type(char c);

int				ft_putchar_len(char c);
int				ft_putstr_len(char *str);
int				ft_putstr_len_rev(char *str);
long			ft_printnbr_len(long n);

int				ft_init_struct_flags(t_flags *f);
int				ft_have_flags(t_flags *f);

int				ft_get_len(long n);
void			ft_tolower_entire(char *str);
#endif
