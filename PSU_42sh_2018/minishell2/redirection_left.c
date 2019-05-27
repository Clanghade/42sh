/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** redirection_right
*/

#include "../headers/fourty_two_sh.h"

env_modif_t run_redirect_left(linked_t *tree, env_modif_t env)
{
    int fd, keep_entry = dup(0);
    char *left = leftest(tree->right);
    struct stat statis;

    stat(left, &statis);
    if (directory(tree, left, statis))
        return ((env_modif_t) {env.env, 1, env.a, env.var, env.h});
    else if (same_str(tree->command, "<")) {
        fd = open(left, O_RDONLY);
        if (!exist(fd, left))
            return ((env_modif_t) {env.env, 1, env.a, env.var, env.h});
        dup2(fd, 0);
        env = run_tree(tree->left, env);
        dup2(keep_entry, 0);
        close(fd);
    }
    return (env);
}

char *getting_line(env_modif_t env, linked_t *tree)
{
    char *line = NULL;
    size_t size;

    if (isatty(0)) {
        my_putstr("? ");
        line = non_block_get(env.h, env, tree);
        line = my_strcat(line, "\n");
    } else
        getline (&line, &size, stdin);
    return (line);
}

env_modif_t run_redirect_left_twice(linked_t *tree, env_modif_t env)
{
    char *left = leftest(tree->right), *line = NULL, *all_enter = NULL;
    struct stat statis;

    stat(left, &statis);
    if (directory(tree, left, statis))
        return ((env_modif_t) {env.env, 1, env.a, env.var, env.h});
    else if (same_str(tree->command, "<<")) {
        while (!same_str(line, left)) {
            line = getting_line(env, tree);
            if (!all_enter)
                all_enter = my_strcpy(all_enter, line);
            else if (!same_str(my_strcat(left, "\n"), line))
                all_enter = my_strcat(all_enter, line);
            line[my_strlen(line) - 1] = 0;
        }
        env = create_doing(all_enter, env, tree, line);
    }
    return (env);
}

env_modif_t piping(linked_t *tree, env_modif_t env)
{
    int fd[2], save_entry = dup(0), save_exit = dup(1), pid;

    if (same_str(tree->command, "|")) {
        if (pipe(fd) != 0)
            return ((env_modif_t) {env.env, 84, env.a, env.var, env.h});
        pid = fork();
        if (pid) {
            dup2(fd[0], 0);
            close(fd[1]);
            env = run_tree(tree->right, env);
        } else {
            dup2(fd[1], 1);
            close(fd[0]);
            env = run_tree(tree->left, env);
            exit (0);
        }
        dup2(save_entry, 0);
        dup2(save_exit, 1);
    }
    return (env);
}