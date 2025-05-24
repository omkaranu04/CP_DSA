#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m;
vector<vector<ll>> grid, nodeid;
vector<pair<pair<ll, ll>, pair<ll, ll>>> edges;
ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};
bool check(ll x, ll y)
{
    return x >= 1 && y >= 1 && x <= n && y <= m;
}
struct UnionFind
{
    ll n;
    vector<ll> rank, par;
    multiset<ll> compSize;
    vector<pair<ll, ll>> st;
    UnionFind(ll N)
    {
        n = N;
        rank.resize(n + 1);
        par.resize(n + 1);
        for (ll i = 0; i <= n; i++)
        {
            par[i] = i;
            rank[i] = 1;
            compSize.insert(1);
        }
        st.clear();
    }
    ll find(ll x)
    {
        if (x == par[x])
            return x;
        return find(par[x]);
    }
    void merge(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (rank[x] < rank[y])
            swap(x, y); // keep x larger always, attach y to x
        compSize.erase(compSize.find(rank[x]));
        compSize.erase(compSize.find(rank[y]));
        rank[x] += rank[y];
        par[y] = x;
        st.push_back({y, x}); // so that we can revert back
        compSize.insert(rank[x]);
    }
    void revert()
    {
        while (!st.empty())
        {
            ll y = st.back().first, x = st.back().second;
            st.pop_back();
            compSize.erase(compSize.find(rank[x]));
            par[y] = y;         // restore the parent;
            rank[x] -= rank[y]; // restore size of x
            compSize.insert(rank[x]);
            compSize.insert(rank[y]);
        }
    }
    ll getmax()
    {
        auto it = compSize.end();
        it--;
        return *it;
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    grid.resize(n + 1, vector<ll>(m + 1));
    nodeid.resize(n + 1, vector<ll>(m + 1));
    ll tmp = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            nodeid[i][j] = tmp++;
        }
    }

    UnionFind uf(n * m + 1);

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            for (ll k = 0; k < 2; k++)
            {
                ll ni = i + dx[k], nj = j + dy[k];
                if (check(ni, nj))
                {
                    ll c1 = grid[i][j], c2 = grid[ni][nj];
                    if (c1 > c2)
                        swap(c1, c2);
                    if (c1 != c2)
                    {
                        edges.push_back({{c1, c2}, {nodeid[i][j], nodeid[ni][nj]}});
                    }
                    else
                    {
                        uf.merge(nodeid[i][j], nodeid[ni][nj]);
                    }
                }
            }
        }
    }

    uf.st.clear();
    sort(edges.begin(), edges.end());
    ll ans = uf.getmax();
    for (ll i = 0; i < edges.size(); i++)
    {
        ll j = i;
        while (j < edges.size() && edges[i].first == edges[j].first)
        {
            uf.merge(edges[j].second.first, edges[j].second.second);
            j++;
        }
        ans = max(ans, uf.getmax());
        uf.revert();
        i = j - 1;
    }
    cout << ans;
    return 0;
}