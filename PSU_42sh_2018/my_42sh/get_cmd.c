/*
** EPITECH PROJECT, 2019
** get_cmd.c
** File description:
** Puigsagur
*/

#include "../headers/fourty_two_sh.h"

int get_cmd(tmp_t *tmp, char *cmd)
{
    int nb_c = 0;

    tmp->cmd = NULL;

    for (; cmd[tmp->y] != 0; tmp->y += 1, nb_c += 1) {
        if (cmd[tmp->y] != '=' && cmd[tmp->y] != '!' && cmd[tmp->y] != '<' \
        && cmd[tmp->y] != '>')
            break;
    }
    if (cmd[tmp->y] == 0) {
        file_exo_error(tmp);
        return (1);
    }
    fill_cmd2(tmp, cmd, nb_c);
    return (0);
}

int get_cmd1(tmp_t *tmp, char *cmd)
{
    int nb_c = 0;

    for (; cmd[tmp->y] != 0; tmp->y += 1)
        if (cmd[tmp->y] == '(')
            break;
    if (cmd[tmp->y] != '(') {
        file_exo_error(tmp);
        return (1);
    }
    tmp->y += 1;
    for (; cmd[tmp->y] != 0; tmp->y += 1, nb_c += 1)
        if (cmd[tmp->y] == '=' || cmd[tmp->y] == '!' || cmd[tmp->y] == '<' \
        || cmd[tmp->y] == '>')
            break;
    if (cmd[tmp->y] == 0) {
        file_exo_error(tmp);
        return (1);
    }
    fill_cmd1(tmp, cmd, nb_c);
    return (0);
}

int get_cmd2(tmp_t *tmp, char *cmd)
{
    int nb_c = 0;

    tmp->cmd2 = NULL;
    for (; cmd[tmp->y] != 0; tmp->y += 1, nb_c += 1) {
        if (cmd[tmp->y] == ')')
            break;
    }
    if (cmd[tmp->y] == 0) {
        file_exo_error(tmp);
        return (1);
    }
    tmp->cmd2 = malloc(sizeof(char) *(nb_c + 1));
    tmp->cmd2[nb_c] = 0;
    for (int i = 0, x = tmp->y - nb_c; cmd[x] != 0; i += 1, x += 1) {
        if (cmd[x] == ')')
            break;
        tmp->cmd2[i] = cmd[x];
    }
    return (0);
}

int get_ex1(tmp_t *tmp, char *cmd)
{
    int nb_c = 0;

    if (cmd[tmp->y] == 0)
        return (1);
    tmp->y += 1;
    for (; cmd[tmp->y] != 0; tmp->y += 1, nb_c += 1);
    if (nb_c == 0)
        return (1);
    tmp->ex1 = malloc(sizeof(char) *(nb_c + 1));
    tmp->ex1[nb_c] = 0;
    for (int i = 0, x = tmp->y - nb_c; cmd[x] != 0; i += 1, x += 1)
        tmp->ex1[i] = cmd[x];
    return (0);
}
