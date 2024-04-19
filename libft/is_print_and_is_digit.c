#include "libft.h"
#include "../cub3D.h"

int is_print_and_is_digit(t_data *data, int i, int x)
{
    return ft_isprint(data->copymap.copied_file[i][x])
        && !ft_isdigit(data->copymap.copied_file[i][x]);
}
