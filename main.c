#include <stdlib.h>
#include <list.h>
#include <stdio.h>

typedef struct pnt_struct
{
    double x, y;
} pnt;

void pnt_print(void* this) {
    printf("(%.3lf, %.3lf)", ((pnt*)this)->x, ((pnt*)this)->y);
}

int pnt_input(pnt* this) {
    int flag = 1;
    if (scanf("%lf %lf", &this->x, &this->y) != 2) flag = 0;
    return flag;
}

int main() {

    // creating from an array
    pnt a[2];
    list* lst = list_init();
    for (int i = 0; i < 2; ++i)
        if (pnt_input(&a[i])) 
            add(lst, &a[i]);

    // print
    list_print(lst, pnt_print);
    printf("\n");

    // add
    pnt p = {1, 2};
    add(lst, &p);
    list_print(lst, pnt_print);
    printf("\n");
    
    // remove
    delete(lst, 2);
    list_print(lst, pnt_print);
    printf("\n");
    
    // insert
    pnt p1 = {1, 2};
    insert(lst, &p1, 0);
    list_print(lst, pnt_print);
    printf("\n");

    // []
    pnt p2 = *(pnt*)get(lst, 1);
    pnt_print(&p2);
    printf("\n");

    // free memory
    destroy(lst);
    return 0;
}