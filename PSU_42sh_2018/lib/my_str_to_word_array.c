/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** change a str to a tab
*/

#include "../headers/minishell2.h"

int nb(char *str, char sep)
{
    int spaces = 1;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == sep)
            spaces++;
    }
    return (spaces);
}

int actual(char *str, char sep)
{
    int i = 1;

    for (; str[0] != 0 && str && str[i] != sep && str[i] != 0; i++);
    return (i);
}

char **last_ver(char **tab, char sep, int nb_el)
{
    if (tab[nb_el - 1][0] == sep || tab[nb_el - 1][0] == 0)
        tab[nb_el - 1] = NULL;
    return (tab);
}

void fixes(char *str, char sep)
{
    int i = 0;

    if (str[i] != 0)
        for (; str[i + 1] == sep || str[i + 1] == '\t'; i++);
}

char **my_str_to_tab(char *str, char sep)
{
    char **tab = malloc(sizeof(char *) * (nb(str, sep) + nb(str, '\t')));
    int j = 0;

    for (int i = 0; i < my_strlen(str) + 1; i++, j++) {
        for (; str[i] == sep || str[i] == '\t'; i++);
        tab[j] = malloc(sizeof(char) * (actual(&str[i], sep) + 2));
        tab[j][0] = 0;
        for (int e = 0; str[i] != sep && str[i] != '\0' && \
        str[i] != '\t'; i++, e++) {
            if (str[i] == '\\')
                i += 1;
            tab[j][e] = str[i];
            if (str[i + 1] == sep || str[i + 1] == '\t' || str[i + 1] == 0)
                tab[j][e + 1] = 0;
        }
        fixes(str, sep);
    }
    tab = last_ver(tab, sep, j);
    tab[j] = NULL;
    return (tab);
}