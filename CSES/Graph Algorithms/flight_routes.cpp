#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m, k;
vector<vector<pair<ll, ll>>> g;
vector<priority_queue<ll>> nodepq;
vector<ll> vis;
void dijkstra()
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    nodepq[1].push(0);

    while (!pq.empty())
    {
        auto [cost, u] = pq.top();
        pq.pop();

        if (cost > nodepq[u].top()) // lazy pruning important
            continue;

        for (auto &[v, w] : g[u])
        {
            ll new_cost = cost + w;
            if (nodepq[v].size() < k)
            {
                nodepq[v].push(new_cost);
                pq.push({new_cost, v});
            }
            else if (nodepq[v].top() > new_cost)
            {
                nodepq[v].pop();
                nodepq[v].push(new_cost);
                pq.push({new_cost, v});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    g.resize(n + 1);
    nodepq.resize(n + 1);
    vis.resize(n + 1, 0);
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    dijkstra();

    vector<ll> ans;
    while (!nodepq[n].empty())
    {
        ans.push_back(nodepq[n].top());
        nodepq[n].pop();
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << " ";
    return 0;
}