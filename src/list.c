#include "list.h"

#include "stdio.h"
#include "stdlib.h"

node* init(void* data) {
    node* new = (node*)malloc(sizeof(node));
    new->content = data;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void add(list* lst, void* data) {
    node* new = init(data);
    if (lst->head == NULL) {  // init
        lst->head = new;
        lst->tail = lst->head;
    } else {  // push back
        new->prev = lst->tail;
        lst->tail->next = new;
        lst->tail = new;
    }
    lst->length++;
}

void list_print(list* lst, void (*prnt)(void*)) {
    node* cur = lst->head;
    while (cur != NULL) {
        (*prnt)(cur->content);
        printf("\n");
        cur = cur->next;
    }
}

list* list_init() {
    list* lst = (list*)malloc(sizeof(list));
    lst->head = NULL;
    lst->tail = NULL;
    lst->length = 0;
    return lst;
}

void destroy(list* lst) {
    if (lst) {
        int flag = 1;
        while (flag) {
            if (lst->head != lst->tail)
                delete (lst, lst->length - 1);
            else
                flag = 0;

            if (lst->head != lst->tail)
                delete (lst, 0);
            else
                flag = 0;
        }
        free(lst->head);
        free(lst);
    }
}

void* get(list* lst, int index) {  // [] operator
    if (index < 0 || index >= lst->length) return NULL;

    if (index == 0) return lst->head;  // first element

    if (index == lst->length - 1) return lst->tail;  // last element

    node* cur;
    int i;
    if (index > lst->length / 2) {  // index after the middle
        cur = lst->tail;
        i = lst->length - 1;
        while (i != index) {
            cur = cur->prev;
            i--;
        }
    } else {  // index before the middle
        cur = lst->head;
        i = 0;
        while (i != index) {
            cur = cur->next;
            i++;
        }
    }
    return cur->content;
}

void delete (list* lst, int index) {
    if (!lst) return;

    if (index < 0 || index >= lst->length) return;

    if (index == 0) {  // head case
        node* temp_head = lst->head;
        lst->head = temp_head->next;
        free(temp_head);
        lst->length--;
        return;
    }
    if (index == lst->length - 1) {  // tail case
        node* temp_tail = lst->tail;
        lst->tail = temp_tail->prev;
        lst->tail->next = NULL;
        free(temp_tail);
        lst->length--;
        return;
    }
    node* cur;
    int i;
    if (index > lst->length / 2) {  // index after the middle
        cur = lst->tail;
        i = lst->length - 1;
        while (i != index) {
            cur = cur->next;
            i--;
        }
    } else {  // index before the middle
        cur = lst->head;
        i = 0;
        while (i != index) {
            cur = cur->next;
            i++;
        }
    }
    cur->next->prev = cur->prev;
    cur->prev->next = cur->next;
    free(cur);
    lst->length--;
}

void insert(list* lst, void* data, int index) {
    if (!lst) return;

    if (index < 0 || index >= lst->length) return;

    if (index == 0) {  // replace head
        node* new = init(data);
        new->next = lst->head;
        lst->head->prev = new;
        lst->head = new;
        lst->length++;
        return;
    }
    if (index == lst->length - 1) {  // replace tail
        add(lst, data);
        lst->length++;
        return;
    }
    node* cur;
    int i;
    if (index > lst->length / 2) {  // index after the middle
        cur = lst->tail;
        i = lst->length - 1;
        while (i != index) {
            cur = cur->next;
            i--;
        }
    } else {  // index before the middle
        cur = lst->head;
        i = 0;
        while (i != index) {
            cur = cur->next;
            i++;
        }
    }
    node* new = init(data);
    new->next = cur;
    new->prev = cur->prev;
    cur->prev->next = new;
    cur->prev = new;
    lst->length++;
}