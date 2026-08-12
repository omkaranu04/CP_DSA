#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n % 2 == 1) // n is odd
    {
        cout << l << endl;
        return;
    }
    if (n == 2) // n is 2
    {
        cout << -1 << endl;
        return;
    }
    ll u = l;
    while (true)
    {
        ll tmp = l & u;
        if (!tmp)
            break;
        ll bit = tmp & -tmp;
        u += bit;
        u &= ~(bit - 1);
    }
    if (u > r)
        cout << -1 << endl;
    else
        cout << (k <= n - 2 ? l : u) << endl;
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