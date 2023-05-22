/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-arthaud.poupard
** File description:
** randomize_maze
*/

#include <time.h>
#include <stdlib.h>
#include "generator.h"

static int count_direc(int *dir)
{
    int count = 0;

    for (int i = 0; i < 4; i++) {
        if (dir[i] == 1)
            count++;
    }
    return count;
}

static void maze_point(gen_t *maze, var_t *place, int direction)
{
    var_t movements = { (direction % 2) * 2 - 1, (direction % 2) * 2 - 1 };

    if (direction / 2 == 1) {
        movements.x = 0;
    } else {
        movements.y = 0;
    }
    maze->array[place->y][place->x] = 1;
    place->x += movements.x;
    place->y += movements.y;
}

static int changes(gen_t *maze, var_t *place)
{
    int random = 0;
    int random_cpy = -1;
    int dir[4] = { 0, 0, 0, 0 };

    check_sides(dir, maze, place);
    if (count_direc(dir) <= 0)
        return 0;
    random = rand() % count_direc(dir);
    for (int i = 0; i <= random; i++) {
        random_cpy = random_cpy + 1;
        if (dir[i] == 0)
            random = random + 1;
    }
    maze_point(maze, place, random_cpy);
    return 1;
}

static int maze_loop(gen_t *maze, var_t *place)
{
    if (!changes(maze, place)) {
        if (!get_back_if_wall(maze, place))
            return 0;
    }
    return 1;
}

void rando_maze(gen_t *maze)
{
    var_t place = { 0, 0 };
    long int random = (long int)(maze) + (long int)(&place);

    srand(time(NULL) + random);
    while (maze_loop(maze, &place));
}
