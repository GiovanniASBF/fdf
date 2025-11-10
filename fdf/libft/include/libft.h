/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:05:33 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/11/06 14:56:19 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_fd_buffer
{
	int					fd;
	char				*buffer;
	struct s_fd_buffer	*next;
}						t_fd_buffer;

typedef struct s_format
{
	char	conversion_type;
}			t_format;

int			ft_atoi(const char *nptr);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *v2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strrchr(const char *s, int c);
int			ft_strlcat(char *dst, const char *src, size_t size);
int			ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);

void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);

char		*ft_get_next_line(int fd);
void		ft_gnl_delete_node(t_fd_buffer **head, int fd);
t_fd_buffer	*ft_gnl_find_node(t_fd_buffer *head, int fd);
t_fd_buffer	*ft_gnl_node_builder(t_fd_buffer *node, t_fd_buffer	*head, int fd);
char		*ft_gnl_update_buffer(char *buffer, char *line);

void		ft_pntf_input_handler(va_list args, const char *format, int *count);
void		ft_pntf_printhex(unsigned long ptr, char *base, int *count);
int			ft_printf(const char *format, ...);
void		ft_pntf_print_char(char c, int *count);
void		ft_pntf_print_str(char *str, int *count);
void		ft_pntf_printptr(void *ptr, int *count);
void		ft_pntf_printnbr(int n, int *count);
void		ft_pntf_printunbr(unsigned int n, int *count);
int			ft_pntf_specifier_handler(const char *str,
				va_list args, int *count);

#endif 