/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for minishell2
*/

#include "headers/minishell2.h"

int error_on_arg(int ac)
{
    my_put_err("Error.\n");
    my_putnbr_base_error(ac - 1, "0123456789");
    my_put_err(" argument(s) given when none is required\n");
    return (84);
}

int usage(char *exec)
{
    my_putstr("USAGE\n\t");
    my_putstr(exec);
    my_putstr("\n\nDESCRIPTION\n\t");
    my_putstr(exec);
    my_putstr("\tbinary for minishell2.\n\t\tUNIX command interpreter\n");
    return (0);
}

hist_t *init_hist(void)
{
    hist_t *h = malloc(sizeof(hist_t));

    h->nb = 0;
    h->pos = 0;
    h->size = 0;
    h->stock = restock(1000);
    h->hist = malloc(sizeof(char *) * 100);
    for (int i = 0; i < 100; i++)
        h->hist[i] = NULL;
    return (h);
}

env_modif_t init_alias_var(env_modif_t env)
{
    env.var = init_var();
    env.a = init_alias();
    env.h = init_hist();
    return (env);
}

int main(int ac, char **av, char **env)
{
    env_modif_t env_modif;
    char *comm = NULL;
    linked_t *tree = NULL;

    env_modif = init_alias_var(env_modif);
    env_modif.env = env;
    env_modif.sortie = 0;
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0)
        return (usage(av[0]));
    else if (ac != 1)
        return (error_on_arg(ac));
    else
        return (my_sh(env_modif, comm, tree));
}