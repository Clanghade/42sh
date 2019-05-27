/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** copy a str
*/

#include "../headers/minishell1.h"

char *my_strcpy(char *dest, char *src)
{
    if (!src)
        return (NULL);
    dest = restock(my_strlen(src) + 1);
    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[my_strlen(src)] = '\0';
    return (dest);
}
