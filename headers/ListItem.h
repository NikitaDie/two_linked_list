#pragma once

template<class T>
class ListItem
{
private:
    T val;
    ListItem<T>* next;
    ListItem<T>* prev;

public:
    ListItem();

    ListItem(const T& val);

    ListItem(const ListItem<T>& obj);
    
    T getVal() const;

    void setVal(const T& val);

    ListItem<T>* getPrev() const;

    void setPrev(ListItem<T>* ptr);

    ListItem<T>* getNext() const;

    void setNext(ListItem<T>* ptr);

    ~ListItem();
};