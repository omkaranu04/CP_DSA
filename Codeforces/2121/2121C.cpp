#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    ll global_max = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> a[i][j];
            global_max = max(global_max, a[i][j]);
        }
    }
    vector<ll> rcnt(n, 0), ccnt(m, 0);
    ll totcnt = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (a[i][j] == global_max)
            {
                rcnt[i]++;
                ccnt[j]++;
                totcnt++;
            }
        }
    }
    bool exists = false;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ll tmp = (a[i][j] == global_max) ? 1 : 0;
            if (rcnt[i] + ccnt[j] - tmp == totcnt)
            {
                cout << global_max - 1 << endl;
                return;
            }
        }
    }
    cout << global_max << endl;
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