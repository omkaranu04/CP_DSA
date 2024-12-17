#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        int maxi = max(max(a, b), c);
        int diff1 = maxi - a;
        int diff2 = maxi - b;
        int diff3 = maxi - c;
        if (n < diff1 + diff2 + diff3)
            cout << "NO" << endl;
        else
        {
            if (n == diff1 + diff2 + diff3)
                cout << "YES" << endl;
            else
            {
                n -= diff1 + diff2 + diff3;
                if (n % 3 == 0)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }
    return 0;
}