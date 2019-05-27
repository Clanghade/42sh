/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** mysh
*/

#include "minishell1.h"
#include "minishell2.h"

#ifndef MYSH_H_
    #define MYSH_H_

    // quotes
    int quote_pb(char *str, env_modif_t env_modif, linked_t *tree, int type);
    int quote(char *str, env_modif_t env_modif, linked_t *tree);

    // separators
    env_modif_t run_and(linked_t *tree, env_modif_t env);
    linked_t *oring(char *line, linked_t *tree);
    linked_t *anding(char *line, linked_t *tree);
    env_modif_t run_and(linked_t *tree, env_modif_t env);
    env_modif_t run_or(linked_t *tree, env_modif_t env);

    int error_alias(char **tab);
    int error_var(char **tab);
    char *first(char *str);
    char *second(char *str);

    //scripting
    char *check_sh(char *cmd);
    //if
    char *do_if(char *cmd, tmp_t *tmp);
    char *my_strcpy_after(char *dest, char *src, int n);
    int get_cmd(tmp_t *tmp, char *cmd);
    int get_cmd1(tmp_t *tmp, char *cmd);
    int get_cmd2(tmp_t *tmp, char *cmd);
    int get_ex1(tmp_t *tmp, char *cmd);
    int do_if_egual(tmp_t *tmp);
    int do_if_not_egal(tmp_t *tmp);
    int do_if_less(tmp_t *tmp);
    int do_if_less_egal(tmp_t *tmp);
    int do_if_more(tmp_t *tmp);
    int do_if_more_egual(tmp_t *tmp);
    int choose_type(char *cmd);
    void file_exo_error(tmp_t *tmp);
    void file_exo_error2(tmp_t *tmp);
    void fill_cmd1(tmp_t *tmp, char *cmd, int nb);
    void fill_cmd2(tmp_t *tmp, char *cmd, int nb_c);
    void print_bad(tmp_t *tmp);
    int my_strcmp_if(char *s1, char *s2);

    //repeat
    char *check_repeat(char *all_cmd);
    char *fill_repeat_cmd(tmp_t *tmp, char *cmd, char *all_cmd);
    int count_nb3(tmp_t *tmp, char *all_cmd, int i);

    //check_glob
    char *check_glob(char *all_cmd);

#endif /* !MYSH_H_ */
