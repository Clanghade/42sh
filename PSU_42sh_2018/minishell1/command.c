/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** command
*/

#include "../headers/minishell2.h"

int verif_commands(char **tab, env_modif_t *env)
{
    if (same_str(tab[0], "cd")) {
        env->env = func_cd(tab, env->env);
        free_tab(tab);
        return (1);
    }
    if (same_str(tab[0], "env")) {
        display_env(env->env);
        free_tab(tab);
        return (1);
    }
    if (same_str(tab[0], "setenv")) {
        env->env = my_setenv(tab, env->env);
        free_tab(tab);
        return (1);
    }
    return (0);
}

int second_command(char **tab, env_modif_t *env, env_modif_t envi)
{
    if (same_str(tab[0], "echo")) {
        env->sortie = function_echo(tab);
        free_tab(tab);
        return (1);
    }
    if (same_str(tab[0], "alias")) {
        env->sortie = function_alias(tab, envi);
        return (1);
    }
    if (same_str(tab[0], "set")) {
        env->sortie = function_variable(tab, envi);
        return (1);
    }
    return (0);
}

char *delete_last_space(char *str)
{
    int len = my_strlen(str) - 1;

    for (;str[len] == ' '; len--)
        str[len] = 0;
    return (str);
}