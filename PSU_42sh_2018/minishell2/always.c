/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** always
*/

#include "../headers/minishell2.h"

int directory(linked_t *tree, char *left, struct stat statis)
{
    if (same_str(tree->command, "<") && S_ISDIR(statis.st_mode)) {
        my_put_err(left);
        my_put_err(": Is a directory.\n");
        return (1);
    }
    return (0);
}

int exist(int fd, char *left)
{
    if (fd == -1) {
        my_put_err(left);
        my_put_err(": No such file or directory.\n");
        return (0);
    }
    return (1);
}

char **display_env(char **env)
{
    for (int i = 0; env[i]; i++)
        my_putstr(my_strcat(env[i], "\n"));
    return (env);
}

env_modif_t create_doing(char *all_enter, env_modif_t env, linked_t *tree,
char *line)
{
    int fd = open(".tmp", O_CREAT | O_WRONLY | O_TRUNC);
    int keep_exit = dup(1), keep_entry = dup(0);

    dup2(fd, 1);
    chmod(".tmp", S_IRWXU);
    my_putstr(all_enter);
    dup2(keep_exit, 1);
    close(fd);
    fd = open(".tmp", O_RDONLY);
    dup2(fd, 0);
    env = run_tree(tree->left, env);
    dup2(keep_entry, 0);
    close(fd);
    free(all_enter);
    free(line);
    return (env);
}

char *remove_exit(char *str)
{
    if (str[my_strlen(str) - 1] == '1')
        str[my_strlen(str) - 1] = 0;
    return (str);
}