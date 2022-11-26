/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:13:09 by cnascime          #+#    #+#             */
/*   Updated: 2022/10/25 15:43:59 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

# define FD 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if __APPLE__
#  define STR_ERROR "(null)"
#  define PTR_ERROR "0x0"
# elif __unix__
#  define STR_ERROR "(null)"
#  define PTR_ERROR "(nil)"
# else
#  define STR_ERROR "(null)"
#  define PTR_ERROR "(null)"
# endif

typedef struct s_flags
{
	int		dash;
	int		zero;
	int		hash;
	int		plus;
	int		space;
	int		i;
	va_list	argument;
}	t_flags;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

size_t	ft_strlen(const char *string);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_isalpha(int c);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isalphabetic(char *str);
int		ft_isdigit(int c);
int		ft_isnumeric(char *str);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isnegative(long num);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *lookingfor, int character);
char	*ft_strrchr(const char *lookingfor, int character);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_atoi(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_putchar_fd(int fd, char c);
int		ft_putstr_fd(int fd, char *s);
void	ft_putendl_fd(int fd, char *s);
void	ft_putnbr_fd(int fd, int n);
void	ft_putnbr_base_fd(int fd, int number, char *base);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *newnode);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *newnode);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
// ft_printf
char	*result(int places, int index, int *convert);
int		ft_places(long number);
char	*ft_utoa(unsigned int n);
char	*ft_otoa(unsigned long long n);
char	*ft_htoa(char lettercase, unsigned long long n);
size_t	ft_hexlen(unsigned int hex);
size_t	ft_pointerlen(uintptr_t pointer);
int		ft_printf(const char *fixed, ...);
int		ft_putint(int number);
int		ft_putuns(unsigned int number);
int		ft_putoct(unsigned long long number);
int		ft_puthex(char lettercase, unsigned long long number);
int		ft_putptr(unsigned long long number);
void	lowerflags(t_flags *flags);
void	raiseflags(const char *expression, t_flags *flags);
void	treatflags(const char *exp, int *places, t_flags *flags);
void	treatspecs(const char *exp, int *count, t_flags *flags);
int		ft_atoiforprintf(const char *str);
void	sign(const char *exp, int *count, t_flags *flags);
// get_next_line
char	*get_next_line(int fd);
char	*reader(int fd, char *temp);
char	*reaper(char *temp);
char	*rescuer(char *temp);
#endif
