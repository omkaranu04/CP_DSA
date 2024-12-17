#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n, 1);
    ll e = -1;
    for (int i = x; i < n; i++)
    {
        a[i] = e;
        e *= -1;
    }
    e = -1;
    for (int i = y - 2; i >= 0; i--)
    {
        a[i] = e;
        e *= -1;
    }
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;
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