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
        int diff = abs(a - b);
        if (diff <= c && diff != 0)
            cout << 1 << endl;
        else if (diff == 0)
            cout << 0 << endl;
        else
            cout << ceil((float)diff / (2 * c)) << endl;
    }
    return 0;
}