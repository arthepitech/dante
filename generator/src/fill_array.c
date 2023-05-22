/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-dante-arthaud.poupard
** File description:
** fill_array
*/

#include <stdlib.h>
#include "generator.h"

static char *do_lines(int x)
{
    char *str = malloc(sizeof(char) * (x + 2));

    if (str == NULL)
        return NULL;
    for (int i = 0; i < x; i++)
        str[i] = (char)0;
    str[x] = '\n';
    str[x + 1] = '\0';
    return str;
}

static char **free_array(char **array)
{
    if (array == NULL)
        return NULL;
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
    return NULL;
}

char **fill_array(int x, int y)
{
    char **array = malloc(sizeof(char *) * (y + 1));

    for (int i = 0; i < y; i++) {
        array[i] = do_lines(x);
        if (array[i] == NULL)
            return free_array(array);
    }
    array[y] = NULL;
    return array;
}
