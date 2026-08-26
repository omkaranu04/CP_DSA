#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
struct DSU
{
    ll n;
    vector<ll> sz, par;
    DSU(ll _n)
    {
        n = _n;
        sz.resize(n + 1, 1);
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
        if (x > y)
            swap(x, y);
        par[x] = y;
        sz[y] += sz[x];
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m1, m2;
    cin >> n >> m1 >> m2;
    DSU moc(n), dia(n);
    for (ll i = 0; i < m1; i++)
    {
        ll u, v;
        cin >> u >> v;
        moc.merge(u, v);
    }
    for (ll i = 0; i < m2; i++)
    {
        ll u, v;
        cin >> u >> v;
        dia.merge(u, v);
    }

    vector<pair<ll, ll>> ans;
    // for (ll u = 1; u <= n; u++)
    // {
    //     for (ll v = u + 1; v <= n; v++)
    //     {
    //         if (moc.find(u) != moc.find(v) && dia.find(u) != dia.find(v))
    //         {
    //             ans.push_back({u, v});
    //             moc.merge(u, v);
    //             dia.merge(u, v);
    //         }
    //     }
    // }
    for (ll i = 2; i <= n; i++)
    {
        if (moc.find(1) != moc.find(i) && dia.find(1) != dia.find(i))
        {
            ans.push_back({1, i});
            moc.merge(1, i);
            dia.merge(1, i);
        }
    }

    vector<ll> A, B;
    for (ll i = 2; i <= n; i++)
    {
        bool inMoc = (moc.find(1) == moc.find(i));
        bool inDia = (dia.find(1) == dia.find(i));
        if (!inMoc && inDia)
            A.push_back(i);
        else if (inMoc && !inDia)
            B.push_back(i);
    }
    for (ll i = 0; i < min(A.size(), B.size()); i++)
    {
        ll u = A[i], v = B[i];
        ans.push_back({u, v});
        moc.merge(u, v);
        dia.merge(u, v);
    }

    cout << ans.size() << endl;
    for (auto [u, v] : ans)
        cout << u << " " << v << endl;
    return 0;
}