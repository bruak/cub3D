#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "cub3D.h"


int	main(int ac, char **av)
{
    t_data data;

    data_init(&data);
    checker(ac, av, &data);
    parsing_cub_file(&data);

}