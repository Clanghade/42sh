/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** error_exe.c
*/

#include "../headers/minishell1.h"

void core(int i)
{
    if (WCOREDUMP(i))
        my_put_err(" (core dumped)");
    my_put_err("\n");
}

int disp_error(int i)
{
    if (WIFSIGNALED(i)) {
        if (WTERMSIG(i) == SIGABRT) {
            my_put_err("Abort");
            core(i);
            return (134);
        }
        if (WTERMSIG(i) == SIGFPE) {
            my_put_err("Floating exception");
            core(i);
            return (136);
        }
        if (WTERMSIG(i) == SIGSEGV) {
            my_put_err("Segmentation fault");
            core(i);
            return (139);
        }
    }
    return (i == 256 ? 1 : 0);
}