#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll N, Q;
struct DSU
{
    ll n;
    vector<ll> par, sz, blk;
    vector<bool> isblk;
    DSU(ll _n)
    {
        n = _n;
        sz.resize(n + 1, 1);
        blk.resize(n + 1, 0);
        isblk.resize(n + 1, false);
        par.resize(n + 1);
        for (ll i = 0; i <= n; i++)
            par[i] = i;
    }
    ll find(ll x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    void merge(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        // x is smaller
        if (sz[x] > sz[y])
            swap(x, y);
        par[x] = y;
        sz[y] += sz[x];
        blk[y] += blk[x];
    }
    void query1(ll u, ll v) { merge(u, v); }
    void query2(ll v)
    {
        ll rootv = find(v);
        if (isblk[v])
        {
            isblk[v] = false;
            blk[rootv]--;
        }
        else
        {
            isblk[v] = true;
            blk[rootv]++;
        }
    }
    void query3(ll v)
    {
        v = find(v);
        cout << (blk[v] > 0 ? "Yes\n" : "No\n");
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> Q;
    DSU dsu(N);
    while (Q--)
    {
        ll t, u, v;
        cin >> t;
        if (t == 1)
        {
            cin >> u >> v;
            dsu.query1(u, v);
        }
        else if (t == 2)
        {
            cin >> v;
            dsu.query2(v);
        }
        else
        {
            cin >> v;
            dsu.query3(v);
        }
    }
    return 0;
}