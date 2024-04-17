#include "libft.h"

char **allocate_split(char const *s)
{
    char **split;

    split = ft_calloc(ft_strlen(s) + 1, sizeof(char *));
    if (split == NULL)
        return (NULL);
    return (split);
}

void fill_split(char **split, char const *s, char c, int *i, int *j)
{
    int k = 0;

    while (s[*i + k] != c && s[*i + k] != '\0')
        k++;
    split[*j] = ft_calloc(k + 1, sizeof(char));
    if (split[*j] == NULL)
        return;
    k = 0;
    while (s[*i] != c && s[*i] != '\0')
    {
        split[*j][k] = s[*i];
        (*i)++;
        k++;
    }
    split[*j][k] = '\0';
    (*j)++;
}

char **ft_split(char const *s, char c)
{
    char **split;
    int i = 0;
    int j = 0;

    split = allocate_split(s);
    if (split == NULL)
        return (NULL);
    while (s[i] != '\0')
    {
        if (s[i] == c)
            i++;
        else
            fill_split(split, s, c, &i, &j);
    }
    return (split);
}