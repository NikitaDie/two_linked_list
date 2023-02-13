#include <iostream>

typedef unsigned int uint;

template<class T>
class ListItem
{
private:
    T val;
    ListItem<T>* next;
    ListItem<T>* prev;

public:
    ListItem() :
        val{},
        next{ nullptr },
        prev{ nullptr }
    {}

    ListItem(const T& val) :
        val{ val },
        next{ nullptr },
        prev{ nullptr }
    {}

    ListItem(const ListItem<T>& obj) :
        val{ obj.val },
        next{ nullptr },
        prev{ nullptr }
    {}

    T getVal() const
    {
        return this->val;
    }

    void setVal(const T& val)
    {
        this->val = val;
    }

    ListItem<T>* getPrev() const
    {
        return this->prev;
    }

    void setPrev(ListItem<T>* ptr)
    {
        this->prev = ptr;
    }

    ListItem<T>* getNext() const
    {
        return this->next;
    }

    void setNext(ListItem<T>* ptr)
    {
        this->next = ptr;
    }
};


template<class T>
class List
{
private:
    ListItem<T>* head;
    ListItem<T>* tail;
    uint count;

    void clearMemory()
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
    ListItem<T>* find(uint id)
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


public:
    List():
        head{nullptr},
        tail{nullptr},
        count{0}
    {}

    List(const List<T>& obj) :
        head{ nullptr },
        tail{ nullptr },
        count{ 0 }
    {
        ListItem<T>* iterator = obj.head;

        while (iterator != nullptr)
        {
            this->pushToTail(iterator->getVal());

            iterator = iterator->getNext();
        }
    }





    //List(List<T>&& obj);

    //List<T>& operator=(const List<T>& obj);
    //List<T>& operator=(List<T>&& obj);
    //T& operator[](uint id);
    //List<T> operator+(const List<T>& obj);
    //// == != 

    int getCount() {
        return this->count;
    }

    //const T& peak(uint id);
    const T& pop(uint id);

    void show()
    {
        if (this->count == 0)
        {
            std::cout << "List is empty";
            return;
        }

        ListItem<T>* iterator = this->head;

        while (iterator != nullptr)
        {
            std::cout << iterator->getVal() << ' ';
            iterator = iterator->getNext();
        }

        std::cout << "\n\n";
    }

    //void pushToHead(const T& val);

    void pushToTail(const T& val)
    {
        ListItem<T>* temp = new ListItem<T>{ val };

        temp->setPrev(this->tail);
        
        if (this->tail != nullptr)
            this->tail->setNext(temp);
        else
            this->head = temp;            
        
        this->tail = temp;

        ++this->count;
    }



   /* void insertBefore(uint id, const T& val);
    void insertAfter(uint id, const T& val);
    void remove(uint id);
    void removeDuplicates();
    List<T> slice(uint startId, uint count);
    void reverse();*/

    void swap(uint id1, uint id2)
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

        if(isNear){

            a->setPrev(b);
            b->setNext(a);
            b->setPrev(aPrev);
            a->setNext(bNext);

        } else {

            a->setPrev(bPrev);
            a->setNext(bNext);
            bPrev->setNext(a);

            b->setPrev(aPrev); 
            b->setNext(aNext); 
            aNext->setPrev(b);
        }

        

        /*ListItem<T>* a = this->find(id1);
        ListItem<T>* b = this->find(id2);

        ListItem<T>* prev = a->getPrev();
        ListItem<T>* next = a->getNext();

        a->setPrev(b->getPrev());
        a->setNext(b->getNext());

        b->setPrev(prev);
        b->setNext(next);

        a->getPrev()->setNext(a);
        a->getNext()->setPrev(a);
        b->getPrev()->setNext(b);
        b->getNext()->setPrev(b);*/
    }

    ~List()
    {
        this->clearMemory();
    }
};




int main()
{
    List<int> list;
    list.pushToTail(34);
    list.pushToTail(45);
    list.pushToTail(67);
    list.pushToTail(80);
    list.pushToTail(90);

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

    /*list.swap(1, 2);
    list.show();*/

    return 0;
}
