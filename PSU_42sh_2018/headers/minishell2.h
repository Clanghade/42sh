/*
** EPITECH PROJECT, 2019
** minishell2.h
** File description:
** header for minishell2
*/

#ifndef MINISHELL2
#define MINISHELL2

#include "minishell1.h"
#include <fcntl.h>

//freedom.c
void free_struct(linked_t *linked);
void free_tab(char **tab);

//binary tree
linked_t *tree_built(char *line, linked_t *tree);
char *after_sign(char *line, char sign);
char *before_sign(char *line, char sign);
linked_t *initiate_tree(void);

//looking sign
linked_t *sign_semicolon(char *line, linked_t *tree);
linked_t *sign_left(char *line, linked_t *tree);
linked_t *sign_right(char *line, linked_t *tree);
linked_t *sign_pipe(char *line, linked_t *tree);
env_modif_t error_output_right(linked_t *tree, env_modif_t env);

//run_binary
env_modif_t run_tree(linked_t *tree, env_modif_t env);
char *leftest(linked_t *tree);

//redirecting_left
env_modif_t run_redirect_left(linked_t *tree, env_modif_t env);
env_modif_t run_redirect_left_twice(linked_t *tree, env_modif_t env);
env_modif_t piping(linked_t *tree, env_modif_t env);

//always
int directory(linked_t *tree, char *left, \
struct stat statis);
int exist(int fd, char *left);
env_modif_t create_doing(char *all_enter, env_modif_t env, linked_t *tree,
char *line);
char *remove_exit(char *str);

//mysh
int verif_commands(char **tab, env_modif_t *env);
int second_command(char **tab, env_modif_t *env, env_modif_t);
int invalid(env_modif_t env);

alias_t *init_alias(void);
var_t *init_var(void);
#endif /*   MINISHELL2  */