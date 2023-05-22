/*
** EPITECH PROJECT, 2022
** AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #define OK  0
    #define KO  84
    #define ISINT(X) (X < '0' || '9' < X)

typedef struct var_s {
    int x;
    int y;
} var_t;

typedef struct gen_s {
    char **array;
    var_t size;
} gen_t;

int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char **my_str_to_word_array(char const *buff, char brk);
void my_putchar(char c);
int free_all(char **map);
int file_size(char *path);
int generation(int ac, char **av);
int get_back_if_wall(gen_t *maze, var_t *place);
void rando_maze(gen_t *maze);
void check_sides(int *dir, gen_t *maze, var_t *place);
gen_t *print_maze(gen_t *maze);
int check_is_perfect(int ac, char **av);
gen_t *free_maze(gen_t *maze);
void unperfected(gen_t *maze);
gen_t *generater(gen_t *maze, int x, int y);
char **fill_array(int x, int y);

#endif /* MY_H_ */
