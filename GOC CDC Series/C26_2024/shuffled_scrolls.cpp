#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
vector<vector<ll>> g;
struct DSU
{
    ll comps;
    vector<ll> sz, par;
    DSU(ll n) : comps(n)
    {
        sz.resize(n, 1);
        par.resize(n);
        for (ll i = 0; i < n; i++)
            par[i] = i;
    }
    ll find(ll x)
    {
        if (par[x] == x)
            return x;
        else
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
        comps--;
    }
};
void solve()
{
    DSU dsu(26);
    ll n;
    cin >> n;
    vector<string> s(n);
    for (ll i = 0; i < n; i++)
        cin >> s[i];

    string ans = "";
    ll in[26], out[26];
    bool active[26];
    memset(active, false, sizeof(active));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    for (ll i = 0; i < n; i++)
    {
        ll u = s[i][0] - 'a';
        ll v = s[i][1] - 'a';

        out[u]++;
        in[v]++;

        if (!active[u])
            active[u] = true;
        if (!active[v])
            active[v] = true;
        dsu.merge(u, v);

        ll root = -1;
        bool connected = true;
        for (ll z = 0; z < 26; z++)
        {
            if (active[z])
            {
                if (root == -1)
                    root = dsu.find(z);
                else if (dsu.find(z) != root)
                {
                    connected = false;
                    break;
                }
            }
        }

        ll plus = 0, minus = 0;
        bool ok = connected;

        for (ll z = 0; z < 26 && ok; z++)
        {
            ll diff = out[z] - in[z];
            if (diff == 1)
                plus++;
            else if (diff == -1)
                minus++;
            else if (diff != 0)
                ok = false;
        }

        ok &= ((plus == 0 && minus == 0) || (plus == 1 && minus == 1));
        if (ok)
            ans.push_back('1');
        else
            ans.push_back('0');
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