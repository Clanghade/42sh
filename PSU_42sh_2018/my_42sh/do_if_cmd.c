/*
** EPITECH PROJECT, 2019
** do_if_cmd.c
** File description:
** Puigsagur
*/

#include "../headers/fourty_two_sh.h"

int do_if_not_egal(tmp_t *tmp)
{
    int type_cmd1 = 0;
    int type_cmd2 = 0;

    type_cmd1 = choose_type(tmp->cmd1);
    type_cmd2 = choose_type(tmp->cmd2);
    if (type_cmd1 == 1 && type_cmd2 == 1) {
        type_cmd1 = atoi(tmp->cmd1);
        type_cmd2 = atoi(tmp->cmd2);
        if (type_cmd1 != type_cmd2)
            return (0);
    } else {
        if ((strcmp(tmp->cmd1, tmp->cmd2)) != 0)
            return (0);
    }
    return (1);
}

int do_if_less(tmp_t *tmp)
{
    int type_cmd1 = 0;
    int type_cmd2 = 0;

    type_cmd1 = choose_type(tmp->cmd1);
    type_cmd2 = choose_type(tmp->cmd2);
    if (type_cmd1 == 1 && type_cmd2 == 1) {
        type_cmd1 = atoi(tmp->cmd1);
        type_cmd2 = atoi(tmp->cmd2);
        if (type_cmd1 < type_cmd2)
            return (0);
    } else {
        file_exo_error(tmp);
    }
    return (1);
}

int do_if_less_egal(tmp_t *tmp)
{
    int type_cmd1 = 0;
    int type_cmd2 = 0;

    type_cmd1 = choose_type(tmp->cmd1);
    type_cmd2 = choose_type(tmp->cmd2);
    if (type_cmd1 == 1 && type_cmd2 == 1) {
        type_cmd1 = atoi(tmp->cmd1);
        type_cmd2 = atoi(tmp->cmd2);
        if (type_cmd1 <= type_cmd2)
            return (0);
    } else {
        file_exo_error(tmp);
    }
    return (1);
}

int do_if_more(tmp_t *tmp)
{
    int type_cmd1 = 0;
    int type_cmd2 = 0;

    type_cmd1 = choose_type(tmp->cmd1);
    type_cmd2 = choose_type(tmp->cmd2);
    if (type_cmd1 == 1 && type_cmd2 == 1) {
        type_cmd1 = atoi(tmp->cmd1);
        type_cmd2 = atoi(tmp->cmd2);
        if (type_cmd1 > type_cmd2)
            return (0);
    } else {
        file_exo_error(tmp);
    }
    return (1);
}

int do_if_more_egual(tmp_t *tmp)
{
    int type_cmd1 = 0;
    int type_cmd2 = 0;

    type_cmd1 = choose_type(tmp->cmd1);
    type_cmd2 = choose_type(tmp->cmd2);
    if (type_cmd1 == 1 && type_cmd2 == 1) {
        type_cmd1 = atoi(tmp->cmd1);
        type_cmd2 = atoi(tmp->cmd2);
        if (type_cmd1 >= type_cmd2)
            return (0);
    } else {
        file_exo_error(tmp);
    }
    return (1);
}
