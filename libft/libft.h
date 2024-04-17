#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>

int     ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char    **ft_split(char const *s, char c);
int     ft_atoi(const char *str);

#endif