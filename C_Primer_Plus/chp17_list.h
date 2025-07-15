#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

#define SIZE 45

typedef struct {
    char name[SIZE];
} Item;

typedef struct node {
    Item item;
    struct node *next;
} Node;

typedef Node *List;

void init_list(List *list);

bool list_is_empty(const List *list);

bool list_is_full(const List *list);

unsigned int list_item_count(const List *list);

bool add_item(Item item, List *list);

void traverse(const List *list, void (*fn) (Item item));

void empty_list(List *list);

#endif

