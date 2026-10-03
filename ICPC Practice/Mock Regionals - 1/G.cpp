#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll LOG = 21;

ll n, m;

vector<vector<ll>> g;
vector<vector<ll>> par;
vector<ll> dep;

// mp1[(u, j)] = leftmost node whose 2^j ancestor is u
// mp2[(u, j)] = rightmost node whose 2^j ancestor is u
map<pair<ll, ll>, ll> mp1, mp2;

void dfs(ll u, ll p)
{
    par[u][0] = p;

    // j = 0
    // Children of u
    if (u != p)
    {
        if (mp1.find({p, 0}) == mp1.end())
            mp1[{p, 0}] = u;

        mp2[{p, 0}] = u;
    }

    // Binary lifting
    for (ll j = 1; j < LOG; j++)
    {
        par[u][j] = par[par[u][j - 1]][j - 1];

        ll r = par[u][j];

        if (mp1.find({r, j}) == mp1.end())
            mp1[{r, j}] = u;

        mp2[{r, j}] = u;
    }

    for (auto v : g[u])
    {
        if (v == p)
            continue;

        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

ll kthan(ll u, ll k)
{
    if (k > dep[u])
        return 0;

    for (ll j = 0; j < LOG; j++)
    {
        if (k & (1LL << j))
            u = par[u][j];
    }

    return u;
}

ll leftNode(ll u, ll k)
{
    for (ll j = 0; j < LOG; j++)
    {
        if (k & (1LL << j))
        {
            auto it = mp1.find({u, j});

            if (it == mp1.end())
                return 0;

            u = it->second;
        }
    }

    return u;
}

ll rightNode(ll u, ll k)
{
    for (ll j = 0; j < LOG; j++)
    {
        if (k & (1LL << j))
        {
            auto it = mp2.find({u, j});

            if (it == mp2.end())
                return 0;

            u = it->second;
        }
    }

    return u;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    g.resize(n + 1);
    par.resize(n + 1, vector<ll>(LOG, 0));
    dep.resize(n + 1, 0);

    vector<ll> parent(n + 1);
    vector<ll> roots;

    for (ll i = 1; i <= n; i++)
    {
        ll p;
        cin >> p;

        parent[i] = p;

        if (p == 0)
        {
            roots.push_back(i);
        }
        else
        {
            g[i].push_back(p);
            g[p].push_back(i);
        }
    }

    // Build binary lifting tables
    for (auto root : roots)
    {
        par[root][0] = root;

        for (ll j = 1; j < LOG; j++)
            par[root][j] = root;

        dfs(root, root);
    }

    // BFS numbering
    vector<ll> num(n + 1);

    for (auto root : roots)
    {
        queue<ll> q;
        q.push(root);

        ll cnt = 0;

        while (!q.empty())
        {
            ll sz = q.size();

            while (sz--)
            {
                ll u = q.front();
                q.pop();

                num[u] = cnt++;

                for (auto v : g[u])
                {
                    if (v == parent[u])
                        continue;

                    q.push(v);
                }
            }
        }
    }

    cin >> m;

    while (m--)
    {
        ll v, p;
        cin >> v >> p;

        // v does not have a p-ancestor
        if (p > dep[v])
        {
            cout << 0 << ' ';
            continue;
        }

        // p-th ancestor of v
        ll z = kthan(v, p);

        // Leftmost and rightmost p-descendants of z
        ll l = leftNode(z, p);
        ll r = rightNode(z, p);

        // Number of nodes between them, excluding v
        ll ans = num[r] - num[l];

        cout << ans << ' ';
    }

    cout << '\n';

    return 0;
}