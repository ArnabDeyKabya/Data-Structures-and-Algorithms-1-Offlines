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
class MyList
{
    node<T> *head;
    node<T> *tail;
    node<T> *current;
    int listSize;

public:
    MyList()
    {
        head = new node<T>();
        current = head;
        tail = head;
        listSize = 0;
    }
    MyList(T ara[], int sz = 0, int X = 0)
    {
        listSize = 1;
        head = new node<T>();
        current = head;
        tail = head;
        head->data = ara[0];
        for (int i = 1; i < sz; i++)
            pushBack(ara[i]);
    }
    void setMyList(T ara[], int sz = 0, int X = 0)
    {
        listSize = 1;
        head = new node<T>();
        current = head;
        tail = head;
        head->data = ara[0];
        for (int i = 1; i < sz; i++)
            pushBack(ara[i]);
    }
    int size()
    {
        return listSize;
    }
    void push(T a)
    {
        if (listSize == 0)
        {
            listSize = 1;
            head = new node<T>();
            head->data = a;
            head->next = NULL;
            current = head;
            tail = head;
        }
        else if (current == head)
        {
            node<T> *temp = new node<T>(a, current);
            current = temp;
            head = current;
            listSize++;
        }
        else
        {
            node<T> *pre;
            for (pre = head; pre->next != current; pre = pre->next)
                ;
            node<T> *temp = new node<T>(a, current);
            pre->next = temp;
            listSize++;
            current = temp;
        }
    }
    void pushBack(T data)
    {
        if (listSize == 0)
        {
            listSize = 1;
            head = new node<T>();
            head->data = data;
            head->next = NULL;
            current = head;
            tail = head;
        }
        else
        {
            node<T> *temp = new node<T>(data, NULL);
            tail->next = temp;
            tail = temp;
            listSize++;
        }
    }
    T erase()
    {
        T item;
        if (current != NULL)
        {
            item = current->data;
            listSize--;
        }
        node<T> *temp;
        if (current == head)
        {
            current = current->next;
            delete head;
            head = current;
        }
        else if (current == tail)
        {
            temp = current;
            node<T> *pre;
            for (pre = head; pre->next != current; pre = pre->next)
                ;
            pre->next = NULL;
            current = pre;
            tail = current;
            delete temp;
        }
        else
        {
            temp = current;
            node<T> *pre;
            for (pre = head; pre->next != current; pre = pre->next)
                ;
            pre->next = current->next;
            delete temp;
            current = pre->next;
        }
        return item;
    }
    void setToBegin()
    {
        current = head;
    }
    void setToEnd()
    {
        if (listSize == 1)
        {
            current = head;
        }
        else
        {
            current = head;
            while (current->next != tail)
                current = current->next;
            current = current->next;
        }
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
        if (current != tail)
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
        return current->data;
    }
    T find(T value)
    {
        int ret = -1;
        node<T> *temp = head;
        for (int i = 0; i < listSize; i++)
        {
            if (temp->data == value)
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
    void print(MyList<T> array)
    {
        int position = array.currPos();
        array.setToBegin();
        cout << "<";
        while (array.currPos() < array.size())
        {
            if (array.currPos() == position)
                cout << "| ";
            cout << array.getValue() << " ";
            if (array.currPos() == array.size() - 1)
                break;
            array.next();
        }
        cout << ">" << endl;
        array.setToPos(position);
    }
};