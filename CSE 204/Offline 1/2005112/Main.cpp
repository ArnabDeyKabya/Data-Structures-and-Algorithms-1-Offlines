#include <iostream>
#include "Arr.cpp"
#include "LL.cpp"
#include <fstream>
using namespace std;
int main()
{
    ofstream outFile;
    ifstream inFile;
    inFile.open("list_input.txt");
    outFile.open("list_output.txt");
    int K, X;
    inFile >> K >> X;
    int ara[K];
    for (int i = 0; i < K; i++)
    {
        int value;
        inFile >> value;
        ara[i] = value;
    }
    //LinkedList<int> array(ara, K, X);
     ArrayList<int> array(ara, K, X);

    array.setToPos(K / 2);

    int position = array.currPos();
    array.setToBegin();
    outFile << "<";
    while (array.currPos() < array.size())
    {
        if (array.currPos() == position)
            outFile << "| ";
        outFile << array.getValue() << " ";
        if (array.currPos() == array.size() - 1)
            break;
        array.next();
    }
    outFile << ">" << endl;
    array.setToPos(position);
    int operation;
    inFile >> operation;
    while (operation--)
    {
        int func, param;
        int ret = -1;
        inFile >> func >> param;
        switch ((func))
        {
        case 1:
            ret = array.size();
            break;
        case 2:
            array.push(param);
            break;
        case 3:
            array.pushBack(param);
            break;
        case 4:
            ret = array.erase();
            break;
        case 5:
            array.setToBegin();
            break;
        case 6:
            array.setToEnd();
            break;
        case 7:
            array.prev();
            break;
        case 8:
            array.next();
            break;
        case 9:
            array.next();
            break;
        case 10:
            array.setToPos(param);
            break;
        case 11:
            ret = array.getValue();
            break;
        case 12:
            ret = array.find(param);
            break;
        case 13:
            array.clear();
            break;
        }
        int position = array.currPos();
        array.setToBegin();
        outFile << "<";
        while (array.currPos() < array.size())
        {
            if (array.currPos() == position)
                outFile << "| ";
            outFile << array.getValue() << " ";
            if (array.currPos() == array.size() - 1)
                break;
            array.next();
        }
        outFile << ">" << endl;
        array.setToPos(position);
        outFile << ret << endl;
    }
    inFile.close();
    outFile.close();
}
