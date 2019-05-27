/*
** EPITECH PROJECT, 2018
** exec_prog.c
** File description:
** how exec_programs
*/

#include "../headers/fourty_two_sh.h"

char *cut_after_point(char *way)
{
    char *test = malloc(sizeof(char) * 255);

    for (int i = 0; i < my_strlen(way); i++) {
        if (way[i] == ':') {
            test[i] = 0;
            return (test);
        }
        test[i] = way[i];
    }
    free(test);
    return (NULL);
}

int point_rank(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == ':')
            return (i);
    }
    return (my_strlen(str));
}

int search_path(char **env)
{
    for (int i = 0; env[i]; i++) {
        if (length_diff(env[i], "PATH="))
            return (i);
    }
    return (0);
}

void try_with_path(char **tab, char **env)
{
    int path = search_path(env);
    struct stat test;
    char **all_path;

    test.st_mode = 0;
    if (path) {
        all_path = my_str_to_tab(&env[path][5], ':');
        for (int i = 0; all_path[i]; i++)
            execve(my_strcat(all_path[i], my_strcat("/", tab[0])), tab, env);
        free_tab(all_path);
    }
    stat(tab[0], &test);
    if (S_ISDIR(test.st_mode)) {
        my_put_err(my_strcat(tab[0], ": Permisison denied.\n"));
        exit (1);
    }
    my_put_err(tab[0]);
    my_put_err(": Command not found.\n");
    exit (1);
    return;
}

int exec_prog(char *comm, char **env)
{
    int i;
    pid_t test = fork();
    char **tab = NULL;

    comm = check_glob(comm);
    comm ? tab = my_str_to_tab(comm, ' ') : 0;
    if (test) {
        waitpid(test, &i, 0);
        return (disp_error(i));
    } else {
        if (!tab[0]) {
            my_put_err(": Command not found.\n");
            exit(1);
        } else {
            execve(tab[0], tab, env);
            try_with_path(tab, env);
        }
    }
    return (0);
}