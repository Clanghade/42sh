/*
** EPITECH PROJECT, 2019
** glob.c
** File description:
** Puigsagur
*/

#include "../headers/fourty_two_sh.h"

int check_if_glob(char *str)
{
    for (int i = 0; str[i] != 0; i += 1) {
        if (str[i] == '?' || str[i] == '*' || \
        str[i] == '[' || str[i] == ']')
            return (0);
    }
    return (1);
}

char *check_glob(char *all_cmd)
{
    wordexp_t word;
    int check = 0;
    char *dest = NULL;

    if ((check_if_glob(all_cmd)) == 1)
        return (all_cmd);
    check = wordexp(all_cmd, &word, WRDE_NOCMD);
    if (check != 0)
        return (all_cmd);
    dest = reconcat_tab(word.we_wordv);
    wordfree(&word);
    return (dest);
}