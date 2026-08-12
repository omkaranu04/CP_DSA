#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll l, r, d, u;
    cin >> l >> r >> d >> u;
    if (r == l && d == l && u == l)
        cout << "Yes\n";
    else
        cout << "No\n";
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