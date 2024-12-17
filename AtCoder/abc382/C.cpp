#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    vector<ll> eaten(2e5 + 10, -1);
    ll iter = 2e5 + 10;
    for (ll i = 0; i < n; i++)
    {
        while (iter >= a[i])
        {
            eaten[iter] = i + 1;
            iter--;
        }
    }

    for (ll i = 0; i < m; i++)
    {
        cout << eaten[b[i]] << "\n";
    }
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}