#include "libft.h"

int ft_strlen(const char *str)
{
    int len;
    int i;

    len = 0;
    i = 0;
    while (str[i] != '\0')
    {
        len++;
        i++;
    }
    return (len);
}