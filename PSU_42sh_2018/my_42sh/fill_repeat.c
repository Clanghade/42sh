/*
** EPITECH PROJECT, 2019
** fill_repeat.c
** File description:
** Puigsagur
*/

#include "../headers/fourty_two_sh.h"

int count_nb3(tmp_t *tmp, char *all_cmd, int i)
{
    for (int z = 0; all_cmd[i] != 0; z += 1, i += 1) {
        if (all_cmd[i] < 48 || all_cmd[i] > 57)
            break;
        tmp->cmd[z] = all_cmd[i];
    }
    return (i);
}

char *fill_up(tmp_t *tmp, char *cmd, char *all_cmd)
{
    for (; all_cmd[tmp->y] != 0; tmp->y += 1) {
        if (all_cmd[tmp->y] == 'r' && all_cmd[tmp->y + 1] == 'e' && \
        all_cmd[tmp->y + 2] == 'p' && all_cmd[tmp->y + 3] == 'e' && \
        all_cmd[tmp->y + 4] == 'a' && all_cmd[tmp->y + 5] == 't')
            break;
        cmd[tmp->y] = all_cmd[tmp->y];
    }
    return (cmd);
}

char *fill_repeat_nb(tmp_t *tmp, char *cmd)
{
    for (int x = 0; tmp->cmd1[x] != 0; x += 1, tmp->y += 1)
        cmd[tmp->y] = tmp->cmd1[x];
    return (cmd);
}

char *fill_repeat_cmd(tmp_t *tmp, char *cmd, char *all_cmd)
{
    int nb = tmp->y;

    tmp->y = 0;
    tmp->nb1 = 0;
    cmd = fill_up(tmp, cmd, all_cmd);
    for (int x = 0; x < nb; x += 1) {
        cmd = fill_repeat_nb(tmp, cmd);
        if (x + 1 != nb) {
            cmd[tmp->y] = ';';
            tmp->y += 1;
        }
    }
    for (; all_cmd[tmp->nb2] != 0; tmp->y += 1, tmp->nb2 += 1)
        cmd[tmp->y] = all_cmd[tmp->nb2];
    cmd[tmp->y] = 0;
    return (cmd);
}
