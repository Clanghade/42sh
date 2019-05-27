/*
** EPITECH PROJECT, 2019
** binary_tree.c
** File description:
** construction of the binary_tree
*/

#include "../headers/minishell2.h"

linked_t *initiate_tree(void)
{
    linked_t *tree = malloc(sizeof(linked_t));

    tree->command = NULL;
    tree->fd[0] = 0;
    tree->fd[1] = 1;
    tree->left = NULL;
    tree->right = NULL;
    return (tree);
}

char *before_sign(char *line, char sign)
{
    char *before = malloc(sizeof(char) * my_strlen(line));
    int i = 0;

    for (; line[i] != sign; i++)
        before[i] = line[i];
    before[i] = 0;
    return (before);
}

char *after_sign(char *line, char sign)
{
    char *after = malloc(sizeof(char) * my_strlen(line));
    int i = 0, j = 0;

    for (; line[i] != sign; i++);
    i++;
    if (line[i] == sign)
        i++;
    if (sign == ';')
        for (; line[i] == sign || line[i] == ' ' || line[i] == '\t'; i++);
    for (; line[i] != 0; i++, j++)
        after[j] = line[i];
    after[j] = 0;
    return  (after);
}

int verify_error(char *line)
{
    for (int i = 0; line[i]; i++) {
        if (line[i] == '<' || line[i] == ';' ||
        line[i] == '>' || line[i] == '|') {
            if ((line[i] == '<' && line[i + 1] == '<') ||
            (line[i] == '>' && line[i + 1] == '>') ||
            (line[i] == '|' && line[i + 1] == '|'))
                i++;
            i++;
            for (; (line[i - 1] == ';' || line[i - 1] == ' ') &&
            (line[i] == ';' || line[i] == ' ' || line[i] == '\t'); i++);
            if (line[i] == '<' || line[i] == ';' ||
            line[i] == '>' || line[i] == '|') {
                my_putstr("Invalid null command.\n");
                return (1);
            }
        }
    }
    return (0);
}

linked_t *tree_built(char *line, linked_t *tree)
{
    if (verify_error(line))
        return (NULL);
    tree = initiate_tree();
    tree = sign_semicolon(line, tree);
    return (tree);
}