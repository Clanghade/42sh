/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** history.c
*/

#include "../headers/minishell1.h"

char *restock(int nb)
{
    char *tmp = malloc(sizeof(char) * nb + 1);

    for (int i = 0; i < nb; i++)
        tmp[i] = '\0';
    return (tmp);
}

char *cnc(char *s1, char *s2)
{
    int i = 0;
    int j = 0;

    for (i = 0; s2[i] != '\0' && s2[i] == ' '; i++);
    for (; s2[i] != '\0'; i++, j++)
        s1[j] = s2[i];
    return (s1);
}

char *cn(char *s1)
{
    char *res = restock(1000);
    int i = 0;
    int j = 0;

    for (i = 0; s1[i] != '\0' && s1[i] == ' '; i++);
    for (; s1[i] != '\0'; i++, j++)
        res[j] = s1[i];
    res[j] = '\0';
    return (res);
}

int get_hist(char **hist)
{
    int i = 0;

    for (i = 0; hist[i] != NULL; i++);
    return (i);
}

int recreate_str(char *str, char **hist)
{
    int i = 0;
    int j = 0;

    for (;str[j] != '\0' && str[j] == ' '; j++);
    if (str[j] != '\0') {
        for (i = 0; hist[i] != NULL; i++);
        hist[i] = cn(str);
    }
    return (0);
}