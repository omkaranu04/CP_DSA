#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll l, r;
    cin >> l >> r;
    ll L, R;
    cin >> L >> R;
    if (L > r || l > R)
    {
        cout << 1 << endl;
    }
    else if ((l > L && r < R) || (L > l && r > R))
    {
        cout << min(r, R) - max(l, L) + 2 << endl;
    }
    else if (r == R && l != L)
    {
        cout << r - max(l, L) + 1 << endl;
    }
    else if (l == L && r != R)
    {
        cout << min(r, R) - l + 1 << endl;
    }
    else if (r == L || R == l)
    {
        cout << 2 << endl;
    }
    else if (r == R && l == L)
    {
        cout << r - l << endl;
    }
    else
    {
        cout << min(r, R) - max(l, L) + 2 << endl;
    }
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}