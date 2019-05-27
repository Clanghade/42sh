/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** quote
*/

#include "../headers/fourty_two_sh.h"

char *clear_quote(char *str)
{
    char **tab = my_str_to_tab(str, ' ');

    for (int i = 0; tab[i] != NULL; i++) {
        if (tab[i][0] == '\'' || tab[i][0] == '\"')
            tab[i]++;
        if (tab[i][my_strlen(tab[i]) - 1] == '\'' ||
        tab[i][my_strlen(tab[i]) - 1] == '\"')
            tab[i][my_strlen(tab[i]) - 1] = '\0';
    }
    return (reconcat_tab(tab));
}

int quote_pb(char *str, env_modif_t env_modif, linked_t *tree, int type)
{
    if (type == 1)
        my_put_err("Unmatched '\''.\n");
    if (type == 2)
        my_put_err("Unmatched '\"'.\n");
    return (my_sh(env_modif, str, tree));
}

int quote(char *str, env_modif_t env_modif, linked_t *tree)
{
    int nb = 0;
    int nb2 = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\'')
            nb++;
        if (str[i] == '\"')
            nb2++;
    }
    if (nb % 2 == 1)
        return (quote_pb(str, env_modif, tree, 1));
    if (nb2 % 2 == 1)
        return (quote_pb(str, env_modif, tree, 2));
    return (0);
}