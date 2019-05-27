/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** my_putstr.c
*/

#include <unistd.h>

int my_strlen(char *str);

int my_put_err(char *str)
{
    if (str)
        write(2, str, my_strlen(str));
    return (1);
}

int my_putstr(char *str)
{
    if (str)
        write(1, str, my_strlen(str));
    return (0);
}