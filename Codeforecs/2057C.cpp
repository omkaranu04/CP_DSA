#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll l, r;
    cin >> l >> r;
    ll base = 0, bit = 62;
    while (bit >= 0)
    {
        ll x = (l & (1LL << bit)), y = (r & (1LL << bit));
        if (x == y)
        {
            if (x)
                base += (1LL << bit);
        }
        else
            break;
        --bit;
    }
    ll x = base + (1LL << bit);
    if (r >= x + 1)
    {
        cout << x - 1 << " " << x << " " << x + 1 << endl;
    }
    else
    {
        cout << x - 2 << " " << x - 1 << " " << x << endl;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}