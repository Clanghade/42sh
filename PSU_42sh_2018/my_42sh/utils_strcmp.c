/*
** EPITECH PROJECT, 2019
** utils_strcmp.c
** File description:
** Puigsagur
*/

#include "../headers/fourty_two_sh.h"

char *edit_str(char *dest, char *str, int n)
{
    for (int i = 0; str[i] != 0; i += 1) {
        if (str[i] == ' ')
            continue;
        dest[n] = str[i];
        n += 1;
    }
    dest[n] = 0;
    return (dest);
}

int my_strcmp_if(char *s1, char *s2)
{
    int n = 0;
    int nb = 0;
    char *str1 = NULL;
    char *str2 = NULL;

    for (; s1[n] != 0; n += 1);
    for (; s2[nb] != 0; nb += 1);
    str1 = malloc(sizeof(char) * (n + 1));
    str2 = malloc(sizeof(char) * (nb + 1));
    n = 0;
    nb = 0;
    str1 = edit_str(str1, s1, n);
    str2 = edit_str(str2, s2, nb);
    if ((strcmp(str1, str2)) == 0)
        return (0);
    return (1);
}
