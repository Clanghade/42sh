/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** replace_word.c
*/

#include "../headers/minishell1.h"

char *reconcat_tab(char **tab)
{
    char *str = NULL;
    int i = 0;
    int lgt = 0;

    for (i = 0; tab[i] != NULL; i++)
        lgt += my_strlen(tab[i]);
    str = restock(lgt + i + 1);
    for (i = 0, lgt = 0; tab[i] != NULL; i++, lgt++) {
        for (int j = 0; tab[i][j] != '\0'; j++, lgt++)
            str[lgt] = tab[i][j];
        str[lgt] = ' ';
    }
    str[lgt] = '\0';
    return (str);
}

char *my_dbconcact(char *str, char *res, int check, int arg)
{
    char *tmp = restock(my_strlen(str) + my_strlen(res) + 1);
    int i = 0;
    int j = 0;

    for (i = 0, j = 0; i < check; i++, j++)
        tmp[i] = str[j];
    for (int h = 0; res[h] != '\0'; h++, i++)
        tmp[i] = res[h];
    for (j += arg; str[j] != '\0'; j++, i++)
        tmp[i] = str[j];
    tmp[i] = '\0';
    return (tmp);
}

char *my_filler(char *str, char *arg, char *res)
{
    int check = -1;

    while ((check = my_fullcmp(str, arg)) != -1) {
        str = my_dbconcact(str, res, check, my_strlen(arg));
    }
    return (str);
}

void inside_fnc(char **tab, env_modif_t env, int i)
{
    for (int j = 0; env.var->var[j] != NULL; j++) {
        if (my_fullcompare(tab[i], my_strcat("$", env.var->var[j]))) {
            tab[i] = my_filler(tab[i], my_strcat("$", env.var->var[j]),
            env.var->var_r[j]);
            break;
        }
    }
    for (int j = 0; env.a->alias[j] != NULL; j++) {
        if (str_compare(tab[i], env.a->alias[j])) {
            tab[i] = my_strcpy(tab[i], env.a->alias_r[j]);
            break;
        }
    }
}

char *al_var_check(char *str, env_modif_t env)
{
    char **tab = NULL;

    str = clear_quote(str);
    tab = my_str_to_tab(str, ' ');
    if (str_compare("set", tab[0]) || str_compare("alias", tab[0]))
        return (str);
    for (int i = 0; tab[i] != NULL; i++) {
        inside_fnc(tab, env, i);
    }
    return (reconcat_tab(tab));
}
