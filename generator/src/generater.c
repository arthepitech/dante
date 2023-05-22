/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-arthaud.poupard
** File description:
** generater
*/

#include <stdlib.h>
#include "generator.h"

static char fill_maze(char c)
{
    if (c > 0)
        return ('*');
    return ('X');
}

gen_t *generater(gen_t *maze, int x, int y)
{
    maze = malloc(sizeof(gen_t));
    maze->array = fill_array(x, y);
    if (maze->array == NULL)
        return free_maze(maze);
    maze->size.x = x;
    maze->size.y = y;
    if (maze == NULL)
        return NULL;
    rando_maze(maze);
    for (int y = 0; y < maze->size.y; y++) {
        for (int x = 0; x < maze->size.x; x++)
            maze->array[y][x] = fill_maze(maze->array[y][x]);
    }
    return maze;
}
