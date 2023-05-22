/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>

static void strcpy_wa(char *wa, char const *buff, int save, char brk)
{
    int i = 0;

    for (; buff[save] != brk && buff[save] != '\0' ; i++) {
        wa[i] = buff[save];
        save++;
    }
    wa[i] = '\0';
}

static int next_line(char const *buff, int save, char brk)
{
    for (; buff[save] != brk && buff[save] != '\0' ; save++);
    return ++save;
}

static int get_x_size(char const *buff, int save, char brk)
{
    int x = 0;

    for (; buff[save] != brk && buff[save] != '\0' ; save++)
        x++;
    return x;
}

static int get_y_size(char const *buff, char brk)
{
    int i = 0;
    int y = 0;

    for (; buff[i] ; i++)
        if (buff[i] == brk)
            y++;
    if (buff[i - 1] == brk)
        y--;
    return ++y;
}

char **my_str_to_word_array(char const *buff, char brk)
{
    char **wa = NULL;
    int y = get_y_size(buff, brk);
    int x;
    int save = 0;

    wa = malloc(sizeof(char *) * (y + 1));
    for (int i = 0 ; i < y ; i++) {
        x = get_x_size(buff, save, brk);
        wa[i] = malloc(sizeof(char) * (x + 1));
        strcpy_wa(wa[i], buff, save, brk);
        save = next_line(buff, save, brk);
    }
    wa[y] = NULL;
    return wa;
}
