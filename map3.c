#include <stdio.h>
#include <stdlib.h>

struct Map {
    char key;
    void *value;
    struct Map *link;
};

void *getValue(struct Map *map, char key);
struct Map *apply(struct Map *map, char key, void *value, size_t value_size);

main() {
    struct Map *map = (struct Map*)malloc(sizeof(struct Map));
    map->link = 0;

    int one = 1;
    int two = 2;
    void *p1 = &one;
    size_t size1 = sizeof(one);
    void *p2 = &two;
    size_t size2 = sizeof(two);
    map = apply(map, "key1", p1, size1);
    map = apply(map, "key2", p2, size2);
    printf("%d\n", *((int*)(getValue(map, "key1"))));
    printf("%d\n", *((int*)(getValue(map, "key2"))));

    float three = 3.5;
    float four = 4.105;
    void *p3 = &three;
    size_t size3 = sizeof(three);
    void *p4 = &four;
    size_t size4 = sizeof(four);
    map = apply(map, "key3", p3, size3);
    map = apply(map, "key4", p4, size4);
    printf("%f\n", *((float*)(getValue(map, "key3"))));
    printf("%f\n", *((float*)(getValue(map, "key4"))));

    char *five = "five";
    char *six = "six";
    void *p5 = five;
    size_t size5 = sizeof(five);
    void *p6 = six;
    size_t size6 = sizeof(six);
    map = apply(map, "key5", p5, size5);
    map = apply(map, "key6", p6, size6);
    printf("%s\n", (char*)(getValue(map, "key5")));
    printf("%s\n", (char*)(getValue(map, "key6")));
}

struct Map *apply(struct Map *map, char key, void *value, size_t value_size) {
    struct Map *map2 = (struct Map*)malloc(sizeof(struct Map));
    struct Map *i = (struct Map*)malloc(sizeof(struct Map));

    int find = -1;
    int j = 0;

    for (i = map; i->link != 0; i = i->link) {
        if (i->key == key) {
            find = j;
            break;
        }
        j++;
    }

    if (find < 0) {
        map2->key = key;
        map2->value = malloc(value_size);

        for (int j = 0; j < value_size; j++) {
            *(char*)(map2->value + j) = *(char*)(value + j);
        }

        map2->link = map;

        return map2;
    } else {
        for (int j = 0; j < value_size; j++) {
            *(char*)(i->value + j) = *(char*)(value + j);
        }

        return map;
    }

}

void *getValue(struct Map *map, char key) {
    struct Map *i = (struct Map*)malloc(sizeof(struct Map));
    void *value = 0;

    for (i = map; i->link != 0; i = i->link) {
        if (i->key == key) {
            value = i->value;
            break;
        }
    }

    return value;
}
