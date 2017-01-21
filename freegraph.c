#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "freegraph.h"



struct List{
    struct N *p;
    struct List *next;
};



struct List *mkList(struct N *ptr, struct List *nx)
{
    struct List *list = malloc(sizeof(struct List));

    list -> p = ptr;
    list -> next = nx;

    return list;
}

bool exists(struct N *ap, struct List *list)
{

    while(list)
    {
        if(list->p == ap) return true;
        list = list -> next;
    }

    return false;
}

struct List *buildList(struct N *ap, struct List *list)
{
    if(ap)
    {
        if(!exists(ap, list)) {
            list = mkList(ap, list);
            list = (buildList(ap->x, list));
            list = (buildList((ap->y), list));
            list = buildList(ap->z, list);
        }


    }
    return list;
}


long sum(struct N *ap)
{
    long count = 0;
    struct List *list;
    list = mkList(NULL, NULL);
    list =  buildList(ap, list);

    struct List *temporary = NULL;

    while(list)
    {
        if(list->p)
            count += list->p->data;

        temporary = list->next;
        free(list);
        list = temporary;
    }

    return count;
}

void deallocate(struct N *ap)
{
    struct List *list;
    list = mkList(NULL, NULL);
    list=  buildList(ap, list);

    struct List *temporary = NULL;
    while(list)
    {
        temporary = list->next;
        free(list->p);
        free(list);
        list = temporary;
    }
}


