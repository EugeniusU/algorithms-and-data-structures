#include <stdio.h>
#include <stdlib.h>

struct Map {
    char key;
    int value;
    struct Map *link;
};

int getValue(struct Map *map, char key);
struct Map *apply(struct Map *map, char key, int value);

main() {
    struct Map *map = (struct Map*)malloc(sizeof(struct Map));
    map->link = 0;

    map = apply(map, "key1", 1);
    map = apply(map, "key2", 2);

    printf("%d\n", getValue(map, "key1"));    // 1
    printf("%d\n", getValue(map, "key2"));    // 2

    int v = getValue(map, "key1");            // 1
    map = apply(map, "key1", 10);
    map = apply(map, "key1New", v);

    printf("%d\n", getValue(map, "key1"));    // 10
    printf("%d\n", getValue(map, "key1New")); // 1

}

struct Map *apply(struct Map *map, char key, int value) {
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
        map2->value = value;
        map2->link = map;

        return map2;
    } else {
        i->value = value;
      
        return map;
    }
}

int getValue(struct Map *map, char key) {
    struct Map *i = (struct Map*)malloc(sizeof(struct Map));
    int value = -1;

    for (i = map; i->link != 0; i = i->link) {
        if (i->key == key) {
            value = i->value;
            break;
        }
    }

    return value;
}
