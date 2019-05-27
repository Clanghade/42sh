/*
** EPITECH PROJECT, 2019
** do_if.c
** File description:
** Puigsgaur
*/

#include "../headers/fourty_two_sh.h"

char *my_strcpy_after(char *dest, char *src, int n)
{
    for (int i = 0; src[n] != 0; n += 1, i += 1)
        dest[i] = src[n];
    return (dest);
}

int do_if_egual(tmp_t *tmp)
{
    int type_cmd1 = 0;
    int type_cmd2 = 0;

    type_cmd1 = choose_type(tmp->cmd1);
    type_cmd2 = choose_type(tmp->cmd2);
    if (type_cmd1 == 1 && type_cmd2 == 1) {
        type_cmd1 = atoi(tmp->cmd1);
        type_cmd2 = atoi(tmp->cmd2);
        if (type_cmd1 == type_cmd2)
            return (0);
    } else {
        if ((my_strcmp_if(tmp->cmd1, tmp->cmd2)) == 0)
            return (0);
    }
    return (1);
}

int check_if(char *cmd, tmp_t *tmp)
{
    tmp->cmd = NULL;
    tmp->cmd1 = NULL;
    tmp->cmd2 = NULL;
    tmp->ex1 = NULL;
    tmp->y = 0;
    if ((get_cmd1(tmp, cmd)) == 1)
        return (84);
    if ((get_cmd(tmp, cmd)) == 1)
        return (84);
    if ((get_cmd2(tmp, cmd)) == 1)
        return (84);
    if ((get_ex1(tmp, cmd)) == 1) {
        file_exo_error2(tmp);
        return (84);
    }
    return (0);
}

char * do_if(char *cmd, tmp_t *tmp)
{
    cmd_t arr[] = {{"==", &do_if_egual}, {"!=", &do_if_not_egal}, \
    {"<", &do_if_less}, {"<=", &do_if_less_egal}, {">", &do_if_more}, \
    {">=", &do_if_more_egual}};
    int check = -1;

    if ((check_if(cmd, tmp)) == 84)
        return (tmp->ex1);
    for (int y = 0; y < 6; y += 1) {
        if ((strcmp(tmp->cmd, arr[y].cmd)) == 0)
            check = arr[y].fptr(tmp);
        if (check == 0)
            return (tmp->ex1);
    }
    if (tmp->ex1[0] != 'i' && tmp->ex1[1] != 'f')
        tmp->ex1 = " ";
    return (tmp->ex1);
}
