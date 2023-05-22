/*
** EPITECH PROJECT, 2022
** solver
** File description:
** main
*/

#include "solver.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int error(char *map)
{
    if (map[0] != '*')
        return KO;
    for (int i = 0 ; map[i] ; i++)
        if (map[i] != 'X' && map[i] != '*' && map[i] != '\n')
            return KO;
    return OK;
}

static char **get_map(char **av)
{
    int fd = open(av[1], O_RDONLY);
    int size = file_size(av[1]);
    char *buff = NULL;
    char **map = NULL;

    if (size == -1)
        return NULL;
    buff = malloc(sizeof(char) * (size + 1));
    if (buff == NULL)
        return NULL;
    read(fd, buff, size);
    if (error(buff) != OK) {
        free(buff);
        return NULL;
    }
    map = my_str_to_word_array(buff, '\n');
    free(buff);
    return map;
}

int main(int ac, char **av)
{
    char **map = NULL;

    if (ac != 2)
        return KO;
    map = get_map(av);
    if (map == NULL)
        return KO;
    solver(map);
    free_all(map);
    return OK;
}
