/*
** EPITECH PROJECT, 2019
** my_cat_text.c
** File description:
** cat texts
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "include/my.h"

int lemin_stand_imput(int fd);
void reset_buffer(char *buffer, int size);

void my_putchar_error(char a)
{
    write(2, &a, 1);
}

int my_putstr_error(char const *str)
{
    for (int i = 0;  str[i] != '\0'; i++) {
        my_putchar_error(str[i]);
    }
    return (0);
}

int my_error_handle(char *command, char *not_found, int error)
{
    my_putstr_error("mysh: ");
    if (command[0] == '\0') {
        my_putstr_error(command);
        my_putstr_error(": ");
    }
    my_putstr_error(not_found);
    my_putstr_error(": ");
    if (error == -1)
        my_putstr_error("too many arguments");
    else
        my_putstr_error("Error");
    my_putchar('\n');
    return 84;
}
