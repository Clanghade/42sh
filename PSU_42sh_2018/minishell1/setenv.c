/*
** EPITECH PROJECT, 2018
** setenv
** File description:
** function for setenv
*/

#include "../headers/minishell1.h"

int check_error(char **tab)
{
    if (tab[1][0] >= '0' && tab[1][0] <= '9') {
        my_put_err("setenv: Variable name must begin with a letter.\n");
        return (1);
    }
    if (my_str_is_alpha_num(tab[1])) {
        my_put_err("setenv: Variable name must contain ");
        my_put_err("alphanumeric characters.\n");
        return (1);
    }
    return (0);
}

char **last_setenv(char **env, int i, char **tab)
{
    env[i] = my_strcat(tab[1], "=");
    env[i + 1] = NULL;
    if (tab[2])
        env[i] = my_strcat(env[i], tab[2]);
    return (env);
}

char **my_setenv(char **tab, char **env)
{
    int i, verif = 0;

    if (!tab[1])
        return (display_env(env));
    if (check_error(tab))
        return (env);
    for (i = 0; env[i]; i++) {
        if (length_diff(env[i], tab[1])) {
            env[i] = my_strcat(tab[1], "=");
            tab[2] ? env[i] = my_strcat(env[i], tab[2]) : 0;
            verif++;
        }
    }
    if (verif)
        return (env);
    env = last_setenv(env, i, tab);
    return (env);
}

char **my_unsetenv(char **tab, char **env)
{
    int i, j;

    if (!tab[1]) {
        my_put_err("unsetenv: Too few arguments.\n");
        return (env);
    }
    for (j = 0, i = 0; env[i]; i++, j++) {
        env[j] = env[i];
        if (length_diff(env[i], tab[1]))
            j--;
    }
    env[j] = NULL;
    return (env);
}

int env_cd(char **env, char *prev, char *cwd)
{
    for (int i = 0; env && env[i]; i++) {
        if (length_diff(env[i], "OLDPWD")) {
            env[i] = my_strcat("OLDPWD=", prev);
            free(prev);
            free(cwd);
            return (1);
        }
    }
    return (0);
}