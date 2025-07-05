#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
string a, b, c;
struct DSU
{
    ll comps;
    vector<set<ll>> s;
    vector<ll> sz, par;
    DSU(ll n) : comps(n)
    {
        s.resize(n);
        sz.resize(n, 1);
        par.resize(n);
        for (ll i = 0; i < n; i++)
        {
            par[i] = i;
            s[i].insert(i);
        }
    }
    ll find(ll x)
    {
        if (x == par[x])
            return x;
        return par[x] = find(par[x]);
    }
    void merge(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (sz[x] < sz[y])
            swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        for (auto it : s[y])
        {
            s[x].insert(it);
        }
        s[y].clear();
        comps--;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c;
    ll n = a.length();
    DSU dsu(26);
    for (ll i = 0; i < n; i++)
        dsu.merge(a[i] - 'a', b[i] - 'a');

    for (ll i = 0; i < c.length(); i++)
    {
        ll ch = c[i] - 'a';
        ch = dsu.find(ch);
        cout << (char)(*dsu.s[ch].begin() + 'a');
    }
}