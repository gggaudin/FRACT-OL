/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:46:06 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/06/05 16:17:10 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line.h"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

ssize_t			ft_abs(ssize_t nb);
size_t			ft_strlenchr(const char *s, char c);
char			*ft_strjoin_free(char *s1, char *s2, char c, int atfree);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstnew(void const *content, size_t content_size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strsub(const char *s, size_t start, size_t n);
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_itoa(int n);
char			**ft_strsplit(const char *s, char c);
char			*ft_strtrim(const char *s);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strmap(const char *s, char (*f)(char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strrchr(const char *s, int c);
char			*ft_strchr(const char *s, int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_atoi(const char *str);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_putchar(char c);
void			ft_putstr(const char *s);
void			ft_putendl(const char *s);
void			ft_putnbr(int n);
int				ft_strequ(const char *s1, const char *s2);
int				ft_isalpha(int c);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char	*dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);

#endif
