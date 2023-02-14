#pragma once

#include "../headers/ListItem.h"

typedef unsigned int uint;

template<class T>
class List
{
private:
    ListItem<T>* head;
    ListItem<T>* tail;
    uint count;

    void clearMemory();

    ListItem<T>* find(uint id);

public:

    List();

    List(const List<T>& obj);

    List(List<T>&& obj);

    List<T>& operator=(const List<T>& obj);

    List<T>& operator=(List<T>&& obj);

//operators overloading
    T& operator[](uint id);

    List<T>& operator+=(const List<T>& obj);

    bool operator==(const List<T>& obj);

    bool operator!=(const List<T>& obj);


// base
    int getCount() const;

    const T& peak(uint id); 

    const T& popFront(uint id);

    const T& popBack(uint id);

    const T& remove(uint id);

    void pushFront(const T& val);

    void pushBack(const T& val);

    void insert(uint id, const T& val);

    void show();

// additional
    void swap(uint id1, uint id2);

    void removeDuplicates();

    List<T> slice(uint startId, uint count);

    List<T>& reverse();

//
    ~List();

};