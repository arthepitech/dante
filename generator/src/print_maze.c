/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-arthaud.poupard
** File description:
** print_maze
*/

#include <stdlib.h>
#include "generator.h"

static char **print_array(char **array)
{
    if (array == NULL)
        return NULL;
    for (int i = 0; array[i] != NULL; i++) {
        if (array[i + 1] == NULL)
            return NULL;
        for (int j = 0; array[i][j] != '\0' && array[i][j] != '\n'; j++)
            my_putchar(array[i][j]);
        if (array[i + 1] != NULL && array[i + 2] != NULL)
            my_putchar('\n');
    }
    return array;
}

gen_t *print_maze(gen_t *maze)
{
    if (maze == NULL)
        return NULL;
    if (print_array(maze->array) == NULL)
        return NULL;
    return maze;
}
