#include "../cub3D.h"
#include "../libft/libft.h"
#include <string.h>
#include <fcntl.h>
#include "../42-get_next_line/get_next_line.h"

void check_map_file_validity(char *str)
{
    int fd;
    char *line;

    fd = open(str, O_RDONLY);
    if (fd == -1)
        error_exit(OPEN_ERROR);
    if ((line = get_next_line(fd)) == NULL)
        error_exit(READ_ERROR);
    close(fd);
}


void error_exit(const char *msg)
{
    write(2, BOLD_RED, strlen(BOLD_RED));
    write(2, ERROR, 6);
    write(2, msg, strlen(msg));
    write(2, RESET, strlen(RESET));
    exit(0);
}

void check_map_extension(char *str)
{
    int len;
    int i;

    len = ft_strlen(str);
    i = 0;
    if (len < 4)
        error_exit(MAP_EXTENSION_SHORT);
    if (str[len - 1] != 'b' || str[len - 2] != 'u'
        || str[len - 3] != 'c' || str[len - 4] != '.')
        error_exit(MAP_EXTENSION_IS_NOT_CUB);
}

void check_ac(int ac)
{
    if (ac < 2)
        error_exit(USAGE);
    else if (ac > 3)
        error_exit(TOO_MANY_ARGS);
}

void	checker(int ac, char **av, t_data *data)
{
    check_ac(ac);
    check_map_extension(av[1]);
    check_map_file_validity(av[1]);
    data->map_path = av[1];
}
