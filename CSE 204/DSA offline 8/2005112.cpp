#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("input.txt");
    outFile.open("output.txt");
    int items;
    inFile >> items;
    vector<int> value(items);
    vector<int> weight(items);
    for (int i = 0; i < items; i++)
    {
        inFile >> weight[i] >> value[i];
    }
    int capacity;
    inFile >> capacity;
    int table[items + 1][capacity + 1];
    for (int i = 0; i <= items; i++)
    {
        for (int j = 0; j < capacity + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                table[i][j] = 0;
            }
            else if (weight[i - 1] <= j)
            {
                table[i][j] = max(value[i - 1] + table[i - 1][j - weight[i - 1]], table[i - 1][j]);
            }
            else
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }
    int answer = table[items][capacity];
    outFile << answer << endl;
    int w = capacity;
    int i = items;
    while (i > 0 && answer > 0)
    {
        if (answer == table[i - 1][w])
        {
            i--;
            continue;
        }

        else
        {
            outFile << weight[i - 1] << " ";
            w -= weight[i - 1];
            answer -= value[i - 1];
        }
        i--;
    }
}
// minimum number of coins with dynamic programming