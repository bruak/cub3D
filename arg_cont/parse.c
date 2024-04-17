#include "../cub3D.h"
#include "../42-get_next_line/get_next_line.h"
#include <fcntl.h>
#include "../libft/libft.h"

int total_line_of_cub_file(t_data *data)
{
    int     fd;

    fd = open(data->map_path, O_RDONLY);
    if (fd == -1)
        error_exit(OPEN_ERROR);
    while (get_next_line(fd) != NULL)
        data->copymap.total_line_count++;
    close(fd);
}

void    get_map_copy(t_data *data)
{
    int i;
    char *line;

    i = 0;
    data->copymap.fd = open(data->map_path, O_RDONLY);
    if (data->copymap.fd == -1)
        error_exit(OPEN_ERROR);
    data->copymap.copied_file = ft_calloc(data->copymap.total_line_count + 1, sizeof(char *));
    if (data->copymap.copied_file == NULL)
        error_exit(MALLOC_ERROR);
    while ((line = get_next_line(data->copymap.fd)) != NULL && i < data->copymap.total_line_count)
    {
        data->copymap.copied_file[i] = ft_strdup(line);
        i++;
    }
    while (i < data->copymap.total_line_count)
    {
        if (data->copymap.copied_file[i] != NULL)
        {
            free(data->copymap.copied_file[i]);
            data->copymap.copied_file[i] = NULL;
        }
        i++;
    }
    close(data->copymap.fd);
}

void    get_info_on_cub_file(t_data *data)
{
    int i;
    char **split;
    char *line;

    i = 0;
    while (i < data->copymap.total_line_count)
    {
        line = data->copymap.copied_file[i];
        split = ft_split(line, ' ');
        if (split[0] == NULL)
        {
            free(split);
            i++;
            continue;
        }
        if (ft_strncmp(split[0], "NO", 2) == 0)
            data->cub_info.north = ft_strdup(split[1]);
        else if (ft_strncmp(split[0], "SO", 2) == 0)
            data->cub_info.south = ft_strdup(split[1]);
        else if (ft_strncmp(split[0], "WE", 2) == 0)
            data->cub_info.west = ft_strdup(split[1]);
        else if (ft_strncmp(split[0], "EA", 2) == 0)
            data->cub_info.east = ft_strdup(split[1]);
        else if (ft_strncmp(split[0], "F", 1) == 0)
            data->cub_info.floor = ft_atoi(split[1]);
        else if (ft_strncmp(split[0], "C", 1) == 0)
            data->cub_info.ceiling = ft_atoi(split[1]);
        free(split);
        i++;
    }
    //printf all direction 

    printf("north: %s\n", data->cub_info.north);
    printf("south: %s\n", data->cub_info.south);
    printf("west: %s\n", data->cub_info.west);
    printf("east: %s\n", data->cub_info.east);
    printf("floor: %d\n", data->cub_info.floor);
    printf("ceiling: %d\n", data->cub_info.ceiling);

}

void    parsing_cub_file(t_data *data)
{
    total_line_of_cub_file(data);
    get_map_copy(data);
    get_info_on_cub_file(data);
}