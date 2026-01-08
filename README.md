# Generic List in C

This was my practice with pointers and also a library for my project.
It is a little bit unsafe because of the ability to put any datatype in one list, but it also can be usefull 

## Build

Run:
```bash
mkdir build && cd build
cmake .. && make
```

The static library will be located in the `build` folder

## Install

Run
```bash
sudo make install
```

Then You can use 
```C
#include <list.h>
```

## Functions list
- `list* list_init();` - create an empty list
- `void add(list *lst, void* data);` - add an element 
- `void list_print(list *lst, void (*prnt) (void*));` - print all elements by given function
- `void insert(list *lst, void* data, int index);` - insert an element on the specific index
- `void* get(list *lst, int index);` - operator []
- `void delete(list *lst, int index);` - remove the element by index
- `void destroy(list *lst);` - free memory

## Example Usage

```C
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
```