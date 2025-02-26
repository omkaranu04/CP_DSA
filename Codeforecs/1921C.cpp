#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, f, a, b;
    cin >> n >> f >> a >> b;
    vector<ll> m(n);
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    ll cost = 0;
    cost += min(a * m[0], b);
    for (int i = 1; i < n; i++)
    {
        cost += min(a * (m[i] - m[i - 1]), b);
    }
    if (cost >= f)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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