#include "../headers/ListItem.h"

template<class T>
ListItem<T>::ListItem() :
    val{},
    next{ nullptr },
    prev{ nullptr }
{}

template<class T>
ListItem<T>::ListItem(const T& val) :
    val{ val },
    next{ nullptr },
    prev{ nullptr }
{}

template<class T>
ListItem<T>::ListItem(const ListItem& obj) :
    val{ obj.val },
    next{ nullptr },
    prev{ nullptr }
{}

template<class T>
T ListItem<T>::getVal() const 
{
    return this->val;
}

template<class T>
void ListItem<T>::setVal(const T& val)
{
    this->val = val;
}

/*template<class T>
ListItem<T>& ListItem<T>::operator=(const T& val)*/ //add in future

template<class T>
ListItem<T>* ListItem<T>::getPrev() const
{
    return this->prev;
}

template<class T>
void ListItem<T>::setPrev(ListItem<T>* ptr)
{
    this->prev = ptr;
}

template<class T>
ListItem<T>* ListItem<T>::getNext() const
{
    return this->next;
}

template<class T>
void ListItem<T>::setNext(ListItem<T>* ptr)
{
    this->next = ptr;
}

template<class T>
ListItem<T>::~ListItem() 
{
    this->next = nullptr;
    this->prev = nullptr;
}