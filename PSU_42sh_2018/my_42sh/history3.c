/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** history3.c
*/

#include "../headers/minishell1.h"

void last_arrows(hist_t *h)
{
    if (h->tmp == 'A' && h->pos > 0) {
        h->pos--;
        h->nb = destroy_chain(h->stock, h->nb, h->pos, h->hist);
    } else if (h->tmp == 'B') {
        if (h->hist[h->pos + 1] != NULL) {
            h->pos++;
            h->nb = destroy_chain(h->stock, h->nb, h->pos, h->hist);
        } else {
            h->pos = get_hist(h->hist);
            h->nb = reset_chain(h->stock, h->nb);
        }
    }
    if (h->tmp == 'C' && h->stock[h->nb] != '\0') {
        printf("%c", h->stock[h->nb]);
        h->nb++;
    } else if (h->tmp == 'D' && h->nb > 0) {
        printf("\b");
        h->nb--;
    }
}

void check_arrow(hist_t *h)
{
    if (h->tmp == '\033') {
        getchar();
        h->tmp = getchar();
        last_arrows(h);
    }
}

void main_hist(hist_t *h)
{
    while (1) {
        h->tmp = getchar();
        for (h->size = 0; h->stock[h->size] != '\0'; h->size++);
        if (h->tmp == '\n') {
            h->tmp = -1;
            h->nb = recreate_str(h->stock, h->hist);
            h->pos = get_hist(h->hist);
            break;
        }
        if (h->tmp != -1 && h->tmp != 127 && h->tmp != 9 && h->tmp != '\033') {
            replace_chain(h->stock, h->tmp, h->nb, h->size);
            h->nb++;
        } else if (h->tmp == 127 && h->nb > 0) {
            replace_chain2(h->stock, h->nb, h->size);
            h->nb--;
        } else
            check_arrow(h);
    }
}

char *non_block_get(hist_t *h, env_modif_t env, linked_t *tree)
{
    struct termios oldt, newt;
    int oldf;

    for (int i = 0; i < 1000; i++)
        h->stock[i] = '\0';
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    main_hist(h);
    printf("\n");
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if (h->stock[0] == '\0')
        my_sh(env, NULL, tree);
    else
        return (h->stock);
    return (NULL);
}