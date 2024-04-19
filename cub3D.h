#ifndef cub3D_H
#define cub3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
* error makros
*/
#define BOLD_RED "\033[1m\033[31m"
#define RESET "\033[0m"
#define ERROR "Error\n"
/*
* map extension and ac error makros
*/
#define MAP_EXTENSION_SHORT "Map file extension is too short\n"
#define MAP_EXTENSION_IS_NOT_CUB "Map file extension is not .cub\n"
#define USAGE "usage: ./cub3D map.cub\n"
#define TOO_MANY_ARGS "Too many arguments\n"
/*
* fd control makros
*/
#define OPEN_ERROR "Map file does not exist\n"
#define READ_ERROR "Error while reading the map file, could be empty!\n"


/*
* allaocation error makros
*/
#define MALLOC_ERROR "Memory allocation error\n"



typedef struct s_cub_info
{
    char    *north;
    char    *south;
    char    *west;
    char    *east;
    int     *floor;
    int     *ceiling;

} t_cub_info ;

typedef struct s_copymap
{
    int    fd;
    char    **copied_file;
    int     total_line_count;
} t_copymap;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    char    **map;
    char    *map_path;
    int     **texture_color_array;
    t_cub_info  cub_info;
    t_copymap   copymap;
} t_data ;



/*
* data initialization
*/
void data_init(t_data *data);


/*
* check the validity of the map file
*/
void	checker(int ac, char **av, t_data *data);
void    error_exit(const char *msg);
void check_map_file_validity(char *str);

/*
* parsing the cub file
*/
void parsing_cub_file(t_data *data);

void get_color_info(char **temp_split, t_data *data);

int is_print_and_is_digit(t_data *data, int i, int x);

#endif