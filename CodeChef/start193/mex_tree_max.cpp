#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll getidx(ll u, ll v, ll n)
{
    return (n * u - (u * (u - 1)) / 2 + (v - u));
}
void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll m = (n * (n + 1)) / 2;
    vector<bitset<2001 * 2001 / 2 + 10>> pbitset(n);

    for (ll st = 0; st < n; st++)
    {
        vector<ll> dist(n, -1), par(n, -1);
        queue<ll> q;
        q.push(st);
        dist[st] = 0;

        while (!q.empty())
        {
            ll u = q.front();
            q.pop();
            for (auto v : g[u])
            {
                if (dist[v] == -1)
                {
                    dist[v] = dist[u] + 1;
                    par[v] = u;
                    q.push(v);
                }
            }
        }

        for (ll fin = st; fin < n; fin++)
        {
            ll idx = getidx(st, fin, n);
            ll curr = fin;
            while (curr != -1)
            {
                pbitset[curr].set(idx);
                curr = par[curr];
            }
        }
    }

    ll ans = 0;
    bitset<2001 * 2001 / 2 + 10> live;
    live.set();
    vector<bool> used(n, false);
    for (ll k = 0; k < n; k++)
    {
        ll bv = -1, bcnt = -1;
        for (ll v = 0; v < n; v++)
        {
            if (used[v])
                continue;
            auto tmp = live & pbitset[v];
            ll cnt = tmp.count();
            if (cnt > bcnt)
            {
                bcnt = cnt;
                bv = v;
            }
        }
        if (bcnt <= 0)
            break;
        used[bv] = true;
        ans += bcnt;
        live &= pbitset[bv];
    }
    cout << ans << endl;
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