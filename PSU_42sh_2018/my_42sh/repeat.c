/*
** EPITECH PROJECT, 2019
** repeat.c
** File description:
** Puigsagur
*/

#include "../headers/fourty_two_sh.h"

int count_nb2(tmp_t *tmp, char *all_cmd, int i)
{
    for (int z = 0; all_cmd[i] != 0; i += 1, z += 1) {
        if (all_cmd[i] >= 48 && all_cmd[i] <= 57)
            break;
        tmp->cmd1[z] = all_cmd[i];
    }
    return (i);
}

int count_nb1(tmp_t *tmp, char *all_cmd, int i)
{
    for (; all_cmd[i] != 0; i += 1, tmp->nb1 += 1)
        if (all_cmd[i] == 'r' && all_cmd[i + 1] == 'e' && \
        all_cmd[i + 2] == 'p' && all_cmd[i + 3] == 'e' && \
        all_cmd[i + 4] == 'a' && all_cmd[i + 5] == 't')
            break;
    i += 6;
    return (i);
}

int count_nb(tmp_t *tmp, char *all_cmd)
{
    int i = 0;
    int n = 0;
    tmp->y = 0;
    tmp->cmd = malloc(sizeof(char) * 1000);
    tmp->cmd1 = malloc(sizeof(char) * 1000);

    for (int z = 0; z < 999; z += 1) {
        tmp->cmd[z] = 0;
        tmp->cmd1[z] = 0;
    }
    i = count_nb1(tmp, all_cmd, i);
    tmp->nb1 = i;
    i = count_nb2(tmp, all_cmd, i);
    i = count_nb3(tmp, all_cmd, i);
    for (; tmp->cmd1[n] != 0; n += 1);
    tmp->nb2 = i;
    for (; all_cmd[i] != 0; i += 1, tmp->nb1 += 1);
    return (n);
}

char *do_repeat(tmp_t *tmp, char *all_cmd)
{
    char *cmd = NULL;
    int n = 0;

    tmp->nb1 = 0;
    tmp->nb2 = 0;
    n = count_nb(tmp, all_cmd);
    tmp->y = atoi(tmp->cmd);
    if (tmp->y <= 0)
        tmp->y = 1;
    tmp->nb1 += (n * tmp->y + tmp->y);
    cmd = malloc(sizeof(char) * (tmp->nb1 + 1));
    cmd = fill_repeat_cmd(tmp, cmd, all_cmd);
    return (cmd);
}

char *check_repeat(char *all_cmd)
{
    tmp_t *tmp = malloc(sizeof(tmp_t));
    int nb = 0;
    int i = 0;
    int n = 0;

    for (; all_cmd[n] != 0; n += 1);
    if (n < 8)
        return (all_cmd);
    for (; all_cmd[i + 5] != 0; i += 1, nb += 1) {
        if (all_cmd[i] == 'r' && all_cmd[i + 1] == 'e' && \
        all_cmd[i + 2] == 'p' && all_cmd[i + 3] == 'e' && \
        all_cmd[i + 4] == 'a' && all_cmd[i + 5] == 't')
            break;
    }
    if (all_cmd[i + 5] == 0)
        return (all_cmd);
    all_cmd = do_repeat(tmp, all_cmd);
    free(tmp->cmd);
    free(tmp->cmd1);
    return (all_cmd);
}
