#include <bits/stdc++.h>
using namespace std;
ifstream inFile;
ofstream outFile;
class Heap
{
private:
    int capacity;
    int size;
    int *arr;
    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    changeCapacity()
    {
        int *temp = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        capacity = capacity * 2 + 2;
        delete arr;
        arr = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            arr[i] = temp[i];
        }
        delete temp;
    }
    minHeapify(int index)
    {
        int ri = right_Child(index);
        int li = left_Child(index);
        int smallest = index;
        if (li < size && arr[li] < arr[smallest])
            smallest = li;
        if (ri < size && arr[ri] < arr[smallest])
            smallest = ri;
        if (smallest != index)
        {
            swap(&arr[index], &arr[smallest]);
            minHeapify(smallest);
        }
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int right_Child(int i)
    {
        return 2 * i + 2;
    }
    int left_Child(int i)
    {
        return 2 * i + 1;
    }

public:
    Heap()
    {
        capacity = 1;
        size = 0;
        arr = new int[capacity];
    }

    void insert(int value)
    {
        if (size + 1 > capacity)
            changeCapacity();
        arr[size] = value;
        int k = size;
        size++;
        while (k != 0 && arr[parent(k)] > arr[k])
        {
            swap(&arr[parent(k)], &arr[k]);
            k = parent(k);
        }
        outFile << "Inserted " << value << endl;
    }
    int FindMin()
    {
        return arr[0];
    }
    int ExtractMin()
    {
        if (size == 1)
        {
            size--;
            return arr[0];
        }
        int minimum = arr[0];
        arr[0] = arr[size - 1];
        size--;
        minHeapify(0);
        return minimum;
    }
    void DecreaseKey(int prevKey, int newKey)
    {
        for (int i = 0; i < size; i++)
        {
            if (prevKey == arr[i])
            {
                arr[i] = newKey;
                while (i != 0 && arr[parent(i)] > arr[i])
                {
                    swap(&arr[i], &arr[parent(i)]);
                    i = parent(i);
                }
            }
        }
        outFile << prevKey << " decreased to " << newKey << endl;
    }
    void print()
    {
        outFile << "Printing the binary heap ....." << endl;
        outFile << "- - - - - - - - - - - - - - - - - - - - - -" << endl;
        int i = 0, k = 0;
        int count = 0;
        int j = 0;
        while (count < size)
        {
            outFile << endl;
            outFile << "Level " << k << ": ";
            for (j = i; j <= i + pow(2, k) - 1; j++)
            {
                outFile << arr[j] << " ";
                count++;
                if (count == size)
                    break;
            }
            i = j;
            k++;
        }
        outFile << endl;
        outFile << "- - - - - - - - - - - - - - - - - - - - - -" << endl;
    }
};
int main()
{

    inFile.open("input.txt");
    outFile.open("output.txt");
    Heap h;
    char command[10];
    int func;
    int param1, param2;
    while (true)
    {
        inFile >> command;
        if (strcmp("FIN", command) == 0)
            func = 1;
        else if (strcmp("EXT", command) == 0)
            func = 2;
        else if (strcmp("INS", command) == 0)
            func = 3;
        else if (strcmp("DEC", command) == 0)
            func = 4;
        else if (strcmp("PRI", command) == 0)
            func = 5;
        switch (func)
        {
        case 1:
            outFile << "FindMin returned " << h.FindMin() << endl;
            break;
        case 2:
            outFile << "ExtractMIn returned " << h.ExtractMin() << endl;
            break;
        case 3:
            inFile >> param1;
            h.insert(param1);
            break;
        case 4:
            inFile >> param1 >> param2;
            h.DecreaseKey(param1, param2);
            break;
        case 5:
            h.print();
            break;
        }
        if (inFile.eof())
            break;
    }
    inFile.close();
    outFile.close();
}
