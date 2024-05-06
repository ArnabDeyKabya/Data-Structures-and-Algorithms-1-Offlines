#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int i = 1;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        if (n == 1 || m == 1)
        {
            cout << "case " << i << ": " << max(n, m) << endl;
        }
        else if (n == 2 || m == 2)
        {
            int big = m * n;
            int ans = (m * n) / 2;
            if (big % 4 == 1 || big % 4 == 3)
                ans++;
            else
                ans += 2;
            cout << "case " << i << ": " << ans << endl;
        }
        else
        {
            int ans;
            if ((m * n) / 2 == 1)
            {
                ans = (m * n) / 2 + 1;
            }
            else
                ans = (m * n) / 2;
            cout << "case " << i << ": " << ans << endl;
        }
        i++;
    }
}