#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n, m;
vector<vector<ll>> g;
vector<ll> indeg, ans;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    indeg.resize(n + 1, 0);
    for (ll i = 1; i <= m; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[b].push_back(a);
        indeg[a]++;
    }
    priority_queue<ll> pq;
    for (ll i = 1; i <= n; i++)
        if (indeg[i] == 0)
            pq.push(i);
    while (!pq.empty())
    {
        ll u = pq.top();
        pq.pop();
        ans.push_back(u);
        for (auto v : g[u])
        {
            indeg[v]--;
            if (indeg[v] == 0)
                pq.push(v);
        }
    }
    reverse(ans.begin(), ans.end());
    if (1LL * ans.size() != n)
        cout << "IMPOSSIBLE\n";
    else
        for (auto x : ans)
            cout << x << " ";
    return 0;
}