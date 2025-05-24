#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, q;
struct UnionFind
{
    ll n, comps;
    vector<ll> par, rank, diff; // diff[x] = weight from x upto par[x]

    UnionFind(ll N)
    {
        n = N;
        comps = N;
        par.resize(N + 1);
        rank.resize(N + 1);
        diff.resize(N + 1);
        for (ll i = 0; i <= N; i++)
        {
            par[i] = i;
            rank[i] = 1;
            diff[i] = 0;
        }
    }
    // returns root and sum from x to the root
    pair<ll, ll> find(ll x)
    {
        if (par[x] == x)
            return {x, 0LL};
        pair<ll, ll> tmp = find(par[x]);
        ll r = tmp.first, w = tmp.second;
        w += diff[x];
        par[x] = r;
        diff[x] = w;
        return {par[x], diff[x]};
    }

    // merge
    void merge(ll x, ll y, ll z)
    {
        pair<ll, ll> tmp1 = find(x), tmp2 = find(y);
        ll rx = tmp1.first, dx = tmp1.second;
        ll ry = tmp2.first, dy = tmp2.second;
        if (rx == ry)
            return;
        // we want dy - dx = z, as per standard thing
        if (rank[rx] < rank[ry]) // attach x to y
        {
            rank[ry] += rank[rx];
            par[rx] = ry;
            diff[rx] = dy - dx - z;
        }
        else // attach y to x
        {
            rank[rx] += rank[ry];
            par[ry] = rx;
            diff[ry] = dx + z - dy;
        }
        comps--;
    }
    pair<bool, ll> query(ll x, ll y)
    {
        pair<ll, ll> tmp1 = find(x), tmp2 = find(y);
        ll rx = tmp1.first, dx = tmp1.second;
        ll ry = tmp2.first, dy = tmp2.second;
        if (rx != ry)
            return {false, 0LL};
        else
            return {true, dy - dx};
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;

    UnionFind uf(n);

    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 0)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            uf.merge(x, y, z);
        }
        else
        {
            ll x, y;
            cin >> x >> y;
            pair<ll, ll> tmp = uf.query(x, y);
            bool exist = tmp.first;
            ll ans = tmp.second;
            if (exist)
                cout << ans << endl;
            else
                cout << "?\n";
        }
    }
    return 0;
}