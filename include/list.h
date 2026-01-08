#ifndef TITLED_LIST_H
#define TITLED_LIST_H
#include "stdlib.h"

typedef struct Node {
    struct Node* prev;
    struct Node* next;
    void* content;
} node;

typedef struct List {
    node* head;
    node* tail;
    int length;
} list;

list* list_init();
void add(list *lst, void* data);
void list_print(list *lst, void (*prnt) (void*));
void insert(list *lst, void* data, int index);
void* get(list *lst, int index);
void delete(list *lst, int index);
void destroy(list *lst);

#endif