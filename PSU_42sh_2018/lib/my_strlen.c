/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** length of a str
*/

int my_strlen(char *str)
{
    int i = 0;

    if (str)
        for (; str[i]; i++);
    return (i);
}