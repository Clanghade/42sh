/*
** EPITECH PROJECT, 2019
** check_sh.c
** File description:
** Puigsagur
*/

#include "../headers/fourty_two_sh.h"

char *file_allcmd(char *all_cmd, char *exe, tmp_t *tmp)
{
    int nb = 0;
    int nb1 = 0;
    int x = 0;
    char *cmd = NULL;

    for (; exe[nb] != 0; nb += 1);
    for (int i = tmp->nb2; all_cmd[i] != 0; i += 1, nb1 += 1);
    cmd = malloc(sizeof(char) * (nb + nb1 + tmp->nb1 + 1));
    for (int i = 0; i < tmp->nb1; i += 1, x += 1)
        cmd[x] = all_cmd[i];
    for (int i = 0; i < nb; i += 1, x += 1)
        cmd[x] = exe[i];
    for (; all_cmd[tmp->nb2]; tmp->nb2 += 1, x += 1)
        cmd[x] = all_cmd[tmp->nb2];
    cmd[nb + nb1 + tmp->nb1] = 0;
    return (cmd);
}

char *file_cmd(char *cmd, char *str, int y, tmp_t *tmp)
{
    int nb = 0;

    for (int i = y, nb_p = 0; str[i] != 0; i += 1, nb += 1) {
        if (str[i] == '(' || str[i] == ')')
            nb_p += 1;
        if (str[i] == ';' || str[i] == '|' || str[i] == '&' || \
        (str[i] == '<' && nb_p >= 2) || (str[i] == '>' && nb_p >= 2)) {
            break;
        }
    }
    cmd = malloc(sizeof(char) * (nb + 1));
    for (int i = y, x = 0; i < nb + y; i += 1, x += 1)
        cmd[x] = str[i];
    cmd[nb] = 0;
    tmp->nb1 = y;
    tmp->nb2 = y + nb;
    return (cmd);
}

char *parsing_cmd(char *str, tmp_t *tmp)
{
    char *cmd = NULL;

    tmp->nb1 = 0;
    tmp->nb2 = 0;
    for (int y = 0; str[y + 1] != 0; y += 1) {
        if (str[y] == 'i' && str[y + 1] == 'f')
            cmd = file_cmd(cmd, str, y, tmp);
    }
    return (cmd);
}

char *check_sh(char *all_cmd)
{
    char *to_exe = NULL;
    tmp_t *tmp = malloc(sizeof(tmp_t));
    char *cmd = parsing_cmd(all_cmd, tmp);
    tmp->ex1 = NULL;

    if (cmd == NULL)
        return (all_cmd);
    for (int i = 0; cmd[i + 1] != 0; i += 1) {
        if (cmd[i] == 'i' && cmd[i + 1] == 'f')
            to_exe = do_if(cmd, tmp);
    }
    to_exe = file_allcmd(all_cmd, to_exe, tmp);
    free(tmp->cmd);
    free(tmp->cmd1);
    free(tmp->cmd2);
    free(cmd);
    return (to_exe);
}
