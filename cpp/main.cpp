#include <iostream>
#include "./templates.cpp"

void checkPushFront(List<int>& list) 
{
    std::cout << "Check pushFront" << std::endl;
    list.pushFront(1);
    list.pushFront(2);
    list.pushFront(3);
    list.pushFront(4);
    list.pushFront(5);

    list.show();
}

void checkPushBack(List<int>& list) 
{
    std::cout << "Check pushBack" << std::endl;
    
    list.pushBack(34);
    list.pushBack(45);
    list.pushBack(67);
    list.pushBack(80);
    list.pushBack(90);

    list.show();
}

void checkSwap(List<int>& list) 
{
    std::cout << "Check swap" << std::endl;

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
}

void checkInsert(List<int>& list) 
{
    std::cout << "Check insert" << std::endl;

    list.insert(0, 128);
    list.insert(list.getCount(), 256);
    std::cout << list.peak(4) << std::endl;
    list.insert(5, 2048);

    list.show();
}

int main()
{
    List<int> list;

    checkPushFront(list);
    checkPushBack(list);

    checkSwap(list);

    list.show();

    checkInsert(list);

    list.popFront();
    list.show();

    std::cout << list.peak(4) << std::endl << std::endl;

    list.popBack();
    list.show();

    list.popBack();
    list.show();

    list.pushBack(25);
    list.show();
    
    list.remove(7);
    list.show();

    /*for(int i{}; i < 10; ++i)
    {
        list.pushBack(i);
    }

    list.show();

    checkInsert(list);

    std::cout << list.peak(4) << std::endl;
    std::cout << list.peak(5) << std::endl;

    list.remove(4);
    list.show();

    /*for(int i{}; i < 10; ++i)
    {
        list.pushBack(i);
    }

    list.show();

    checkSwap(list);

    for(int i{}; i < list.getCount(); ++i)
    {
        std::cout << list.peak(i) << " ";
    }

    checkInsert(list);

    std::cout << list.peak(4) << std::endl;
    std::cout << list.peak(5) << std::endl;

    list.remove(4);
    list.show();*/


    return 0;
}
