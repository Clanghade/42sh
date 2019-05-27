/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** init
*/

#include "headers/minishell2.h"

alias_t *init_alias(void)
{
    alias_t *a = malloc(sizeof(alias_t));

    a->alias = malloc(sizeof(char *) * 100);
    a->alias_r = malloc(sizeof(char *) * 100);
    for (int i = 0; i < 100; i++) {
        a->alias[i] = NULL;
        a->alias_r[i] = NULL;
    }
    return (a);
}

var_t *init_var(void)
{
    var_t *v = malloc(sizeof(var_t));

    v->var = malloc(sizeof(char *) * 100);
    v->var_r = malloc(sizeof(char *) * 100);
    for (int i = 0; i < 100; i++) {
        v->var[i] = NULL;
        v->var_r[i] = NULL;
    }
    return (v);
}