/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** putchar
*/

#include <unistd.h>
#include "../headers/minishell2.h"

int my_putchar(char c)
{
    write (1, &c, 1);
    return (0);
}

void putchar_err(char c)
{
    write (2, &c, 1);
}

int str_compare(char *c1, char *c2)
{
    if (c1 == NULL || c2 == NULL)
        return (0);
    if (my_strlen(c1) != my_strlen(c2))
        return (0);
    for (int i = 0; c1[i] != '\0' && c2[i] != '\0'; i++) {
        if (c1[i] != c2[i]) {
            return (0);
        }
    }
    return (1);
}

int my_fullcompare(char *str1, char *str2)
{
    int j = 0;

    for (int i = 0; str1[i] != '\0';) {
        for (j = 0; str2[j] != '\0' && str1[i] == str2[j]; j++, i++);
        if (str2[j] == '\0' && (str1[i] == '\0' || str1[i] < 48 ||
        (str1[i] > 57 && str1[i] < 65) || (str1[i] > 90 && str1[i] < 97) ||
        str1[i] > 122)) {
            return (1);
        } else if (j == 0)
            i++;
    }
    return (0);
}

int my_fullcmp(char *str1, char *str2)
{
    int j = 0;

    for (int i = 0; str1[i] != '\0';) {
        for (j = 0; str2[j] != '\0' && str1[i] == str2[j]; j++, i++);
        if (str2[j] == '\0' && (str1[i] == '\0' || str1[i] < 48 ||
        (str1[i] > 57 && str1[i] < 65) || (str1[i] > 90 && str1[i] < 97) ||
        str1[i] > 122)) {
            return (i - j);
        } else if (j == 0)
            i++;
    }
    return (-1);
}