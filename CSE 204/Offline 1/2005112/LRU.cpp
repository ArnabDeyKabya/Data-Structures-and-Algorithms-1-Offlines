#include <iostream>
#include "LL.cpp"
#include "Arr.cpp"
#include "fstream"
using namespace std;
class LRU
{
public:
    int key;
    int value;
    LRU()
    {
        key = value = 0;
    }
    LRU(int k, int v)
    {
        key = k;
        value = v;
    }
};
class LRUCache
{
    int capacity = 0;
    LinkedList<LRU> Cache;

public:
    LRUCache(int c)
    {
        capacity = c;
    }
    void put(int k, int v)
    {
        LRU temp(k, v);
        if (Cache.size() >= capacity)
        {
            Cache.setToBegin();
            LRU temp = Cache.erase();
        }
        Cache.setToBegin();
        while (Cache.currPos() < Cache.size())
        {

            if (k == Cache.getValue().key)
            {
                LRU t = Cache.erase();
                break;
            }
            Cache.next();
        }
        Cache.pushBack(temp);
    }
    int get(int k)
    {
        int ret = -1;
        Cache.setToBegin();
        while (Cache.currPos() < Cache.size())
        {
            if (Cache.getValue().key == k)
            {
                ret = Cache.getValue().value;
                LRU temp(Cache.getValue().key, Cache.getValue().value);
                LRU tem = Cache.erase();
                Cache.pushBack(temp);
                break;
            }
            Cache.next();
        }
        return ret;
    }
};
int main()
{
    int c;
    ofstream outFile;
    ifstream inFile;
    inFile.open("lru_input.txt");
    outFile.open("lru_output.txt");
    inFile >> c;
    LRUCache ob(c);
    int Q;
    inFile >> Q;
    while (Q--)
    {
        int func, param1, param2;
        int ret;
        inFile >> func;
        switch (func)
        {
        case 1:
            inFile >> param1;
            ret = ob.get(param1);
            outFile << ret << endl;
            break;
        case 2:
            inFile >> param1;
            inFile >> param2;
            ob.put(param1, param2);
            break;
        }
    }
    inFile.close();
    outFile.close();
}
