/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** run_binary
*/

#include "../headers/fourty_two_sh.h"

char *leftest(linked_t *tree)
{
    int i = 0;

    if (tree->left)
        return (leftest(tree->left));
    for (; tree->command[i] == ' ' || tree->command[i] == '\t'; i++);
    return (&tree->command[i]);
}

env_modif_t run_semicolon(linked_t *tree, env_modif_t env)
{
    if (same_str(tree->command, ";")) {
        env = run_tree(tree->left, env);
        env = run_tree(tree->right, env);
    }
    return (env);
}

env_modif_t run_redirect_right(linked_t *tree, env_modif_t env)
{
    int fd, keep_exit = dup(1);
    char *left = leftest(tree->right);
    struct stat statis;

    left = delete_last_space(left);
    stat(left, &statis);
    if (directory(tree, left, statis))
        return ((env_modif_t) {env.env, 1, env.a, env.var, env.h});
    else if (same_str(tree->command, ">") &&
    !same_str(tree->right->command, "&2")) {
        fd = open(left, O_CREAT | O_WRONLY | O_TRUNC);
        chmod(left, S_IRWXU);
        dup2(fd, 1);
        env = run_tree(tree->left, env);
        dup2(keep_exit, 1);
        close(fd);
    }
    if (same_str(tree->right->command, "&2"))
        env = error_output_right(tree, env);
    return (env);
}

env_modif_t run_redirect_right_twice(linked_t *tree, env_modif_t env)
{
    int fd, keep_exit = dup(1);
    char *left = leftest(tree->right);
    struct stat statis;

    stat(left, &statis);
    if (directory(tree, left, statis))
        return ((env_modif_t) {env.env, 1, env.a, env.var, env.h});
    else if (same_str(tree->command, ">>")) {
        fd = open(left, O_WRONLY | O_APPEND);
        if (fd == -1)
            fd = open(left, O_CREAT | O_WRONLY);
        chmod(left, S_IRWXU);
        dup2(fd, 1);
        env = run_tree(tree->left, env);
        dup2(keep_exit, 1);
        close(fd);
    }
    return (env);
}

env_modif_t run_tree(linked_t *tree, env_modif_t env)
{
    if (!same_str(tree->command, "|") && !same_str(tree->command, ";") &&
    !same_str(tree->command, "<") && !same_str(tree->command, "<<") &&
    !same_str(tree->command, ">") && !same_str(tree->command, ">>") &&
    !same_str(tree->command, "&&") && !same_str(tree->command, "||"))
        return (my_sh_second(tree->command, env));
    env = run_semicolon(tree, env);
    env = run_or(tree, env);
    env = run_and(tree, env);
    env = run_redirect_right(tree, env);
    env = run_redirect_right_twice(tree, env);
    env = run_redirect_left(tree, env);
    env = run_redirect_left_twice(tree, env);
    env = piping(tree, env);
    return (env);
}