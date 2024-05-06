#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("input.txt");
    outFile.open("output.txt");
    int n;
    inFile >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        inFile >> start >> end;
        v.push_back(make_pair(start, end));
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i].second >= v[j].second)
            {
                swap(v[i], v[j]);
            }
        }
    }
    int i = 0;
    int j = 1;
    int count = 1;
    vector<pair<int, int>> v2;
    v2.push_back(make_pair(v[0].first, v[0].second));
    while (j < n)
    {
        if (v[i].second <= v[j].first)
        {
            count++;
            i = j;
            j++;
            v2.push_back(make_pair(v[i].first, v[i].second));
        }
        else
            j++;
    }
    outFile << count << endl;
    for (int i = 0; i < v2.size(); i++)
    {
        outFile << v2[i].first << " " << v2[i].second << endl;
    }
}