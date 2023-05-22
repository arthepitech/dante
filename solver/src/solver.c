/*
** EPITECH PROJECT, 2022
** solver
** File description:
** solver
*/

#include "solver.h"
#include <stdio.h>
#include <stdlib.h>

int check_if_empty(char const *line)
{
    for (int i = 0 ; line[i] != '\0' ; i++)
        if (line[i] != '*' && line[i] != 'X')
            return KO;
    return OK;
}

static int change_p(char **map)
{
    int count = 0;
    int y = 0;

    for (int x = 0 ; map[y] != NULL ; x++) {
        if (check_if_empty(map[y]) == OK)
            break;
        if (map[y][x] == 'p') {
            map[y][x] = 'P';
            count++;
        }
        if (map[y][x + 1] == '\0') {
            x = -1;
            y++;
        }
    }
    if (count == 0) {
        printf("no solution found\n");
        return KO;
    }
    return OK;
}

int solver(char **map)
{
    int y = 0;
    int x = 0;

    while (map[y + 1] != NULL)
        y++;
    while (map[y][x + 1] != '\n' && map[y][x + 1] != '\0')
        x++;
    map[0][0] = 'P';
    for (int n = 33 ; 1 ; n += 2) {
        for (int y = 0 ; map[y] != NULL ; y++)
            move(map, n, y);
        if (stop_condition(map, n, y, x) == OK)
            break;
        if (change_p(map) != OK)
            break;
        if (n == 109)
            n = 31;
    }
    return OK;
}
