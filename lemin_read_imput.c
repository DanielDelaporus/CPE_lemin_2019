/*
** EPITECH PROJECT, 2019
** lemin.c
** File description:
** lemin
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/error.h"
#include "include/lemin.h"

char *new_cmd(char *str)
{
    int i;
    char *cmd = malloc(sizeof(char) * 400);

    for (i = 0; str[i] != '\n' && str[i] != '\t' && str[i] != ';'
    && str[i] != ' ' && str[i] != '\0'; i++) {
        cmd[i] = str[i];
    }
    cmd[i] = '\0';
    return cmd;
}

char **read_commands(char *buffer, int readsize)
{
    int i = 1;
    int point = 0;
    char **argv = malloc(sizeof(char *) * 4096);

    for (i = 0; i < readsize; i++) {
        if (buffer[i] != '\n' && buffer[i] != ' '
        && buffer[i] != '\t' && buffer[i] != ';') {
            argv[point] = new_cmd(&buffer[i]);
            point++;
            for (; buffer[i] != '\n' && buffer[i] != ' ' && buffer[i] != ';'
            && i < readsize && buffer[i] != '\t'; i++);
        }
    }
    argv[point] = NULL;
    return argv;
}

void print_node_t(node_tab *n)
{
    node_tab *tmp = n;
    while (tmp != NULL) {
        my_putstr("NODE:\n");
        my_putstr("Name: {");
        my_putstr(tmp->the_node->name);
        my_putstr("}\n");
        my_putstr("is_start: ");
        my_put_nbr(tmp->the_node->is_start);
        my_putstr("\n");
        my_putstr("is_end: ");
        my_put_nbr(tmp->the_node->is_end);
        my_putstr("\n");
        tmp = tmp->next;
    }
    my_putchar('\n');
}

int lemin_stand_imput(void)
{
    // index 0 : readvar; index1: is_beggin; index 2: is_end; index3: number of ants; index4: i;
    int integer_tab[5] = {4096, 0, 0, 0, 0};
    char *buffer = malloc(sizeof(char) * 8000);
    size_t size = 4096;
    node_tab *n = NULL;
    char **argv = NULL;
    int error = 0;

    for (integer_tab[4] = 0; integer_tab[0] > 0; integer_tab[4]++) {
        reset_buffer(buffer, integer_tab[0]);
        integer_tab[0] = getline(&buffer, &size, stdin);
        if (integer_tab[0] > 0) {
            argv = read_commands(buffer, integer_tab[0]);
            error = lemin_init(buffer, integer_tab, &n, argv);
            if (n != NULL)
                print_node_t(n);
        }
    }
    if (buffer != NULL)
        free(buffer);
    return error;
}

int lemin(int ac)
{
    if (ac == 1)
        return lemin_stand_imput();
    else
        return 84;
    return 0;
}