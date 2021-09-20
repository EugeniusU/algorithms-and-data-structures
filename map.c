#include <stdio.h>
#include <stdlib.h>

struct Map {
    int index;
    char *keys;
    int *data;
};

void apply(struct Map *map, char key, int value);
int getValue(struct Map *map, char key);

main() {
    struct Map *map = (struct Map*)malloc(sizeof(struct Map));

    map->index = 0;
    map->keys = (char*)malloc(sizeof(char));
    map->data = (int*)malloc(sizeof(int));

    apply(map, "key1", 1);
    apply(map, "key2", 2);

    printf("%d\n", getValue(map, "key1"));    // 1
    printf("%d\n", getValue(map, "key2"));    // 2

    int v = getValue(map, "key1");            // 1
    apply(map, "key1", 10);
    apply(map, "key1New", v);

    printf("%d\n", getValue(map, "key1"));    // 10
    printf("%d\n", getValue(map, "key1New")); // 1
}

void apply(struct Map *map, char key, int value) {
    int index = map->index;
    int find = -1;

    for (int i = 0; i < index; i++) {
        if (map->keys[i] == key) {
            find = i;
            break;
        }
    }

    if (find < 0) {
        map->keys[index] = key;
        map->data[index] = value;
        map->index++;
    } else {
        map->data[find] = value;
    }
}

int getValue(struct Map *map, char key) {
    int index = map->index;
    int value = -1;

    for (int i = 0; i < index; i++) {
        if (map->keys[i] == key) {
            value = map->data[i];
            break;
        }
    }

    return value;
}
