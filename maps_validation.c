
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "./get_next_line/get_next_line.h"
#include "so_long.h"
int map_height(char *path)
{
    int i;
    int fd;

    i = 0;
    fd = open(path,O_RDONLY);
    while (get_next_line(fd) != NULL)
    {
        i++;
    }
    close(fd);
    return i;
}
char **get_map(char *path)
{
    char **map;
    int i;
    int height;

    height = map_height(path);
    map = (char **)malloc(height * sizeof(char *) + 1);
    int fd = open("./maps/map1.ber",O_RDONLY);
    i = 0;
    while(i < height)
    {
        map[i] = get_next_line(fd);
        i++;
    }
    map[i] = NULL;
    return map;
}

int main(int argc , char *argv[])
{
    if(argc == 1)
    {
        ft_putstr("PLEASE ENTER THE MAP PATH !!!");
        return 1;
    }
    // ft_putstr(&argv[1][ft_strlen(argv[1]) - 4]);
    if(ft_memcmp(&argv[1][ft_strlen(argv[1]) - 4],".ber"))
    {
        ft_putstr("PATH EXTENSION IS INCORRECT !!!");
        return 1;
    }    
    int i;

    i = 0;
    char **res = get_map(argv[1]);
    while(res[i])
    {
        printf("%s",  res[i]);
        i++;
    }
}
