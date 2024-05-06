#include <bits/stdc++.h>
using namespace std;
int notes(vector<int> v, int value)
{
    int m = v.size();
    int table[value + 1];
    table[0] = 0;
    for (int i = 1; i <= value; i++)
        table[i] = 1000000;
    for (int i = 1; i <= value; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[j] <= i)
            {
                int sub_result = table[i - v[j]];
                if (sub_result != 1000000 && sub_result + 1 < table[i])
                    table[i] = sub_result + 1;
            }
        }
    }
    if (table[value] == 1000000)
        return -1;
    return table[value];
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int value;
    cin >> value;
    int m = notes(v, value);
    cout << m << endl;
}
