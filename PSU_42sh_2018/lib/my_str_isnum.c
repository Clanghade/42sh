/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** my_str_isnum
*/

#include <stdio.h>

int my_str_is_alpha(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (!(str[i] >= 'a' && str[i] <= 'z') &&
        !(str[i] >= 'A' && str[i] <= 'Z'))
            return (1);
    }
    return (0);
}

int my_str_isnum(char *str)
{
    int i = 0;

    if (str[i] == '-')
        i++;
    for (; str[i] != '\0'; i++) {
        if (!((str[i] >= '0') && (str[i] <= '9')))
            return (1);
    }
    return (0);
}

int my_str_is_alpha_num(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (my_str_isnum(str) && my_str_is_alpha(str))
            return (1);
    }
    return (0);
}