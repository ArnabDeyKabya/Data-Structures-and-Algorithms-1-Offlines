#include <iostream>
using namespace std;
template <typename T>
class node
{
public:
    T data;
    node *next;
    node()
    {
        next = NULL;
    }
    node(T data, node *link)
    {
        this->data = data;
        next = link;
    }
};

template <typename T>
class LinkedList
{
    node<T> *head;
    node<T> *tail;
    node<T> *current;
    int listSize;

public:
    LinkedList()
    {
        head = new node<T>();
        current = head;
        tail = head;
        listSize = 0;
    }
    LinkedList(T ara[], int sz, int X)
    {
        listSize = 0;
        head = new node<T>();
        current = head;
        tail = head;
        for (int i = 0; i < sz; i++)
            pushBack(ara[i]);
    }
    int size()
    {
        return listSize;
    }
    void push(T a)
    {
        node<T> *temp = new node<T>(a, current->next);
        current->next = temp;
        listSize++;
    }
    void pushBack(T data)
    {
        node<T> *temp = new node<T>(data, NULL);
        tail->next = temp;
        tail = temp;
        listSize++;
    }
    T erase()
    {
        node<T> *temp = current->next;
        T value = temp->data;
        current->next = current->next->next;
        delete temp;
        listSize--;
        return value;
    }
    void setToBegin()
    {
        current = head;
    }
    void setToEnd()
    {
        current = head;
        while (current->next != tail)
            current = current->next;
    }
    void prev()
    {
        if (current != head)
        {
            node<T> *temp = head;
            while (temp->next != current)
                temp = temp->next;
            current = temp;
        }
    }
    void next()
    {
        current = current->next;
    }
    int currPos()
    {
        node<T> *temp = head;
        int i;
        for (i = 0; temp != current; i++)
            temp = temp->next;
        return i;
    }
    void setToPos(int pos)
    {
        current = head;
        for (int i = 0; i < pos; i++)
            current = current->next;
    }
    T getValue()
    {
        return current->next->data;
    }
    T find(T value)
    {
        int ret = -1;
        node<T> *temp = head;
        for (int i = 0; i < listSize; i++)
        {
            if (temp->next->data == value)
                return i;
            temp = temp->next;
        }
        return ret;
    }
    void clear()
    {
        while (head != NULL)
        {
            current = head;
            head = head->next;
            delete current;
        }
        current = tail = head = new node<T>();
        listSize = 0;
    }
};
