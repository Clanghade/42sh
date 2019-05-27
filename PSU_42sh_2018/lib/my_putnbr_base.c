/*
** EPITECH PROJECT, 2018
** my_putnbr_base
** File description:
** put a number using his base
*/

#include "../headers/minishell1.h"

int my_putnbr_base(int nb, char *base)
{
    int var;
    int len = my_strlen(base);

    if (nb < 0) {
        my_putchar('-');
        my_putnbr_base(-nb, base);
    }
    if (nb == 0)
        my_putchar(base[0]);
    else if (nb >= len) {
        var = nb % len;
        nb = (nb - var) / len;
        my_putnbr_base(nb, base);
        my_putchar(base[var]);
    } else
        my_putchar(base[nb]);
    return (0);
}

int my_putnbr_base_error(int nb, char *base)
{
    int var;
    int len = my_strlen(base);

    if (nb < 0) {
        putchar_err('-');
        my_putnbr_base_error(-nb, base);
    }
    if (nb == 0)
        putchar_err(base[0]);
    else if (nb >= len) {
        var = nb % len;
        nb = (nb - var) / len;
        my_putnbr_base_error(nb, base);
        putchar_err(base[var]);
    } else
        putchar_err(base[nb]);
    return (0);
}