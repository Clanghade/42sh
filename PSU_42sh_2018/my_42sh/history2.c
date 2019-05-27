/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** history2.c
*/

#include "../headers/minishell1.h"

void replace_chain(char *str, char c, int nb, int size)
{
    str[size + 2] = '\0';
    for (int i = size; i > nb; i--)
        str[i] = str[i - 1];
    str[nb] = c;
    for (int i = nb + 1; i < size + 1; i++)
        printf(" ");
    for (int i = size + 1; i > nb + 1; i--)
        printf("\b");
    for (int i = nb; i < size + 1; i++)
        printf("%c", str[i]);
    for (int i = size + 1; i > nb + 1; i--)
        printf("\b");
}

void replace_chain2(char *str, int nb, int size)
{
    int i = 0;

    printf("\b");
    for (int i = nb - 1; i < size; i++)
        printf(" ");
    for (int i = size; i > nb - 1; i--)
        printf("\b");
    for (i = nb - 1; str[i + 1] != '\0'; i++)
        str[i] = str[i + 1];
    str[i] = '\0';
    for (int i = nb - 1; i < size; i++)
        printf("%c", str[i]);
    for (int i = size; i > nb; i--)
        printf("\b");
}

int destroy_chain(char *str, int nb, int pos, char **hist)
{
    int lgt = 0;

    for (int i = 0; i < nb; i++)
        printf("\b");
    for (int i = 0; str[i] != '\0'; i++)
        printf(" ");
    for (int i = 0; str[i] != '\0'; i++)
        printf("\b");
    for (int i = 0; i < 1000; i++)
        str[i] = '\0';
    cnc(str, hist[pos]);
    for (lgt = 0; str[lgt] != '\0'; lgt++)
        printf("%c", str[lgt]);
    return (lgt);
}

int reset_chain(char *str, int nb)
{
    for (int i = 0; i < nb; i++)
        printf("\b");
    for (int i = 0; str[i] != '\0'; i++)
        printf(" ");
    for (int i = 0; str[i] != '\0'; i++)
        printf("\b");
    for (int i = 0; i < 1000; i++)
        str[i] = '\0';
    return (0);
}