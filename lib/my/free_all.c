/*
** EPITECH PROJECT, 2022
** lib
** File description:
** free all
*/

#include <stdlib.h>

int free_all(char **map)
{
    if (map == NULL)
        return 0;
    for (int i = 0 ; map[i] != NULL ; i++)
        free(map[i]);
    free(map);
    return 0;
}
