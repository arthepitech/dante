/*
** EPITECH PROJECT, 2022
** lib
** File description:
** file size
*/

#include <sys/stat.h>

int file_size(char *path)
{
    struct stat n;

    if (stat(path, &n) == 0)
        return n.st_size;
    return -1;
}
