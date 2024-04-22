/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:51:59 by mho               #+#    #+#             */
/*   Updated: 2023/12/18 14:27:25 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# if defined(__linux__)
#  define PTR_NULL "(nil)"
# elif defined(__APPLE__)
#  define PTR_NULL "0x0"
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);

int					ft_tolower(int c);
int					ft_toupper(int c);

void				ft_bzero(void *b, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strdup(const char *s1);
void				*ft_calloc(size_t count, size_t size);

size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *hs, const char *nd, size_t len);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

size_t				ft_strlcat(char *dest, const char *src, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

int					ft_atoi(const char *s);
char				*ft_itoa(int n);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **list, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

typedef struct s_flags
{
	int				left;
	int				zero;
	int				hash;
	int				space;
	int				plus;
	int				width;
	int				precision;
	int				caps;
	int				dot;
}					t_flags;

int					ft_printf(const char *s, ...);
int					ft_check_format(char s, t_flags *flags, va_list *args);
void				ft_check_flags(const char *s, t_flags *flags, int *i);

void				ft_init_flags(t_flags *flags);
int					is_format(char s);
int					is_flags(char s);
void				ft_check_width_precision(const char *s, t_flags *flags,
						int *i);

int					ft_putchar(char c);
int					ft_print_width(int width, char c);
int					ft_print_char(t_flags *flags, int c);
int					ft_putstr(char *s, t_flags *flags);
int					ft_print_str(t_flags *flags, char *str);

int					ft_intlen(int n, int base, t_flags *flags);
void				ft_putnbr_id(int n, int fd, t_flags *flags);
int					ft_putnbr(int n, t_flags *flags);
int					ft_print_i(t_flags *flags, int n);
void				ft_print_ii(t_flags *flags, int n, int int_len);

int					ft_print_xx(t_flags *flags, unsigned int n, int len,
						int hex_len);
int					ft_print_x(t_flags *flags, unsigned int n);
void				ft_putnbr_base(unsigned int n, char *base);
int					ft_puthex(unsigned int n, t_flags *flags);
int					ft_hexlen(unsigned int n, int base, t_flags *flags);

int					ft_print_uu(t_flags *flags, unsigned int n, int len,
						int intlen);
int					ft_print_u(t_flags *flags, unsigned int n);
int					ft_putui(unsigned int n, t_flags *flags);
void				ft_putui_fd(unsigned int nb, int fd, t_flags *flags);
int					ft_uintlen(unsigned int n, int base, t_flags *flags);

int					ft_print_p(t_flags *flags, unsigned long long n);
int					ft_putp(unsigned long long n);
void				ft_putp_base(unsigned long long n, char *base);
int					ft_ulonglen(unsigned long long n);
int					ft_putstr_custom(char *s);

/* Main Functions */
/*
 * @brief joins buffer to the result and free the temp buffer
 * @param res result string
 * @param buffer buffer string
 * @return A pointer to the joined string
 */
char				*joinf(char *res, char *buffer);
/*
 * @brief reads the file and appends to result string until '\n'
 * @param fd file descriptor
 * @param res result string
 * @return A pointer to the result string
 */
char				*read_file(int fd, char *res);
/*
 * @brief gets the line up to '\n' from buffer
 * @param buffer buffer string
 * @return A pointer to the line string
 */
char				*get_line(char *buffer);
/*
 * @brief trims the buffer to the remaining string after '\n'
 * @param buffer buffer string
 * @return A pointer to the remaining string
 */
char				*trim_buffer(char *buffer);
/*
 * @brief returns a line read from a file descriptor (til '\n')
 * @param fd file descriptor
 * @return A pointer to the line that has been read, or NULL if an error occurs
 *		or if there is nothing else to read.
 */
char				*get_next_line(int fd);

#endif
