#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        int ans = 0;
        int y;
        for (int i = 1; i < x; i++)
        {
            if (__gcd(x, i) + i > ans)
            {
                ans = __gcd(x, i) + i;
                y = i;
            }
        }
        cout << y << endl;
    }
    return 0;
}