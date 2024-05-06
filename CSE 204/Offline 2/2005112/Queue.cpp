#include <iostream>
// #include "Arr.cpp"
#include "LL.cpp"
using namespace std;
template <typename T>
class queue
{
    int maxSize;
    int size;

public:
    MyList<T> List;
    // ArrayList<T> List;

    queue()
    {
        size = 0;
        maxSize = 0;
    }
    queue(T ara[], int k, int x)
    {
        List.setMyList(ara, k, x);
        // List.setArrayList(ara, k, x);
    }
    void clear()
    {
        List.clear();
    }
    void enqueue(T item)
    {
        List.pushBack(item);
    }
    T deque()
    {
        List.setToBegin();
        T item = List.erase();
        return item;
    }
    int length()
    {
        int total;
        total = List.size();
        return total;
    }
    T frontValue()
    {
        List.setToBegin();
        T value = List.getValue();
        return value;
    }
    T rearValue()
    {
        List.setToEnd();
        T value;
        value = List.getValue();
        return value;
    }
    T leaveQueue()
    {
        List.setToEnd();
        T item;
        item = List.erase();
        return item;
    }
    void print(queue<T> array)
    {
        int position = array.List.currPos();
        array.List.setToBegin();
        cout << "<";
        while (array.List.currPos() < array.List.size())
        {
            if (array.List.currPos() == 0)
                cout << "| ";
            cout << array.List.getValue() << " ";
            if (array.List.currPos() == array.List.size() - 1)
                break;
            array.List.next();
        }
        cout << ">" << endl;
        array.List.setToPos(position);
    }
};