// // // // // // // // // // // // // //
//                                     //
//                                     //
//   Author:                           //
//            reckless_spark           //
//                                     //
//                                     //
//                                     //
//                                     //
// // // // // // // // // // // // // //
#include <bits/stdc++.h>
using namespace std;
#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
int main()
{
    FastIO;
    // write your code here
    int n;
    cin >> n;
    int k, prev = -1, count = 0;
    while (n != 0)
    {
        k = n % 10;
        if (prev == 9 && k == 9)
        {
            count--;
        }
        if (prev == -1 & k == 9)
        {
            count--;
        }
        if (k == 9)
        {
            count += 2;
        }
        prev = k;
        n = n / 10;
        if (n == 0 && k == 9)
            count--;
    }
    cout << count << endl;

    return 0;
}