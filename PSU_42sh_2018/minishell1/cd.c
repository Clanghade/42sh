/*
** EPITECH PROJECT, 2018
** cd.c
** File description:
** functions for cd
*/

#include "../headers/fourty_two_sh.h"

char **last_verif_previous_dir(char **env, char *prv)
{
    for (int i = 0; env[i]; i++) {
        if (length_diff(env[i], "PWD") && prv) {
            env[i] = my_strcat("PWD=", prv);
            free(prv);
            return (env);
        }
    }
    free(prv);
    my_put_err(": No such file or directory.\n");
    return (env);
}

char **previous_dir(char **env)
{
    char *actualdir, *prv = 0;

    for (int i = 0;env && env[i]; i++) {
        if (env && length_diff(env[i], "PWD"))
            actualdir = my_strcpy(actualdir, &env[i][4]);
    }
    for (int i = 0; env && env[i]; i++) {
        if (length_diff(env[i], "OLDPWD")) {
            chdir(copy_after_slash(env[i]));
            prv = my_strcpy(prv, &env[i][7]);
            env[i] = my_strcat("OLDPWD=", actualdir);
        }
    }
    free(actualdir);
    return (last_verif_previous_dir(env, prv));
}

char **modif_env(char **env)
{
    char *cwd = malloc(sizeof(char) * 255), **set = NULL, *prev = NULL;

    getcwd(cwd, 255);
    for (int i = 0;env && env[i]; i++) {
        if (length_diff(env[i], "PWD")) {
            prev = my_strcpy(prev, &env[i][4]);
            env[i] = my_strcat("PWD=", cwd);
        }
    }
    if (env_cd(env, prev, cwd))
        return (env);
    set = setting(prev, cwd);
    env = my_setenv(set, env);
    free(cwd);
    free_tab(set);
    free(prev);
    return (env);
}

char **second_cd(char **tab, char **env)
{
    int verify;
    struct stat test;

    if (tab[1][0] == '-' && tab[1][1] == 0) {
        env = previous_dir(env);
        return (env);
    }
    verify = stat(tab[1], &test);
    if (verify != 0) {
        my_put_err(my_strcat(tab[1], ": No such file or directory.\n"));
        return (env);
    }
    if (!S_ISDIR(test.st_mode)) {
        my_put_err(my_strcat(tab[1], ": Not a directory.\n"));
        return (env);
    }
    chdir(tab[1]);
    env = modif_env(env);
    return (env);
}

char **func_cd(char **tab, char **env)
{
    if (tab[1] != NULL && tab[1][0] != 0 && (!same_str(tab[1], "home") ||
    (same_str(tab[1], "home") && !home_exist(env))))
        return (second_cd(tab, env));
    if (!env || !env[0]) {
        my_putstr("cd: No home directory.\n");
        return (env);
    }
    if (tab[1] && same_str(tab[1], "home"))
        my_putstr("~ \n");
    for (int i = 0; env[i]; i++) {
        if (length_diff(env[i], "HOME")) {
            chdir(copy_after_slash(env[i]));
            env = modif_env(env);
        }
    }
    return (env);
}