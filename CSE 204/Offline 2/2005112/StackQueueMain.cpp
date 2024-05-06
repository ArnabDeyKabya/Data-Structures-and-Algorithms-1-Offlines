#include <iostream>
#include "Stack.cpp"
#include "Queue.cpp"
#include <fstream>
using namespace std;
int main()
{
    ofstream outfile;
    ifstream infile;
    infile.open("input.txt");
    outfile.open("output.txt");
    int K, X;
    infile >> K >> X;
    int queue_ara[K];
    for (int i = 0; i < K; i++)
    {
        int y;
        infile >> y;
        queue_ara[i] = y;
    }
    queue<int> list1(queue_ara, K, X);
    int M, Y;
    infile >> M >> Y;
    int stack_ara[M];
    for (int i = 0; i < M; i++)
    {
        int y;
        infile >> y;
        stack_ara[i] = y;
    }
    stack<int> list2(stack_ara, K, X);
    list1.List.setToBegin();
    outfile << "<";
    while (list1.List.currPos() < list1.List.size())
    {
        if (list1.List.currPos() == 0)
            outfile << "| ";
        outfile << list1.List.getValue() << " ";
        if (list1.List.currPos() == list1.List.size() - 1)
            break;
        list1.List.next();
    }
    outfile << ">" << endl;

    list2.List.setToBegin();
    outfile << "<";
    while (list2.List.currPos() < list2.List.size())
    {
        if (list2.List.currPos() == list2.List.size() - 1)
            outfile << "| ";
        outfile << list2.List.getValue() << " ";
        if (list2.List.currPos() == list2.List.size() - 1)
            break;
        list2.List.next();
    }
    outfile << ">" << endl;
    int operation;
    infile >> operation;
    while (operation--)
    {
        int func, param;
        int ret = -1;
        infile >> func >> param;
        switch (func)
        {
        case 1:
            list1.clear();
            break;
        case 2:
            list1.enqueue(param);
            break;
        case 3:
            ret = list1.deque();
            break;
        case 4:
            ret = list1.length();
            break;
        case 5:
            ret = list1.frontValue();
            break;
        case 6:
            ret = list1.rearValue();
            break;
        case 7:
            ret = list1.leaveQueue();
            break;
        case 8:
            list2.clear();
            break;
        case 9:
            list2.push(param);
            break;
        case 10:
            ret = list2.pop();
            break;
        case 11:
            ret = list2.length();
            break;
        case 12:
            ret = list2.topValue();
            break;
        }
        if (func == 8 || func == 9 || func == 10 || func == 11 || func == 12)
        {
            list2.List.setToBegin();
            outfile << "<";
            while (list2.List.currPos() < list2.List.size())
            {
                if (list2.List.currPos() == list2.List.size() - 1)
                    outfile << "| ";
                outfile << list2.List.getValue() << " ";
                if (list2.List.currPos() == list2.List.size() - 1)
                    break;
                list2.List.next();
            }
            outfile << ">" << endl;
        }

        else
        {
            list1.List.setToBegin();
            outfile << "<";
            while (list1.List.currPos() < list1.List.size())
            {
                if (list1.List.currPos() == 0)
                    outfile << "| ";
                outfile << list1.List.getValue() << " ";
                if (list1.List.currPos() == list1.List.size() - 1)
                    break;
                list1.List.next();
            }
            outfile << ">" << endl;
        }
        outfile << ret << endl;
    }
    infile.close();
    outfile.close();
}