/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    for (int size = 0 ; 1 ; size++)
        if (str[size] == '\0')
            return size;
}
