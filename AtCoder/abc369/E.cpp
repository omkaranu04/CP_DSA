#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n, m;
vector<vector<pair<ll, ll>>> g;
vector<pair<ll, ll>> bridges;
vector<ll> cost;
vector<vector<ll>> dist;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    bridges.resize(m + 1);
    cost.resize(m + 1);

    for (ll i = 1; i <= m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
        bridges[i] = {u, v};
        cost[i] = c;
    }

    // Floyd Warshall
    dist.resize(n + 1, vector<ll>(n + 1, 1e18));
    for (ll u = 1; u <= n; u++)
    {
        dist[u][u] = 0;
        for (auto v : g[u])
        {
            dist[u][v.first] = min(dist[u][v.first], v.second);
        }
    }

    for (ll k = 1; k <= n; k++)
    {
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    ll q;
    cin >> q;
    while (q--)
    {
        ll k;
        cin >> k;
        vector<ll> b(k);
        for (ll i = 0; i < k; i++)
            cin >> b[i];

        vector<tuple<ll, ll, ll>> compulsory_bridges; // u, v, c
        for (auto idx : b)
        {
            ll u = bridges[idx].first;
            ll v = bridges[idx].second;
            ll c = cost[idx];
            compulsory_bridges.push_back({u, v, c});
        }

        vector<ll> perm(k);
        for (ll i = 0; i < k; i++)
            perm[i] = i;

        ll min_time = 1e18;
        do
        {
            // try both for all bridges directions
            for (ll mask = 0; mask < (1 << k); mask++)
            {
                ll curr_time = 0, curr_pos = 1;
                for (ll i = 0; i < k; i++)
                {
                    ll idx = perm[i];
                    ll u = get<0>(compulsory_bridges[idx]);
                    ll v = get<1>(compulsory_bridges[idx]);
                    ll c = get<2>(compulsory_bridges[idx]);

                    bool direction = (mask >> i) & 1; // 1 for u->v, 0 for v->u

                    if (curr_pos != u && direction)
                        curr_time += dist[curr_pos][u]; // go to u
                    if (curr_pos != v && !direction)
                        curr_time += dist[curr_pos][v]; // go to v

                    curr_time += c; // cross the bridge

                    curr_pos = direction ? v : u; // go to the other end
                }
                if (curr_pos != n)
                    curr_time += dist[curr_pos][n]; // go to n if not already there

                min_time = min(min_time, curr_time);
            }
        } while (next_permutation(perm.begin(), perm.end()));

        cout << min_time << endl;
    }
    return 0;
}