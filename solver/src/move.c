/*
** EPITECH PROJECT, 2022
** solver
** File description:
** move
*/

#include <stddef.h>

static void all_directions(char **map, int y, int x)
{
    if (y != 0 && map[y - 1][x] == '*')
        map[y - 1][x] = 'p';
    if (map[y + 1] != NULL && map[y + 1][x] == '*')
        map[y + 1][x] = 'p';
    if (map[y][x + 1] == '*')
        map[y][x + 1] = 'p';
    if (x != 0 && map[y][x - 1] == '*')
        map[y][x - 1] = 'p';
}

void move(char **map, int n, int y)
{
    for (int x = 0 ; map[y][x] != '\0' ; x++) {
        if (map[y][x] == 'P') {
            map[y][x] = n;
            all_directions(map, y, x);
        }
    }
}
