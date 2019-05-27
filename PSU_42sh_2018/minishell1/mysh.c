/*
** EPITECH PROJECT, 2018
** my_sh
** File description:
** main program for minishell1
*/

#include "../headers/fourty_two_sh.h"

char *search_home(char **env)
{
    char *tild = malloc(sizeof(char) * 255);

    for (int i = 0; env[i]; i++) {
        if (length_diff(env[i], "HOME")) {
            tild = copy_after_slash(env[i]);
            return (tild);
        }
    }
    free(tild);
    return (NULL);
}

char *maybe_tild(char *s, char *tild)
{
    if (tild && length_diff(s, tild))
        return (my_strcat("~", &s[my_strlen(tild)]));
    return (s);
}

void arraying(env_modif_t env_modif)
{
    char *tild = search_home(env_modif.env);
    char *array = malloc(sizeof(char) * 255);

    getcwd(array, 255);
    array = maybe_tild(array, tild);
    if (isatty(0))
        my_putstr(my_strcat (array, "> "));
    free(array);
}

int my_sh(env_modif_t env, char *comm, linked_t *tree)
{
    size_t s = 0;
    int test = 0;

    arraying(env);
    if (isatty(0))
        comm = non_block_get(env.h, env, tree);
    else
        test = getline(&comm, &s, stdin);
    if (comm == NULL || test == -1 || comm[0] == '\n')
        return (env.sortie);
    env.sortie = 0;
    setting_comm(&comm, env, tree);
    quote(comm, env, tree);
    if (comm[my_strlen(comm) - 1] == '\n')
        comm[my_strlen(comm) - 1] = 0;
    comm = al_var_check(comm, env);
    tree = tree_built(comm, tree);
    env = run_tree(tree, env);
    free_struct(tree);
    return (my_sh(env, comm, tree));
}

env_modif_t my_sh_second(char *comm, env_modif_t env_modif)
{
    char **tab = my_str_to_tab(comm, ' ');

    if (verif_commands(tab, &env_modif) ||
    second_command(tab, &env_modif, env_modif))
        return (env_modif);
    if (same_str(tab[0], "unsetenv")) {
        env_modif.env = my_unsetenv(tab, env_modif.env);
        free_tab(tab);
        return (env_modif);
    }
    if (same_str(tab[0], "exit")) {
        function_exit(tab);
        free_tab(tab);
        return (env_modif);
    }
    env_modif.sortie = exec_prog(comm, env_modif.env);
    free_tab(tab);
    return (env_modif);
}
