/*
** EPITECH PROJECT, 2018
** echo
** File description:
** function for echo
*/

#include "../headers/minishell2.h"

char *dlt_quot(char *str, int nb_quotes)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '"') {
            for (int j = i + 1, k = i; str[j] != 0; j++, k++)
                str[k] = str[j];
        }
    }
    str[my_strlen(str) - nb_quotes] = 0;
    return (str);
}

char *set_echo(char **tab)
{
    char *to_print = malloc(sizeof(char) * my_strlen(tab[1]));

    to_print[0] = 0;
    for (int i = 1; tab[i]; i++) {
        to_print = my_strcat(to_print, tab[i]);
        tab[i + 1] ? to_print = my_strcat(to_print, " ") : 0;
    }
    return (to_print);
}

int function_echo(char **tab)
{
    char *to_print = NULL;
    int quote = 0;

    if (tab[1]) {
        to_print = set_echo(tab);
        for (int i = 0; i < my_strlen(to_print); i++)
            to_print[i] == '"' ? quote++ : 0;
        if (quote % 2) {
            my_put_err("Unmatched '\"'.");
            return (1);
        } else {
            to_print = dlt_quot(to_print, quote);
            my_putstr(to_print);
        }
    }
    free(to_print);
    my_putchar('\n');
    return (0);
}