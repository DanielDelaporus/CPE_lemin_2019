/*
** EPITECH PROJECT, 2019
** lemin.c
** File description:
** lemin
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/lemin.h"
#include "include/my.h"

int lemin_init_nb_word(char *buffer)
{
    int j = 0;
    for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++) {
        if (buffer[i] == ' ')
            j++;
    }
    return j + 1;
}

node *lemin_init_two(char **tab, int *integer_tab)
{
    node *n = malloc(sizeof(node));
    n->is_start = 0;
    n->is_end = 0;
    n->nb_ants = 0;
    if (integer_tab[1] != 0) {
        n->is_start = 1;
        n->nb_ants = integer_tab[3];
        integer_tab[1] = 0;
    }
    if (integer_tab[2] != 0) {
        n->is_end = 1;
        integer_tab[2] = 0;
    }
    n->is_close = 0;
    n->name = my_strdup(tab[0]);
    n->path = NULL;
    return n;
}

int lemin_init(char *buffer, int *integer_tab, node_tab **n, char **tab)
{
    node_tab *tmp = NULL;
    int nb_words = lemin_init_nb_word(buffer);
    if (nb_words <= 0)
        return 84;
    if (integer_tab[4] == 0 && nb_words == 1) {
        integer_tab[3] = my_getnbr(buffer);
        return 0;
    }
    if (!(my_strcmp("##start", tab[0]))) {
        integer_tab[1] = 1;
        return 0;
    }
    if (!(my_strcmp("##end", tab[0]))) {
        integer_tab[2] = 1;
        return 0;
    }
    if (nb_words == 3) {
        if (*n == NULL) {
            (*n) = malloc(sizeof(node_tab));
            tmp = *n;
            tmp->the_node = lemin_init_two(tab, integer_tab);
            tmp->next = NULL;
        } else {
            tmp = *n;
            while (tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = malloc(sizeof(node_tab));
            tmp->next->the_node = lemin_init_two(tab, integer_tab);
            tmp->next->next = NULL;
        }
        return 0;
    }
    return 84;
}