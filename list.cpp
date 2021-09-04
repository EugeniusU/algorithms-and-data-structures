#include <iostream>

template <typename T>

class Vector {
public:
    T x, y;
    Vector(T x, T y) {
        this->x = x;
        this->y = y;
    }
};

template <typename U>

class List {
public:
    U* now;
    List* prev;
    int sized = 0;

    List(U* obj) {
        now = obj;
//        prev = NULL;
        prev = 0;
        sized++;
    }

    List* apply(U* obj) {
        auto li = new List(obj);

        li->now = now;
        li->prev = prev;
        li->sized = sized;

        now = obj;
        prev = li;

        sized++;

        return this;
    }

    U* getLast() {
        return this->now;
    }

    void iterate() {
        for (List* i = this; i != 0; i = i->prev) {
            std::cout << i->now->x << " " << i->now->y << std::endl;
            std::cout << "size" << " " << i->sized << std::endl;
        }
    }
};

int main() {
    auto v = new Vector<std::string>("abc", "ff");
    std::cout << v->x << " " << v->y <<std::endl;


    auto obj = new Vector<float>(1.1, 2.2);
    auto li = new List<Vector<float>>(obj);

    for (int i = 0; i < 10; i++) {
        float x = i + 0.1;
        float y = x * x;
        auto obj2 = new Vector<float>(x, y);
        li->apply(obj2);
    }

    li->iterate();

    return 0;
}

