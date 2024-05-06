#include <iostream>
// #include "LL.cpp"
#include "Arr.cpp"
using namespace std;
template <typename T>
class stack
{
    int stackSize;
    int stackMaxSize;

public:
    // MyList<T> List;
    ArrayList<T> List;
    stack()
    {
        stackSize = 0;
        stackMaxSize = 0;
    }
    stack(T ara[], int k, int x)
    {
        // List.setMyList(ara, k, x);
        List.setArrayList(ara, k, x);
    }
    void clear()
    {
        List.clear();
    }
    void push(T item)
    {
        List.pushBack(item);
    }
    T pop()
    {
        List.setToEnd();
        T item = List.erase();
        return item;
    }
    int length()
    {
        int total;
        total = List.size();
        return total;
    }
    T topValue()
    {
        List.setToEnd();
        T item = List.getValue();
        return item;
    }
    T front()
    {
        List.setToBegin();
        return List.getValue();
    }
    void print(stack<T> array)
    {
        int position = array.List.currPos();
        array.List.setToBegin();
        cout << "<";
        while (array.List.currPos() < array.List.size())
        {
            if (array.List.currPos() == array.List.size() - 1)
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
