#include <iostream>
#include "./templates.cpp"


int main()
{
    List<int> list;
    
    list.pushFront(1);
    list.pushFront(2);
    list.pushFront(3);
    list.pushFront(4);
    list.pushFront(5);

    list.show();

    list.pushBack(34);
    list.pushBack(45);
    list.pushBack(67);
    list.pushBack(80);
    list.pushBack(90);

    list.show();

    list.swap(1, 2);
    list.show();

    list.swap(1, 3);
    list.show();

    list.swap(0, 1);
    list.show();

    list.swap(list.getCount() - 2, list.getCount() - 1);
    list.show();

    list.swap(0, 2);
    list.show();

    list.swap(1, list.getCount() - 1);
    list.show();

    list.swap(0, list.getCount() - 1);
    list.show();

    return 0;
}
