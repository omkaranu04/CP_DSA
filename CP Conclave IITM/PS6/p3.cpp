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
        int x = 0, y = 0;
        if (r >= 2 * l)
        {
            x = l;
            y = 2 * l;
        }
        else
        {
            x = -1;
            y = -1;
        }
        cout << x << " " << y << endl;
    }
    return 0;
}
