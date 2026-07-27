/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:13:31 by gyun              #+#    #+#             */
/*   Updated: 2026/07/28 01:12:25 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define FD_MAX 4096

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t dsize);
size_t	ft_strlcat(char *dest, const char *src, size_t dsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *));

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	sharp;
	int	space;
	int	plus;
	int	width;
	int	wild_wid;
	int	precision;
	int	wild_pre;
}	t_flags;

typedef struct s_pads
{
	int		pre_pad;
	int		zero_pad;
	int		post_pad;
	char	sign;
	int		sign_len;
}	t_pads;

typedef unsigned long long	t_ull;

int		ft_printf(const char *format, ...);
t_flags	ft_printf_init_flags(void);
void	ft_printf_flag_dup(t_flags *flags);
t_pads	ft_printf_init_pads(int n, t_flags *flags);
int		ft_printf_set_pads(t_ull n, t_pads *pads, t_flags *flags, char *base);
int		ft_printf_fill_wid(int i, char c);
int		ft_printf_putnbr(t_ull n, char *base);
int		ft_printf_nbrlen(t_ull n, char *base);
int		ft_printf_form_check(const char *format, t_flags *flags, va_list args);
int		ft_printf_help(const char *format, int i, t_flags *flags, va_list args);
int		ft_printf_char(va_list args, t_flags *flags);
int		ft_printf_str(va_list args, t_flags *flags);
int		ft_printf_ptr(va_list args, t_flags *flags);
int		ft_printf_dec(va_list args, t_flags *flags);
int		ft_printf_un_dec(va_list args, t_flags *flags);
int		ft_printf_lower_hex(va_list args, t_flags *flags);
int		ft_printf_upper_hex(va_list args, t_flags *flags);

char	*get_next_line(int fd);
size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strjoin(char *s1, char *s2);

#endif
