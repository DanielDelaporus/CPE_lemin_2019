/*
** EPITECH PROJECT, 2019
** lemin.c
** File description:
** lemin
*/

typedef struct node {
    char *name;
    int is_start; // is_end_beggin: -1 pour début, 1 si fin et 0 sinon
    int is_end;
    int nb_ants; // si nb_ants > 0 : Chemin bloqué pour les autres
    int is_close;
    struct struct_path *path;
} node;

typedef struct struct_path {
    node *node;
    int distance;
    struct struct_path *next;
} struct_path;

typedef struct node_tab {
    node *the_node;
    struct node_tab *next;
} node_tab;

void reset_buffer(char *buffer, int size);
int lemin_init(char *buffer, int *integer_tab, node_tab **n, char **tab);