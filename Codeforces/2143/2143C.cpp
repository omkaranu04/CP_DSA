#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> g(n + 1);
        vector<ll> indeg(n + 1, 0);
        for (ll i = 1; i <= n - 1; i++)
        {
            ll u, v, x, y;
            cin >> u >> v >> x >> y;
            if (x <= y)
            {
                g[u].push_back(v);
                indeg[v]++;
            }
            else
            {
                g[v].push_back(u);
                indeg[u]++;
            }
        }
        vector<ll> topo;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (ll i = 1; i <= n; i++)
            if (!indeg[i])
                pq.push(i);
        while (!pq.empty())
        {
            ll u = pq.top();
            pq.pop();
            topo.push_back(u);
            for (auto v : g[u])
            {
                indeg[v]--;
                if (!indeg[v])
                    pq.push(v);
            }
        }
        vector<ll> ans(n + 1);
        for (ll i = 0; i < n; i++)
            ans[topo[i]] = i + 1;
        for (ll i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}