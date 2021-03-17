/*
** EPITECH PROJECT, 2019
** my_cat_text.c
** File description:
** cat texts
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "include/my.h"
#include "include/lemin.h"

node **dijsktra(/*Struct for all the graph,*/ node start, node end)
{
    int total = 1; //Supposed to be the total of node but I don't see it in any struct
    int dist[total] = {__INT32_MAX__}; //A tab of the size of the nb of node
    int p[total] = {-1};
    dist[/*the start*/] = 0;
    heap h = make_heap(total);
    push(h, start);
    while (!isempty(h)) {
        x = pop(h);
        if (x == end)
            return;
        for (int y = 0; /*Every node adj to x*/; y++) {
            if (dist[x] /*+ distance beetween x and y*/ < dist[y]) {
                dist[y] = dist[x] /*+ distance beetween x and y*/;
                p[y] = x;
                
            }
        } 
    }
    return;
}