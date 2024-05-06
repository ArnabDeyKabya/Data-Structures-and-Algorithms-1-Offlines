#include <iostream>
using namespace std;
template <typename T>
class ArrayList
{
    int length;
    int capacity;
    int current;
    T *list;
    // expand the capacity when the Arraylist is full of inserting new element.
    void expandCapacity()
    {
        T *temp = new T[capacity];
        for (int i = 0; i < length; i++)
            temp[i] = list[i];
        capacity = capacity * 2;
        delete[] list;
        list = new T[capacity];
        for (int i = 0; i < length; i++)
            list[i] = temp[i];
        delete[] temp;
    }
    // release the unused memory
    void shrink()
    {
        int l = length;
        cout << "HI 1" << endl;

        T *temp = new T[length];
        cout << "HI 2" << endl;

        for (int i = 0; i < length; i++)
            temp[i] = list[i];
        cout << "HI 3" << endl;

        delete[] list;
        cout << "HI 4" << endl;
        cout << "Length is : " << l << endl;

        list = new T[l];
        cout << "HI 5" << endl;

        for (int i = 0; i < l; i++)
            list[i] = temp[i];
        cout << "HI 6" << endl;

        delete[] temp;
        cout << "HI 7" << endl;
        // list = temp;
    }

public:
    ArrayList()
    {
        capacity = 1;
        length = 0;
        current = 0;
        list = new T[capacity];
    }
    ArrayList(T ara[], int length, int capacity)
    {
        this->length = length;
        this->capacity = capacity;
        current = 0;
        list = new T[capacity];
        for (int i = 0; i < length; i++)
            list[i] = ara[i];
        if ((capacity / 2) >= length)
            shrink();
    }
    ~ArrayList()
    {
        delete[] list;
    }
    int size()
    {
        return length;
    }
    void push(T data)
    {
        if (length == capacity)
            expandCapacity();
        for (int i = length; i > current; i--)
            list[i] = list[i - 1];
        list[current] = data;
        length++;
        if ((capacity / 2) >= length)
            shrink();
    }
    void pushBack(T item)
    {
        if (length == capacity)
            expandCapacity();
        list[length++] = item;
        if ((capacity / 2) >= length)
            shrink();
    }
    T erase()
    {
        T value = list[current];
        for (int i = current; i < length - 1; i++)
            list[i] = list[i + 1];
        length--;
        int c = capacity;
        cout << "Erase checking" << endl;
        if ((c / 2) >= length)
            shrink();
        return value;
    }
    void setToBegin()
    {
        current = 0;
    }
    void setToEnd()
    {
        current = length - 1;
    }
    void prev()
    {
        if (current != 0)
            current = current - 1;
    }
    void next()
    {
        if (current != length - 1)
            current = current + 1;
    }
    int currPos()
    {
        return current;
    }
    void setToPos(int pos)
    {
        current = pos;
    }
    T getValue()
    {
        return list[current];
    }
    int find(T item)
    {
        for (int i = 0; i < length; i++)
        {
            if (list[i] == item)
                return i;
        }
        return -1;
    }
    void clear()
    {
        delete[] list;
        length = current = 0;
        list = new T[capacity];
    }
};
