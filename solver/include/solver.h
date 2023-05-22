/*
** EPITECH PROJECT, 2022
** solver
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #define OK  0
    #define KO  84

typedef struct solver_s {
    int n;
} solver_t;

int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char **my_str_to_word_array(char const *buff, char brk);
int free_all(char **map);
int file_size(char *path);

int solver(char **map);
int check_if_empty(char const *line);
void move(char **map, int n, int y);
int stop_condition(char **map, int n, int y, int x);

#endif /* MY_H_ */
