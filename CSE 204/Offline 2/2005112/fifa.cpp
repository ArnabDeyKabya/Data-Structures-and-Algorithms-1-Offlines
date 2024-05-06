#include <iostream>
#include "Stack.cpp"
#include "Queue.cpp"
#include <fstream>
using namespace std;

class customer
{
public:
    int enterTime;
    int exitTime;
    int stayTime;
    int customerID;
    customer()
    {
        enterTime = 0;
        exitTime = 0;
        stayTime = 0;
        customerID = 0;
    }
    customer(int enterTime, int exitTime, int customerID)
    {
        this->enterTime = enterTime;
        this->exitTime = exitTime;
        this->customerID = customerID;
    }
    void setCustomer(int enterTime, int stayTime, int customerID)
    {
        this->enterTime = enterTime;
        this->stayTime = stayTime;
        this->customerID = customerID;
    }
};

int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("fifa_input.txt");
    outfile.open("fifa_output.txt");
    int n, c;
    infile >> n >> c;
    customer ara[n];
    for (int i = 0; i < n; i++)
    {
        int enter, rent;
        infile >> enter >> rent;
        ara[i].setCustomer(enter, rent, (i + 1));
    }
    queue<customer> line1;
    stack<customer> line2;
    int customerNo = 0;
    customer current1;
    customer current2;
    int console_1_ReleaseTime = 0;
    int console_2_ReleaseTime = 0;
    int console_1_free = 1;
    int console_2_free = 1;
    for (int t = 0; t <= c; t++)
    {
        if (t == ara[customerNo].enterTime && line1.length() < 3)
        {
            line1.enqueue(ara[customerNo]);
            if (customerNo < n - 1)
                customerNo++;
        }
        if (console_1_ReleaseTime == t)
            console_1_free = 1;
        if (line1.length() > 0)
        {
            if (console_1_free == 1)
            {
                current1 = line1.deque();

                int l = current1.customerID - 1;
                console_1_free = 0;
                console_1_ReleaseTime = t + current1.stayTime;
                if (console_1_ReleaseTime > c)
                    console_1_ReleaseTime = c;
                ara[l].exitTime = console_1_ReleaseTime;
            }
        }

        if (t == ara[customerNo].enterTime && line1.length() == 3)
        {
            line2.push(ara[customerNo]);
            if (customerNo < n - 1)
                customerNo++;
        }
        if (console_2_ReleaseTime == t)
        {
            console_2_free = 1;
        }
        if (line2.length() > 0)
        {
            if (console_2_free == 1)
            {
                current2 = line2.pop();
                int l = current2.customerID - 1;
                console_2_free = 0;
                console_2_ReleaseTime = t + current2.stayTime;
                if (console_2_ReleaseTime > c)
                    console_2_ReleaseTime = c;
                ara[l].exitTime = console_2_ReleaseTime;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        outfile << ara[i].customerID << " > " << ara[i].exitTime << endl;
    }
    infile.close();
    outfile.close();
}
