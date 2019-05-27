/*
** EPITECH PROJECT, 2019
** fill_cmd1.c
** File description:
** Puigsagur
*/

#include "../headers/fourty_two_sh.h"

void fill_cmd1(tmp_t *tmp, char *cmd, int nb)
{
    tmp->cmd1 = NULL;
    tmp->cmd1 = malloc(sizeof(char) * (nb + 1));
    tmp->cmd1[nb] = 0;

    for (int i = 0, x = tmp->y - nb; cmd[x] != 0; i += 1, x += 1) {
        if (cmd[x] == '=' || cmd[x] == '!' || cmd[x] == '<' \
        || cmd[x] == '>')
            break;
        tmp->cmd1[i] = cmd[x];
    }
}

void fill_cmd2(tmp_t *tmp, char *cmd, int nb_c)
{
    tmp->cmd = malloc(sizeof(char) *(nb_c + 1));
    tmp->cmd[nb_c] = 0;
    for (int i = 0, x = tmp->y - nb_c; cmd[x] != 0; i += 1, x += 1) {
        if (cmd[x] != '=' && cmd[x] != '!' && cmd[x] != '<' \
        && cmd[x] != '>')
            break;
        tmp->cmd[i] = cmd[x];
    }
}
