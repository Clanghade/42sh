/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** alias
*/

#include "../headers/fourty_two_sh.h"

char *second_alias(char **tab, int nb)
{
    char *str = restock(100);
    int i = 2;

    if (nb == 3)
        return (tab[2]);
    for (;  i < nb - 1; i++) {
        str = my_strcat(str, tab[i]);
        str = my_strcat(str, " ");
    }
    str = my_strcat(str, tab[i]);
    return (str);
}

void stock_alias(env_modif_t env, char **tab, int nb)
{
    int i = 0;
    int check = 0;

    for (; env.a->alias[i] != NULL; i++) {
        if (str_compare(env.a->alias[i], tab[1]) == 1) {
            check = 1;
            break;
        }
    }
    if (check == 1)
        env.a->alias_r[i] = second_alias(tab, nb);
    else {
        env.a->alias[i] = tab[1];
        env.a->alias_r[i] = second_alias(tab, nb);
    }
}

void print_alias(env_modif_t env, char **tab)
{
    for (int i = 0; env.a->alias[i] != NULL; i++) {
        if (str_compare(tab[1], env.a->alias[i]))
            printf("%s\n", env.a->alias_r[i]);
    }
    return;
}

void print_all_alias(env_modif_t env)
{
    int check = 0;

    for (int i = 0; env.a->alias[i] != NULL; i++)  {
        printf("%s\t", env.a->alias[i]);
        for (int j = 0; env.a->alias_r[i][j] != '\0' && check != 1; j++)
            if (env.a->alias_r[i][j] == ' ')
                check = 1;
        if (check == 1)
            printf("(%s)\n", env.a->alias_r[i]);
        else
            printf("%s\n", env.a->alias_r[i]);
    }
}

int function_alias(char **tab, env_modif_t env)
{
    int check = 0;
    int err = error_alias(tab);

    if (err != 0)
        return (1);
    for (; tab[check] != NULL; check++);
    if (check == 1)
        print_all_alias(env);
    else if (check == 2)
        print_alias(env, tab);
    else
        stock_alias(env, tab, check);
    return (0);
}