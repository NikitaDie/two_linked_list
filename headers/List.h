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

//operators overloading
    List<T>& operator=(const List<T>& obj);

    List<T>& operator=(List<T>&& obj);

    ListItem<T>& operator[](uint id);

    List<T>& operator+=(const List<T>& obj);

    bool operator==(const List<T>& obj);

    bool operator!=(const List<T>& obj);


// base
    int getCount() const;

    T peak(uint id); 

    T popFront();

    T popBack();

    T remove(uint id);

    void pushFront(const T& val);

    void pushBack(const T& val);

    void insert(uint id, const T& val);

    void show() const;

// additional
    void swap(uint id1, uint id2);

    List<T> slice(uint startId, uint endId);

    List<T>& reverse();

//
    ~List();

};