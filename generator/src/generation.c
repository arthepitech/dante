/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-arthaud.poupard
** File description:
** generation
*/

#include <stdlib.h>
#include "generator.h"

static int check_x_y(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (ISINT(str[i]))
            return 0;
    }
    return 1;
}

gen_t *free_maze(gen_t *maze)
{
    if (maze->array != NULL) {
        for (int i = 0; maze->array[i] != NULL; i++)
            free(maze->array[i]);
        free(maze->array);
    }
    free(maze);
    return NULL;
}

static int maze_generator(gen_t *maze, int x, int y, int isperfect)
{
    if (x < 1 || y < 1)
        return KO;
    y += 1;
    maze = generater(maze, x, y);
    if (maze == NULL)
        return NULL;
    maze->size.y -= 1;
    if (maze->array[maze->size.y - 1][maze->size.x - 1] != '*') {
        free_maze(maze);
        return maze_generator(maze, x, y, isperfect);
    }
    if (!isperfect)
        unperfected(maze);
    print_maze(maze);
    free_maze(maze);
    return OK;
}

int generation(int ac, char **av)
{
    gen_t *maze = NULL;

    if (!check_x_y(av[1]) || !check_x_y(av[2]))
        return KO;
    if (ac == 4) {
        if (check_is_perfect(ac, av))
            return (maze_generator(maze, atoi(av[1]), atoi(av[2]), 1));
        else
            return KO;
    }
    return (maze_generator(maze, atoi(av[1]), atoi(av[2]), 0));
}
