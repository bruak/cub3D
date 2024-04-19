#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
    char	*dup;
    size_t	i;

    dup = (char *)malloc(sizeof(char) * (n + 1));
    if (!dup)
        return (NULL);
    i = 0;
    while (i < n && s1[i])
    {
        dup[i] = s1[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}