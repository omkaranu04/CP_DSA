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
    bool merge(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (sz[x] > sz[y])
            swap(x, y);
        par[x] = y;
        sz[y] += sz[x];
        return true;
    }
};
struct Edge
{
    ll u, v, w;
    ll id;
};
struct QueryEdge
{
    ll q, edgeId;
};
vector<Edge> edges;
bool comp(QueryEdge a, QueryEdge b)
{
    // sort by weight first, then query
    if (edges[a.edgeId].w != edges[b.edgeId].w)
        return edges[a.edgeId].w < edges[b.edgeId].w;
    return a.q < b.q;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, q;
    cin >> n >> m >> q;
    edges.resize(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].id = i;
    }
    // store queries, queries in which edge occurs
    vector<vector<ll>> queries(q), edgeQueries(m);
    for (ll i = 0; i < q; i++)
    {
        ll k;
        cin >> k;
        queries[i].resize(k);
        for (ll j = 0; j < k; j++)
        {
            ll x;
            cin >> x;
            x--;
            queries[i][j] = x;
            edgeQueries[x].push_back(i);
        }
    }

    // sort edge indices according to weight in order
    vector<ll> order(m);
    for (ll i = 0; i < m; i++)
        order[i] = i;
    sort(order.begin(), order.end(), [&](ll a, ll b)
         { return edges[a].w < edges[b].w; });

    vector<QueryEdge> occur;
    for (ll e = 0; e < m; e++)
    {
        for (auto q : edgeQueries[e])
            occur.push_back({q, e});
    }
    sort(occur.begin(), occur.end(), comp);

    DSU globalDSU(n);
    vector<ll> ans(q, 1);

    // Temporary DSU
    vector<ll> tempPar(n + 1), tempSz(n + 1, 1), tempVersion(n + 1, 0);
    ll version = 0;
    auto tempFind = [&](ll x)
    {
        ll root = x;
        while (tempPar[root] != root)
            root = tempPar[root];
        while (tempPar[x] != x)
        {
            ll nxt = tempPar[x];
            tempPar[x] = root;
            x = nxt;
        }
        return root;
    };
    auto tempMerge = [&](ll x, ll y)
    {
        x = tempFind(x);
        y = tempFind(y);
        if (x == y)
            return false;
        if (tempSz[x] > tempSz[y])
            swap(x, y);
        tempPar[x] = y;
        tempSz[y] += tempSz[x];
        return true;
    };

    ll ei = 0, oi = 0;
    while (ei < m)
    {
        ll weight = edges[order[ei]].w;
        ll ej = ei;
        // [ei, ej) -> all graph edges of given weight
        while (ej < m && edges[order[ej]].w == weight)
            ej++;
        ll oj = oi;
        // [oi, oj) -> all query-edge occurences if given weight
        while (oj < occur.size() && edges[occur[oj].edgeId].w == weight)
            oj++;

        // Process each query for this weight given
        ll pos = oi;
        while (pos < oj)
        {
            ll qId = occur[pos].q, end = pos;
            while (end < oj && occur[end].q == qId)
                end++;
            if (ans[qId])
            {
                version++;
                // all < weight edges added to global DSU
                // for all required edges having == weight, map endpoint to global component, then check if these create cycles
                for (ll k = pos; k < end; k++)
                {
                    ll eId = occur[k].edgeId;
                    ll u = globalDSU.find(edges[eId].u), v = globalDSU.find(edges[eId].v);
                    // Initialise only temporary DSU nodes that are actually used
                    if (tempVersion[u] != version)
                    {
                        tempVersion[u] = version;
                        tempPar[u] = u;
                        tempSz[u] = 1;
                    }
                    if (tempVersion[v] != version)
                    {
                        tempVersion[v] = version;
                        tempPar[v] = v;
                        tempSz[v] = 1;
                    }

                    // they can create a cycle
                    if (!tempMerge(u, v))
                    {
                        ans[qId] = 0;
                        break;
                    }
                }
            }
            pos = end;
        }

        // Only after checking for all queries add ALL graph edges of this weight to Global DSU
        for (ll k = ei; k < ej; k++)
        {
            ll eId = order[k];
            globalDSU.merge(edges[eId].u, edges[eId].v);
        }
        ei = ej;
        oi = oj;
    }
    for (ll i = 0; i < q; i++)
        cout << (ans[i] ? "YES\n" : "NO\n");
    return 0;
}