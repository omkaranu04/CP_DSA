#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m, k;
vector<vector<pair<ll, ll>>> g;
vector<priority_queue<ll>> pq;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    g.resize(n + 1);
    pq.resize(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
    }
    queue<ll> q;
    q.push(1);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();

        for (auto x : g[u])
        {
            ll v = x.first, w = x.second;
            if (pq[v].top() < pq[u].top() + w)
            {
                pq[v].push(pq[u].top() + w);
                q.push(v);
                if (pq[v].size() > k)
                    pq[v].pop();
            }
        }
    }
    auto temp = pq[n];
    vector<ll> ans;
    while (!temp.empty())
    {
        ans.push_back(temp.top());
        temp.pop();
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << " ";
    return 0;
}