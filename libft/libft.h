/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 11:10:42 by jsarkis           #+#    #+#             */
/*   Updated: 2019/07/09 11:05:21 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 50
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);

void				ft_bzero(void *s, size_t n);

int					ft_find_index(char *str, char to_find);

char				*ft_find_str(char const *s, char c, int start);

int					ft_is_white_space(char c);

int					ft_isalnum(int c);

int					ft_isalpha(int c);

int					ft_isascii(int c);

int					ft_isdigit(int c);

int					ft_isprint(int c);

char				*ft_itoa(int n);

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstdel_c(void *content, size_t content_size);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

t_list				*ft_lstnew(void const *content, size_t constent_size);

t_list				*ft_lstnew_content_malloc(size_t size, size_t content_size);

void				*ft_memalloc(size_t size);

void				*ft_memccpy(void *dest, const void *src, int c, size_t n);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memcpy(void *dest, const void *src, size_t n);

void				ft_memdel(void **ap);

void				*ft_memmove(void *dest, const void *src, size_t n);

void				*ft_memset(void *b, int c, size_t len);

int					ft_num_words(char const *s, char c);

long				ft_order(long n);

void				ft_putchar(char c);

void				ft_putchar_fd(char c, int fd);

void				ft_putendl(char const *s);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putnbr(int n);

void				ft_putnbr_fd(int n, int fd);

void				ft_putstr(char const *str);

void				ft_putstr_fd(char const *str, int fd);

void				ft_str_char_set(char **str, char to_set, int index);

char				*ft_str_realloc(char **str, size_t size);

char				*ft_str_shift(char *str, int shift_size);

char				*ft_strcat(char *s1, const char *s2);

char				*ft_strchr(const char *s, int c);

void				ft_strclr(char *s);

int					ft_strcmp(const char *s1, const char *s2);

char				*ft_strcpy(char *dst, const char *src);

void				ft_strdel(char **as);

char				*ft_strdup(const char *s1);

int					ft_strequ(char const *s1, char const *s2);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strjoin(char const *s1, char const *s2);

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

size_t				ft_strlen(const char *str);

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char				*ft_strncat(char *s1, const char *s2, size_t n);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strncpy(char *dst, const char *src, size_t len);

int					ft_strncpyi(char **dst, const char *src, int len, \
						int dest_index);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strnew(size_t size);

char				*ft_strnstr(const char *haystack, const char *needle, \
						size_t len);

int					ft_strocc(const char *str, char c);

char				*ft_strrchr(const char *s, int c);

char				**ft_strsplit(char const *s, char c);

char				*ft_strstr(const char *haystack, const char *needle);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strtrim(char const *s);

int					ft_tolower(int c);

int					ft_toupper(int c);

int					get_next_line(const int fd, char **line);

int					get_next_line_lst(const int fd, char **line);

int					gnl_main_loop(const int fd, char **line, char **buff);

void				prep_buff(char **buff);

#endif
