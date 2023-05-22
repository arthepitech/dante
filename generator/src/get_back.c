/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-arthaud.poupard
** File description:
** get_back
*/

#include "generator.h"

static int do_the_backward(gen_t *maze, var_t *place, int x, int y)
{
    var_t size = maze->size;

    x += place->x;
    y += place->y;
    if (x < 0 || size.x <= x || y < 0 || size.y <= y)
        return 0;
    if (maze->array[y][x] != 1)
        return 0;
    place->x = x;
    place->y = y;
    return 1;
}

int get_back_if_wall(gen_t *maze, var_t *place)
{
    var_t tab[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    maze->array[place->y][place->x] = 2;
    for (int i = 0; i < 4; i++) {
        if (do_the_backward(maze, place, tab[i].x, tab[i].y))
            return 1;
    }
    return 0;
}
