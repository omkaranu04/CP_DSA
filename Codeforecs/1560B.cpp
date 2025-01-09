#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int a1, b1, a, b, c;
        cin >> a1 >> b1 >> c;
        a = max(a1, b1);
        b = min(a1, b1);
        if (a - b >= b && 2 * (a - b) >= c)
        {
            if (c <= a - b)
                c = c + (a - b);
            else
                c = c - (a - b);
            cout << c << endl;
            continue;
        }
        cout << -1 << endl;
    }
    return 0;
}
