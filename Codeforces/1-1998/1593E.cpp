#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<vector<ll>> g(n + 1);
        vector<ll> deg(n + 1, 0);
        for (ll i = 1; i <= n - 1; i++)
        {
            ll u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        // BFS
        queue<ll> q;
        for (ll i = 1; i <= n; i++)
        {
            if (deg[i] <= 1)
                q.push(i);
        }
        ll rem = n;
        for (ll op = 1; op <= k; op++)
        {
            if (q.empty())
                break;

            ll sz = q.size();
            rem -= sz;
            while (sz--)
            {
                ll u = q.front();
                q.pop();
                for (ll v : g[u])
                {
                    if (deg[v] > 0)
                    {
                        deg[v]--;
                        if (deg[v] == 1)
                            q.push(v);
                    }
                }
                deg[u] = 0;
            }
        }
        cout << rem << endl;
    }
    return 0;
}