#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b && a != c)
            cout << c << endl;
        if (a == c && a != b)
            cout << b << endl;
        if (b == c && b != a)
            cout << a << endl;
    }
    return 0;
}