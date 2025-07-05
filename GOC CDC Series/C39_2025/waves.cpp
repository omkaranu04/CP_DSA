#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m;
ll ways(vector<ll> &a, bool x)
{
    vector<ll> prev(m + 1, 0), curr(m + 1, 0), ps(m + 1, 0);
    if (a[0] == -1)
    {
        for (ll i = 1; i <= m; i++)
            prev[i] = 1;
    }
    else
        prev[a[0]] = 1;

    for (ll i = 1; i < n; i++)
    {
        ps[0] = 0;
        for (ll i = 1; i <= m; i++)
            ps[i] = (ps[i - 1] + prev[i]) % mod;

        bool y = ((i & 1) == 1) == x;

        for (ll v = 1; v <= m; v++)
        {
            if (a[i] != -1 && a[i] != v)
            {
                curr[v] = 0;
                continue;
            }
            if (y)
                curr[v] = (ps[m] - ps[v] + mod) % mod;
            else
                curr[v] = ps[v - 1];
        }
        swap(prev, curr);
        fill(curr.begin(), curr.end(), 0LL);
    }
    ll ans = 0;
    for (ll v = 1; v <= m; v++)
        ans = (ans + prev[v]) % mod;
    return ans;
}
void solve()
{
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    if (n == 1)
    {
        if (a[0] == -1)
            cout << m % mod << endl;
        else
            cout << 1 << endl;
        return;
    }
    ll a1 = ways(a, true);
    ll a2 = ways(a, false);
    cout << (a1 + a2) % mod << endl;
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