#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        ll a, b;
        cin >> a >> b;
        ll ans;
        if (a + a >= b)
        {
            if (x > y)
                swap(x, y);
            ans = x * b + (y - x) * a;
        }
        else
        {
            ans = (x + y) * a;
        }
        cout << ans << endl;
    }
    return 0;
}