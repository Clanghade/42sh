/*
** EPITECH PROJECT, 2018
** function_exit
** File description:
** funciton for exit
*/

#include "../headers/fourty_two_sh.h"

void function_exit(char **tab)
{
    int ex = 0;

    if (tab[1]) {
        if (my_str_isnum(tab[1])) {
            my_put_err("exit: Expression Syntax.\n");
            return;
        }
        ex = my_getnbr(tab[1]);
    }
    free_tab(tab);
    exit(ex);
}

int setting_comm(char **comm, env_modif_t env, linked_t *tree)
{
    *comm = check_sh(*comm);
    *comm = check_repeat(*comm);
    if (comm[0][0] == ' ' && comm[0][1] == 0)
        return (my_sh(env, *comm, tree));
    return (0);
}
