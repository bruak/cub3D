#include "../cub3D.h"

//tüm init değerleri çoğaldıktan sonra fonksiyonlara bölerek daha okunaklı bi kod yapısı oluşturacağım
void data_init(t_data *data)
{
    data->mlx = NULL;
    data->win = NULL;
    data->map = NULL;
    data->map_path = NULL;

    data->cub_info.north = NULL;
    data->cub_info.south = NULL;
    data->cub_info.west = NULL;
    data->cub_info.east = NULL;
    data->cub_info.floor = 0;
    data->cub_info.ceiling = 0;
    
    data->copymap.total_line_count = 0;
    data->copymap.fd = 0;
    data->copymap.copied_file = NULL;
}