#include <bits/stdc++.h>
using namespace std;
int merging_arrays(int ara[], int left, int mid, int right, vector<pair<int, int>> &v)
{
    int count = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int sub_array1[n1];
    int sub_array2[n2];
    for (int i = 0; i < n1; i++)
    {
        sub_array1[i] = ara[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        sub_array2[i] = ara[mid + i + 1];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (sub_array1[i] <= sub_array2[j])
        {
            ara[k] = sub_array1[i];
            k++;
            i++;
        }
        else
        {
            ara[k] = sub_array2[j];
            count += n1 - i;
            for (int left = i; left < n1; left++)
            {
                v.push_back(make_pair(sub_array1[left], sub_array2[j]));
            }
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        ara[k] = sub_array1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        ara[k] = sub_array2[j];
        k++;
        j++;
    }
    return count;
}
int counting_pairs(int ara[], int left, int right, vector<pair<int, int>> &v)
{
    int count = 0;
    if (left < right)
    {
        int mid = (left + right) / 2;
        count += counting_pairs(ara, left, mid, v);
        count += counting_pairs(ara, mid + 1, right, v);
        count += merging_arrays(ara, left, mid, right, v);
    }
    return count;
}
void print(vector<pair<int, int>> &v)
{
    cout << "The inverted pairs are ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << "(" << v[i].first << "," << v[i].second << ")";
        if (i < v.size() - 1)
            cout << ",";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int ara[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ara[i];
    }
    vector<pair<int, int>> v;
    cout << counting_pairs(ara, 0, n - 1, v) << endl;
    print(v);
}
