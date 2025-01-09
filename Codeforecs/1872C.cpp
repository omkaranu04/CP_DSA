#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int right = r;
        int flag = 0;
        for (int i = 1; i <= r; i++)
        {
            if (__gcd(i, r - i) != 1 && (r - i) != 0)
            {
                cout << i << " " << r - i << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << -1 << endl;
    }
    return 0;
}