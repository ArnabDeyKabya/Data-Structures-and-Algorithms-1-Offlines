#include <bits/stdc++.h>
using namespace std;
string compare(string s1, string s2)
{
    if (s1.size() == 2)
        return s1;
    if (s2.size() == 2)
        return s2;
    int m = max(s1.size(), s2.size());
    if (m == s1.size())
        return s1;
    else
        return s2;
}
string find(string s)
{
    int i = 0, j = 0;
    int count = 0;
    for (i = 0; i < s.size(); i++)
    {
        for (j = 0; j < s.size(); j++)
        {
            if (s[i] == s[j])
                count++;
        }
        if (count == 0)
            break;
    }
    vector<char> left;
    vector<char> right;
    for (int k = 0; k < i; k++)
    {
        left.push_back(s[i]);
    }
    for (int k = i + 1; k < s.size(); k++)
    {
        right.push_back(s[i]);
    }
    string s1 = find(left);
    string s1 = find(right);
    string s1 = compare(left, right);
    return s1;
}
int main()
{
    string s;
    cin >> s;
    cout << find(s) << endl;
}