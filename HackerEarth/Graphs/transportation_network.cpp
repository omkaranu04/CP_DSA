#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, q;
struct DSU
{
    ll n, comps;
    vector<ll> parent, rank;
    vector<vector<ll>> members;
    DSU(ll _n)
    {
        n = _n;
        comps = n;
        parent.resize(n + 1);
        rank.resize(n + 1);
        members.resize(n + 1);
        for (ll i = 0; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
            members[i].push_back(i);
        }
    }
    ll find(ll x)
    {
        if (x == parent[x])
            return x;
        else
            return parent[x] = find(parent[x]);
    }
    void merge(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (rank[x] < rank[y])
            swap(x, y);
        rank[x] += rank[y];
        parent[y] = x;
        comps--;
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    DSU road(n);
    queue<pair<ll, ll>> rail;
    while (q--)
    {
        ll t, u, v;
        cin >> t >> u >> v;
        if (t == 1)
            rail.push({u, v});
        else
            road.merge(u, v);
        while (!rail.empty())
        {
            auto [a, b] = rail.front();
            if (road.find(a) != road.find(b))
                break;
            rail.pop();
        }
        if (rail.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}