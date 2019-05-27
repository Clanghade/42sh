/*
** EPITECH PROJECT, 2018
** getnextline
** File description:
** getnextline
*/

#include "../headers/get_next_line.h"
#include "../headers/minishell1.h"

char *my_strcat(char *s1, char *s2)
{
    char *res = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 3));
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return (NULL);
    for (i = 0; s1[i] != '\0'; i++)
        res[i] = s1[i];
    for (int j = 0; s2[j] != '\0'; j++, i++)
        res[i] = s2[j];
    res[i] = '\0';
    return (res);
}

char *copy_end(char *src, char *dest, int end)
{
    int i = 0;

    for (; end < my_strlen(src); end++, i++)
        dest[i] = src[end];
    dest[i] = 0;
    return (dest);
}

char *inf_loop(char *s, char *save, int verif_second, int fd)
{
    int verif;
    char *second_s = malloc(sizeof(char) * (READ_SIZE + 1));

    if (second_s == NULL)
        return (NULL);
    while (1) {
        for (int i = 0; i < my_strlen(s); i++)
            if (s[i] == '\n') {
                save = copy_end(s, save, i + 1);
                s[i] = 0;
                return (s);
            }
        verif = read(fd, second_s, READ_SIZE);
        second_s[READ_SIZE] = 0;
        if (verif == 0 && verif_second != 0)
            return (s);
        if (verif < 0 || (verif == 0 && verif_second == 0))
            return (NULL);
        s = my_strcat(s, second_s);
    }
}

char *get_next_line(int fd)
{
    char *s = malloc(sizeof(char) * (READ_SIZE + 1));
    static char *save = NULL;
    int verif, verif_second;

    if (s == NULL || fd == -1)
        return (NULL);
    for (int i = 0; i < READ_SIZE + 1; i++)
        s[i] = '\0';
    verif = read(fd, s, READ_SIZE);
    if (verif == -1)
        return (NULL);
    verif_second = verif;
    if (save == NULL) {
        save = malloc(sizeof(char) * (READ_SIZE + 1));
        save[0] = '\0';
    }
    if (save == NULL)
        return (NULL);
    s = my_strcat(save, s);
    return (inf_loop(s, save, verif_second, fd));
}