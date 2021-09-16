#include <stdio.h>
#include <stdlib.h>

struct List {
    int value;
    struct List *link;
};

struct List *apply(struct List *list, int value);
void getAll(struct List* list);

main() {
    struct List *list = (struct List*)malloc(sizeof(struct List));
    list->link = 0;
  
    for (int i = 0; i < 10; i++) {
        list = apply(list, i);
    }
  
    getAll(list);
}

struct List *apply(struct List* list, int value) {
    struct List *list2 = (struct List*)malloc(sizeof(struct List));

    list2->value = value;
    list2->link = list;

    return list2;
}

void getAll(struct List* list) {
    struct List *i = (struct List*)malloc(sizeof(struct List));
    i = list;

    for (i; i->link != 0; i = i->link) {
        printf("value %d\n", i->value);
    }
}
