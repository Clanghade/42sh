/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** variables
*/

#include "../headers/fourty_two_sh.h"

char *second(char *str)
{
    char *rep = restock(100);
    int j = 0;
    int i = 0;
    int err = 0;

    for (int k = 0; str[k] != '\0'; k++)
        if (str[k] == '=')
            err++;
    if (err == 0)
        return ("\0");
    for (; str[i] != '='; i++);
    i++;
    for (; str[i] != '\0'; i++) {
        rep[j] = str[i];
        j++;
    }
    return (rep);
}

char *first(char *str)
{
    char *rep = restock(100);
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '=')
            break;
        rep[j] = str[i];
        j++;
    }
    rep[j] = '\0';
    return (rep);
}

void stock_set(env_modif_t env, char **tab, int check)
{
    int j = 0;
    int nb = 0;

    for (int i = 1; i < check; i++) {
        for (j = 0, nb = 0; env.var->var[j] != NULL; j++) {
            if (str_compare(env.var->var[j], first(tab[i])) == 1) {
                nb = 1;
                break;
            }
        }
        if (nb == 1)
            env.var->var_r[j] = second(tab[i]);
        else {
            env.var->var[j] = first(tab[i]);
            env.var->var_r[j] = second(tab[i]);
        }
    }
}

void print_set(env_modif_t env)
{
    for (int i = 0; env.var->var[i] != NULL; i++)  {
        printf("%s\t", env.var->var[i]);
        printf("%s\n", env.var->var_r[i]);
    }
}

int function_variable(char **tab, env_modif_t env)
{
    int check = 0;
    int err = error_var(tab);

    if (err != 0)
        return (1);
    for (; tab[check] != NULL; check++);
    if (check == 1)
        print_set(env);
    else if (check >= 2)
        stock_set(env, tab, check);
    return (0);
}