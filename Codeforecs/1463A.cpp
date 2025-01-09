#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll ans = a + b + c;
        if (ans % 9 != 0)
            cout << "NO" << endl;
        else
        {
            if (min(min(a, b), c) >= ((a + b + c) / 9))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}