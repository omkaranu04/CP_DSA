#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            cin >> v[i][j];
    bool possible = true;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (v[i][j] + v[0][0] != v[i][0] + v[0][j])
                possible = false;
        }
    }
    if (possible)
        cout << "YES\n";
    else
        cout << "NO\n";
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