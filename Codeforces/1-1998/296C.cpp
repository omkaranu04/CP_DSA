#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n + 2, 0);
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    vector<array<ll, 3>> operations(m + 1);
    for (ll i = 0; i < m; i++)
    {
        ll l, r, d;
        cin >> l >> r >> d;
        operations[i + 1] = {l, r, d};
    }
    vector<ll> ps(m + 2, 0);
    for (ll i = 0; i < k; i++)
    {
        ll x, y;
        cin >> x >> y;
        ps[x]++;
        ps[y + 1]--;
    }
    for (ll i = 1; i < m + 2; i++)
        ps[i] += ps[i - 1];

    vector<ll> diff(n + 2, 0);
    for (ll i = 1; i <= m; i++)
    {
        if (ps[i])
        {
            ll l = operations[i][0], r = operations[i][1];
            ll d = operations[i][2];
            diff[l] += ps[i] * d;
            diff[r + 1] -= ps[i] * d;
        }
    }
    for (ll i = 1; i <= n; i++)
        diff[i] += diff[i - 1];
    for (ll i = 1; i <= n; i++)
        cout << a[i] + diff[i] << " ";
    return 0;
}