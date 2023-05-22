/*
** EPITECH PROJECT, 2023
** dante
** File description:
** stop
*/

#include <stdio.h>

static void erase_evidences(char **map)
{
    for (int y = 0, x = 0 ; map[y] != NULL ; x++) {
        if (map[y][x] != '*' && map[y][x] != 'X' && map[y][x] != 'o')
            map[y][x] = '*';
        if (map[y][x + 1] == '\0') {
            y++;
            x = -1;
        }
    }
}

static void change_map(char **map, int y, int x, int n)
{
    map[y][x--] = 'o';
    while (x != 0 || y != 0) {
        if (y != 0 && (map[y - 1][x] == n - 2 ||
        map[y - 1][x] == 'm' && n == '!'))
            map[y--][x] = 'o';
        if (x != 0 && (map[y][x - 1] == n - 2 ||
        map[y][x - 1] == 'm' && n == '!'))
            map[y][x--] = 'o';
        if (map[y][x + 1] == n - 2 ||
        map[y][x + 1] == 'm' && n == '!')
            map[y][x++] = 'o';
        if (map[y + 1] != NULL && (map[y + 1][x] == n - 2 ||
        map[y + 1][x] == 'm' && n == '!'))
            map[y++][x] = 'o';
        n -= 2;
        if (n == 31)
            n = 'm';
    }
    erase_evidences(map);
}

void print_map(char **map)
{
    for (int i = 0 ; map[i] != NULL ; i++) {
        if (i != 0)
            printf("\n");
        printf("%s", map[i]);
    }
}

int stop_condition(char **map, int n, int y, int x)
{
    if (map[y][x] == 'p') {
        change_map(map, y, x, n);
        map[0][0] = 'o';
        print_map(map);
        return 0;
    }
    return 84;
}
