#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n, k;
vector<vector<ll>> g;
vector<ll> degree;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    g.resize(n + 1);
    degree.resize(n + 1, 0);
    for (ll i = 1; i <= n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    set<ll> to_keep;
    for (ll i = 1; i <= k; i++)
    {
        ll v;
        cin >> v;
        to_keep.insert(v);
    }
    queue<ll> q;
    ll ans = n;
    for (ll i = 1; i <= n; i++)
    {
        if (degree[i] == 1)
            q.push(i);
    }
    while (!q.empty())
    {
        ll v = q.front();
        q.pop();

        if (to_keep.count(v))
            continue;

        for (auto x : g[v])
        {
            degree[x]--;
            if (degree[x] == 1)
                q.push(x);
        }
        ans--;
    }
    cout << ans << endl;
    return 0;
}