/*
** EPITECH PROJECT, 2022
** generator
** File description:
** main
*/

#include <stdlib.h>
#include "generator.h"

int main(int ac, char **av)
{
    if (ac < 3)
        return KO;
    if (ac > 4)
        return KO;
    return (generation(ac, av));
}
