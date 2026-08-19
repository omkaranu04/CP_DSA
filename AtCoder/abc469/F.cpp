#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
struct DSU
{
    vector<ll> par, sz;
    DSU(ll n)
    {
        par.resize(n + 1);
        sz.resize(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }
    ll find(ll x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    bool merge(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (sz[x] < sz[y])
            swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        return true;
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll maxA = LLONG_MIN;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        maxA = max(maxA, a[i]);
    }
    vector<ll> pos(maxA + 1, -1);
    for (ll i = 0; i < n; i++)
        pos[a[i]] = i;

    DSU dsu(n);
    ll ans = 0, edgesUsed = 0;
    for (ll g = maxA; g >= 1 && edgesUsed < n - 1; g--)
    {
        ll prev = -1; // index of previous element seen with value multiple of g
        for (ll v = g; v <= maxA; v += g)
        {
            if (pos[v] == -1)
                continue;
            ll curr = pos[v];
            if (prev != -1)
            {
                if (dsu.merge(prev, curr))
                {
                    ans += g;
                    edgesUsed++;
                    if (edgesUsed == n - 1)
                        break;
                }
            }
            prev = curr;
        }
    }
    cout << ans << endl;
    return 0;
}