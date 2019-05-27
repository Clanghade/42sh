/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** looking_sign
*/

#include "../headers/fourty_two_sh.h"

linked_t *sign_semicolon(char *line, linked_t *tree)
{
    for (int i = 0; i < my_strlen(line); i++) {
        if (line[i] == ';') {
            tree->command = my_strcat("\0", ";");
            tree->left = tree_built(before_sign(line, ';'), tree->left);
            tree->right = tree_built(after_sign(line, ';'), tree->right);
            return (tree);
        }
    }
    return (oring(line, tree));
}

linked_t *sign_left(char *line, linked_t *tree)
{
    for (int i = 0; i < my_strlen(line); i++) {
        if (line[i] == '<') {
            if (line[i + 1] != '<')
                tree->command = my_strcat("\0", "<");
            else
                tree->command = my_strcat("\0", "<<");
            tree->left = tree_built(before_sign(line, '<'), tree->left);
            tree->right = tree_built(after_sign(line, '<'), tree->right);
            return (tree);
        }
    }
    return (sign_right(line, tree));
}

linked_t *sign_right(char *line, linked_t *tree)
{
    for (int i = 0; i < my_strlen(line); i++) {
        if (line[i] == '>') {
            if (line[i + 1] != '>')
                tree->command = my_strcat("\0", ">");
            else
                tree->command = my_strcat("\0", ">>");
            tree->left = tree_built(before_sign(line, '>'), tree->left);
            tree->right = tree_built(after_sign(line, '>'), tree->right);
            return (tree);
        }
    }
    return (sign_pipe(line, tree));
}

linked_t *sign_pipe(char *line, linked_t *tree)
{
    for (int i = 0; i < my_strlen(line); i++) {
        if (line[i] == '|' && line[i + 1] != '|') {
            tree->command = my_strcat("\0", "|");
            tree->left = tree_built(before_sign(line, '|'), tree->left);
            tree->right = tree_built(after_sign(line, '|'), tree->right);
            return (tree);
        } if (line[i] == '|' && line[i + 1] == '|')
            i++;
    }
    tree->command = my_strcpy(tree->command, line);
    tree->left = NULL;
    tree->right = NULL;
    return (tree);
}

env_modif_t error_output_right(linked_t *tree, env_modif_t env)
{
    int keep_error = dup(2);

    dup2(keep_error, 1);
    tree->left->command = remove_exit(tree->left->command);
    env = run_tree(tree->left, env);
    dup2(keep_error, 1);
    close(keep_error);
    return (env);
}