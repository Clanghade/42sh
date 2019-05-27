/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** header for minishell1
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <signal.h>
#include <ncurses.h>
#include <fcntl.h>
#include <termios.h>
#include <wordexp.h>
#include "minishell2.h"


#ifndef MINISHELL
#define MINISHELL

typedef struct dirent dirent_t;

typedef struct tmp_s {
    char *cmd;
    char *cmd1;
    char *cmd2;
    char *ex1;
    int y;
    int nb1;
    int nb2;
} tmp_t;

typedef struct cmd_s {
    char *cmd;
    int (*fptr)(tmp_t *tmp);
} cmd_t;

typedef struct hist_s
{
    int nb;
    int pos;
    int size;
    char tmp;
    char **hist;
    char *stock;
} hist_t;

typedef struct alias_s
{
    char **alias;
    char **alias_r;
} alias_t;

typedef struct var_s
{
    char **var;
    char **var_r;
} var_t;

typedef struct env_modif_s
{
    char **env;
    int sortie;
    alias_t *a;
    var_t *var;
    hist_t *h;
} env_modif_t;


typedef struct linked_s
{
    char *command;
    int fd[2];
    struct linked_s *left;
    struct linked_s *right;
} linked_t;

//programm outside
int my_put_err(char *str);
int my_putstr(char *str);
int my_putnbr_base(int nb, char *base);
int my_putchar(char c);
void putchar_err(char c);
int str_compare(char *, char *);
int my_putnbr_base(int nb, char *base);
int my_putnbr_base_error(int nb, char *base);
int my_str_isnum(char *str);
int my_getnbr(char *str);
int my_str_is_alpha(char *str);
int my_str_is_alpha_num (char *str);

//gnl
int my_strlen(char *str);
char *my_strcat(char *dest, char *src);
char *copy_end(char *src, char *dest, int end);
char *bouclinf(char *s, char *save, int verif_second, int fd);
char *get_next_line(int fd);
char *my_strcpy(char *dest, char *src);

//my_str_to_word_array
int nb_space(char *str, char sep);
int actual(char *str, char sep);
char **my_str_to_tab(char *str, char sep);
char *delete_last_space(char *str);

//mysh.c
int my_sh(env_modif_t env_modif, char *comm, linked_t *tree);
env_modif_t my_sh_second(char *comm, env_modif_t env_modif);
char *maybe_tild(char *s, char *tild);
char **display_env(char **env);

//cd.c
char **previous_dir(char **env);
char **modif_env(char **env);
char **second_cd(char **tab, char **env);
char **func_cd(char **tab, char **env);

//function_exit
void function_exit(char **tab);
int setting_comm(char **comm, env_modif_t, linked_t *);

//setenv
char **my_setenv(char **tab, char **env);
char **my_unsetenv(char **tab, char **env);
int env_cd(char **env, char *prev, char *cwd);

//exec_prog
int exec_prog(char *comm, char **env);
int disp_error(int i);

//function echo
int function_echo(char **tab);

//useful
int length_diff(char *s1, char *s2);
char *copy_after_slash(char *str);
int same_str(char *s1, char *s2);
char **setting(char *prev, char *cwd);
int home_exist(char **env);

// alias && variables
int function_alias(char **, env_modif_t);
int function_variable(char **, env_modif_t);

//historique
char *restock(int);
char *cnc(char *, char *);
char *cn(char *);
int get_hist(char **);
int recreate_str(char *, char **);
void replace_chain(char *, char, int, int);
void replace_chain2(char *, int, int);
int destroy_chain(char *, int, int, char **);
int reset_chain(char *, int);
char *non_block_get(hist_t *n, env_modif_t, linked_t *);
char *reconcat_tab(char **);
char *al_var_check(char *, env_modif_t);
int my_fullcompare(char *, char *);
int my_fullcmp(char *, char *);
char *my_dbconcact(char *, char *, int, int);
char *clear_quote(char *);
#endif /* MINISHELL */
