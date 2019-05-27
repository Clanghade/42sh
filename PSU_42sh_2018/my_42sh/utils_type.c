/*
** EPITECH PROJECT, 2019
** utils_type.c
** File description:
** Puigsagur
*/

#include "../headers/fourty_two_sh.h"

void file_exo_error(tmp_t *tmp)
{
    int i = 0;
    char *s = "echo ";
    char *s2 = "if: Expression Syntax.";
    char *s3 = " 1>&2\n";

    tmp->ex1 = malloc(sizeof(char) * 37);
    for (; s[i] != 0; i += 1)
        tmp->ex1[i] = s[i];
    tmp->ex1[i] = '"';
    i += 1;
    for (int x = 0; s2[x] != 0; x += 1, i += 1)
        tmp->ex1[i] = s2[x];
    tmp->ex1[i] = '"';
    i += 1;
    for (int x = 0; s3[x] != 0; x += 1, i += 1)
        tmp->ex1[i] = s3[x];
    tmp->ex1[i] = 0;
}

void file_exo_error2(tmp_t *tmp)
{
    char *s = "echo ";
    char *s2 = "if: Empty if.";
    char *s3 = " 1>&2\n";
    int i = 0;

    tmp->ex1 = malloc(sizeof(char) * 35);
    for (; s[i] != 0; i += 1)
        tmp->ex1[i] = s[i];
    tmp->ex1[i] = '"';
    i += 1;
    for (int x = 0; s2[x] != 0; x += 1, i += 1)
        tmp->ex1[i] = s2[x];
    tmp->ex1[i] = '"';
    i += 1;
    for (int x = 0; s3[x] != 0; x += 1, i += 1)
        tmp->ex1[i] = s3[x];
    tmp->ex1[i] = 0;
}

void print_bad(tmp_t *tmp)
{
    char *s = "echo ";
    char *s2 = "if: not ok.";
    char *s3 = " 1>&2\n";
    int i = 0;

    tmp->ex1 = malloc(sizeof(char) * 35);
    for (; s[i] != 0; i += 1)
        tmp->ex1[i] = s[i];
    tmp->ex1[i] = '"';
    i += 1;
    for (int x = 0; s2[x] != 0; x += 1, i += 1)
        tmp->ex1[i] = s2[x];
    tmp->ex1[i] = '"';
    i += 1;
    for (int x = 0; s3[x] != 0; x += 1, i += 1)
        tmp->ex1[i] = s3[x];
    tmp->ex1[i] = 0;
}

int choose_type(char *cmd)
{
    int nb = 0;
    int i = 0;

    for (; cmd[i] != 0; i += 1) {
        if ((cmd[i] >= 48 && cmd[i] <= 57) || cmd[i] == ' ')
            nb += 1;
    }
    if (nb == i)
        return (1);
    else
        return (2);
    return (0);
}
