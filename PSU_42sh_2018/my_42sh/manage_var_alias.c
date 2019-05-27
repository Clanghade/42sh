/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** manage_var_alias
*/

#include "../headers/fourty_two_sh.h"

int error_alias(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (tab[i][0] == '$') {
            tab[i]++;
            printf("%s: Undefined variable.\n", tab[i]);
            return (1);
        }
    }
    return (0);
}

int error_dollar(char *str)
{
    str++;
    printf("%s: Undefined variable.\n", first(str));
    return (1);
}

int error_in(char *str)
{
    for (int i = 0; str[i] != '\0' && str[i] != '='; i++) {
        if (str[i] < 48 || (str[i] > 57 && str[i] < 65) || (str[i]
        > 90 && str[i] < 97) || str[i] > 122) {
            printf("set: Variable name must contain alphanumeric"
            "characters.\n");
            return (1);
        }
    }
    return (0);
}

int second_dollar(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '=')
            nb++;
    if (nb == 0)
        return (0);
    else {
        for (; str[0] != '='; str++);
        str++;
        if (str[0] == '$') {
            printf("%s: Undefined variable.\n", str);
            return (1);
        } else
            return (0);
    }
    return (0);
}

int error_var(char **tab)
{
    int check = 0;

    for (int i = 1; tab[i] != NULL; i++) {
        if (tab[i][0] == '$')
            return (error_dollar(tab[i]));
        if (tab[i][0] < 48 || (tab[i][0] > 57 && tab[i][0] < 65) || (tab[i][0]
        > 90 && tab[i][0] < 97) || tab[i][0] > 122) {
            printf("set: Variable name must begin with a letter.\n");
            return (1);
        }
        if ((check = error_in(tab[i])) == 1)
            return (1);
        if ((check = second_dollar(tab[i])) == 1)
            return (1);
    }
    return (0);
}