#include "../headers/List.h"

template<class T>
void List<T>::clearMemory()
{
    if (this->count == 0)
        {
            this->head = nullptr;
            this->tail = nullptr;
            return;
        }

        ListItem<T>* current = this->head;
        ListItem<T>* next;

        do
        {
            next = current->getNext();
            delete current;

            current = next;

        } while (current != nullptr);

        this->count = 0;
        this->head = nullptr;
        this->tail = nullptr;
}

template<class T>
ListItem<T>* List<T>::find(uint id)
{
    // TODO: check id => throw

    bool fromHead = id < this->count / 2;

    ListItem<T>* iterator = fromHead ? this->head : this->tail;
    int i = fromHead ? 0 : this->count - 1;
    int factor = fromHead ? 1 : -1;

    while (iterator != nullptr)
    {
        if (i == id)
            return iterator;

        iterator = fromHead ? iterator->getNext() : iterator->getPrev();
        i += factor;
    }
}

template<class T>
List<T>::List() :
    head{nullptr},
    tail{nullptr},
    count{0}
{}

template<class T>
List<T>::List(const List<T>& obj) :
    head{ nullptr },
    tail{ nullptr },
    count{ 0 }
{
    ListItem<T>* iterator = obj.head;

    while (iterator != nullptr)
    {
        this->pushBack(iterator->getVal());

        iterator = iterator->getNext();
    }
}

template<class T>
List<T>::List(List<T>&& obj) :
    head{ obj.head },
    tail{ obj.tail },
    count{ obj.count }
{
    obj.head = nullptr;
    obj.tail = nullptr;
    obj.count = 0;
}

template<class T>
List<T>& List<T>::operator=(const List<T>& obj)
{
    if (this!= &obj)
        return *this;
    
    if (this->head != nullptr || this->tail != nullptr || this->count > 0) 
        this->clearMemory();

    ListItem<T>* iterator = obj.head;

    while (iterator != nullptr)
    {
        this->pushBack(iterator->getVal());

        iterator = iterator->getNext();
    } 

    return *this;
}

template<class T>
List<T>& List<T>::operator=(List<T>&& obj)
{
    if (this!= &obj)
        return *this;

    if (this->head!= nullptr || this->tail!= nullptr || this->count > 0) 
        this->clearMemory();

    this->head = obj.head;
    this->tail = obj.tail;
    this->count = obj.count;

    obj.head = nullptr;
    obj.tail = nullptr;
    obj.count = 0;

    return *this;
}


// base
template<class T>
int List<T>::getCount() const
{
    return this->count;
}

template<class T>
const T& List<T>::peak(uint id) //do const?, then i need "const find()"
{
    return this->find(id)->getVal();
}

template<class T>
void List<T>::pushFront(const T& val)
{
    ListItem<T>* temp = new ListItem<T>{ val };

    temp->setPrev(nullptr);

    if (this->head != nullptr)
    {
        temp->setNext(this->head);
        temp->getNext()->setPrev(temp);
    } 
    else 
    {
        temp->setNext(nullptr);
        this->tail = temp;
    }

    this->head = temp;

    ++this->count;
}

template<class T>
void List<T>::pushBack(const T& val)
{
    ListItem<T>* temp = new ListItem<T>{ val };

    temp->setPrev(this->tail);

    if (this->head == nullptr)
    {
        this->head = temp;
        this->tail = this->head;
    }
    else
    {
        this->tail->setNext(temp);
        this->tail = this->tail->getNext();
    }

    ++this->count;
}

template<class T>
void List<T>::insert(uint id, const T& val)
{
    if (id == 0) pushFront(val);

    else if (id >= this->count) pushBack(val);

    else {
        ListItem<T>* temp = new ListItem<T>{ val };

        ListItem<T>* prev = this->find(id - 1);
        ListItem<T>* next = this->find(id);

        temp->setPrev(prev);
        temp->setNext(next);

        prev->setNext(temp);
        next->setPrev(temp);
    }
}

template<class T>
void List<T>::show()
{
    if (this->count == 0)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }

    ListItem<T>* iterator = this->head;

    while (iterator != nullptr)
    {
        std::cout << iterator->getVal() << " ";
        iterator = iterator->getNext();
    }

    std::cout << std::endl;
    std::cout << std::endl;
}


// additional
template<class T>
void List<T>::swap(uint id1, uint id2)
{
    if (id1 == id2)
        return;

    ListItem<T>* a = this->find(id1);
    ListItem<T>* b = this->find(id2);

    ListItem<T>* aPrev = a->getPrev();
    ListItem<T>* aNext = a->getNext();
    ListItem<T>* bPrev = b->getPrev();
    ListItem<T>* bNext = b->getNext();

    bool isNear = a->getNext() == b;

    bool isHead = a == this->head;
    bool isTail = b == this->tail;

    if (isHead) {
        this->head = b;
    } else {
        aPrev->setNext(b);
    }

    if (isTail) {
        this->tail = a;
    } else {
        bNext->setPrev(a);
    }

    if (isNear)
    {
        a->setPrev(b);
        b->setNext(a);
        b->setPrev(aPrev);
        a->setNext(bNext);
    } 
    else 
    {
        a->setPrev(bPrev);
        a->setNext(bNext);
        bPrev->setNext(a);

        b->setPrev(aPrev); 
        b->setNext(aNext); 
        aNext->setPrev(b);
    }
}


//
template<class T>
List<T>::~List()
{
    if (head != nullptr && tail!= nullptr)
        this->clearMemory();
}