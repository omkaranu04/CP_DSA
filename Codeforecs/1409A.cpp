#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
            cout << 0 << endl;
        else
        {
            int diff = abs(a - b);
            if (diff % 10 == 0)
                cout << diff / 10 << endl;
            else
                cout << diff / 10 + 1 << endl;
        }
    }
    return 0;
}