/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-arthaud.poupard
** File description:
** check_sides
*/

#include "generator.h"

static int check_left(gen_t *maze, var_t *place)
{
    int x = place->x;
    int y = place->y;
    var_t size = maze->size;

    if (x <= 0 || maze->array[y][x - 1] > 0)
        return 0;
    if (x - 1 > 0) {
        if (maze->array[y][x - 2] > 0)
            return 0;
    }
    if (y - 1 >= 0) {
        if (maze->array[y - 1][x - 1] > 0)
            return 0;
    }
    if (y + 1 <= size.y - 1) {
        if (maze->array[y + 1][x - 1] > 0)
            return 0;
    }
    return 1;
}

static int check_rigth(gen_t *maze, var_t *place)
{
    int x = place->x;
    int y = place->y;
    var_t size = maze->size;

    if (x >= size.x - 1 || maze->array[y][x + 1] > 0)
        return 0;
    if (x + 1 < size.x - 1) {
        if (maze->array[y][x + 2] > 0)
            return 0;
    }
    if (y - 1 >= 0) {
        if (maze->array[y - 1][x + 1] > 0)
            return 0;
    }
    if (y + 1 <= size.x - 1) {
        if (maze->array[y + 1][x + 1] > 0)
            return 0;
    }
    return 1;
}

static int check_north(gen_t *maze, var_t *place)
{
    int x = place->x;
    int y = place->y;
    var_t size = maze->size;

    if (y <= 0 || maze->array[y - 1][x] > 0)
        return 0;
    if (y - 1 > 0) {
        if (maze->array[y - 2][x] > 0)
            return 0;
    }
    if (x - 1 >= 0) {
        if (maze->array[y - 1][x - 1] > 0)
            return 0;
    }
    if (x + 1 <= size.x - 1) {
        if (maze->array[y - 1][x + 1] > 0)
            return 0;
    }
    return 1;
}

static int check_south(gen_t *maze, var_t *place)
{
    int x = place->x;
    int y = place->y;
    var_t size = maze->size;

    if (y >= size.y - 2 || maze->array[y + 1][x] > 0)
        return 0;
    if (y + 1 < size.y - 2) {
        if (maze->array[y + 2][x] > 0)
            return 0;
    }
    if (x - 1 >= 0) {
        if (maze->array[y + 1][x - 1] > 0)
            return 0;
    }
    if (x + 1 <= size.x - 1) {
        if (maze->array[y + 1][x + 1] > 0)
            return 0;
    }
    return 1;
}

void check_sides(int *dir, gen_t *maze, var_t *place)
{
    if (check_left(maze, place))
        dir[0] = 1;
    if (check_rigth(maze, place))
        dir[1] = 1;
    if (check_north(maze, place))
        dir[2] = 1;
    if (check_south(maze, place))
        dir[3] = 1;
}
