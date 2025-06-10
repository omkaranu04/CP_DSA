#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, Q;
vector<pair<ll, ll>> coordinates;
struct Edge
{
    ll u, v;
    ll w;
    bool operator<(Edge const &o) const
    {
        return w > o.w;
    }
};
struct Query
{
    ll t;
    ll a, b;
};
vector<Query> qs;

struct DSU
{
    ll n;
    vector<ll> parent, rank;
    DSU(ll _n) : n(_n)
    {
        parent.resize(_n + 1);
        rank.resize(_n + 1, 0);
        for (ll i = 0; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    ll find(ll x)
    {
        if (x == parent[x])
            return x;
        else
            return parent[x] = find(parent[x]);
    }
    bool unite(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (rank[x] < rank[y])
            swap(x, y); // x is greater
        parent[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
        return true;
    }
    bool same(ll x, ll y)
    {
        return find(x) == find(y);
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> Q;
    coordinates.reserve(n + Q);
    qs.resize(Q);

    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        coordinates.push_back({x, y});
    }

    for (ll i = 0; i < Q; i++)
    {
        cin >> qs[i].t;
        if (qs[i].t == 1)
        {
            cin >> qs[i].a >> qs[i].b;
            coordinates.push_back({qs[i].a, qs[i].b});
        }
        else if (qs[i].t == 3)
        {
            cin >> qs[i].a >> qs[i].b;
        }
    }

    ll m = coordinates.size();
    DSU dsu(m);
    vector<bool> used(m + 1, false);
    for (ll i = 1; i <= n; i++)
        used[i] = true;
    priority_queue<Edge> pq;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = i + 1; j <= n; j++)
        {
            ll dx = llabs(coordinates[i - 1].first - coordinates[j - 1].first);
            ll dy = llabs(coordinates[i - 1].second - coordinates[j - 1].second);
            pq.push({i, j, dx + dy});
        }
    }

    ll curr = n;
    for (auto &q : qs)
    {
        if (q.t == 1)
        {
            curr++;
            used[curr] = true;
            for (ll i = 1; i < curr; i++)
            {
                if (used[i])
                {
                    ll dx = llabs(coordinates[i - 1].first - coordinates[curr - 1].first);
                    ll dy = llabs(coordinates[i - 1].second - coordinates[curr - 1].second);
                    pq.push({i, curr, dx + dy});
                }
            }
        }
        else if (q.t == 2)
        {
            while (!pq.empty())
            {
                auto x = pq.top();
                if (!used[x.u] || !used[x.v] || dsu.same(x.u, x.v))
                {
                    pq.pop();
                    continue;
                }
                break;
            }
            if (pq.empty())
                cout << -1 << endl;
            else
            {
                ll k = pq.top().w;
                cout << k << endl;
                while (!pq.empty() && pq.top().w == k)
                {
                    auto x = pq.top();
                    pq.pop();
                    if (used[x.u] && used[x.v])
                        dsu.unite(x.u, x.v);
                }
            }
        }
        else
        {
            bool tmp = dsu.same(q.a, q.b);
            if (tmp)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}