/*
** EPITECH PROJECT, 2018
** my_sh
** File description:
** free functions
*/

#include "../headers/minishell2.h"

void free_tab(char **tab)
{
    if (tab) {
        for (int i = 0; tab[i]; i++)
            free(tab[i]);
        free(tab);
    }
}

void free_struct(linked_t *linked)
{
    if (linked) {
        if (linked->left)
            free_struct(linked->left);
        if (linked->right)
            free_struct(linked->right);
        if (linked->command)
            free(linked->command);
        free(linked);
    }
}