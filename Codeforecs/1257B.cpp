#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if (x > 3)
            cout << "YES" << endl;
        else if (x == 1)
            cout << (y == 1 ? "YES" : "NO") << endl;
        else
            cout << (y <= 3 ? "YES" : "NO") << endl;
    }
    return 0;
}