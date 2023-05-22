/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-arthaud.poupard
** File description:
** perfect
*/

#include <time.h>
#include <stdlib.h>
#include "generator.h"

void unperfected(gen_t *maze)
{
    var_t pos = { 0, 0 };
    int size = (maze->size.x * maze->size.y) / 9 + 1;
    long int random = (long int)(maze) + (long int)(&size);

    srand(time(NULL) + random);
    for (int i = 0; i < size; i++) {
        pos.x = rand() % maze->size.x;
        pos.y = rand() % maze->size.y;
        maze->array[pos.y][pos.x] = '*';
    }
}

int check_is_perfect(int ac, char **av)
{
    char perfect[] = "perfect";
    int size = my_strlen(perfect);

    if (ac != 4)
        return 0;
    for (int i = 0; i < size + 1; i++) {
        if (av[3][i] == '\0' && av[3][i] != perfect[i])
            return 0;
        if (av[3][i] != perfect[i])
            return 0;
    }
    return 1;
}
