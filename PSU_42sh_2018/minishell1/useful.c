/*
** EPITECH PROJECT, 2018
** useful
** File description:
** functions used
*/

#include "../headers/minishell1.h"

int length_diff(char *s1, char *s2)
{
    for (int i = 0; i < my_strlen(s2); i++) {
        if (s1[i] != s2[i])
            return (0);
    }
    return (1);
}

char *copy_after_slash(char *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        if (str[i] == '/')
            return (&str[i]);
    return (str);
}

int same_str(char *s1, char *s2)
{
    if (!s1 || !s2)
        return (0);
    if (my_strlen(s1) != my_strlen(s2))
        return (0);
    for (int i = 0; i < my_strlen(s1); i++) {
        if (s1[i] != s2[i])
            return (0);
    }
    return (1);
}

char **setting(char *prev, char *cwd)
{
    char **set = malloc(sizeof(char *) * 5);

    set[0] = my_strcat("\0", "a");
    set[1] = my_strcat("\0", "OLDPWD");
    if (prev)
        set[2] = my_strcpy(set[2], prev);
    else
        set[2] = my_strcpy(set[2], cwd);
    set[3] = NULL;
    return (set);
}

int home_exist(char **env)
{
    for (int i = 0; env && env[i]; i++) {
        if (length_diff(env[i], "HOME"))
            return (1);
    }
    return (0);
}