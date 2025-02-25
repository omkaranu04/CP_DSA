#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m;
vector<ll> track, visited;
vector<vector<ll>> g, gr;
unordered_map<ll, vector<ll>> mp;
void dfs1(ll src)
{
    visited[src] = 1;
    for (auto i : g[src])
    {
        if (!visited[i])
            dfs1(i);
    }
    track.push_back(src);
}
void dfs2(ll src, ll comp)
{
    visited[src] = 1;
    mp[comp].push_back(src);
    for (auto i : gr[src])
    {
        if (!visited[i])
            dfs2(i, comp);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    gr.resize(n + 1);
    visited.resize(n + 1, 0);
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs1(i);
    }
    reverse(track.begin(), track.end());
    fill(visited.begin(), visited.end(), 0);
    ll ans = 0;
    for (auto i : track)
    {
        if (!visited[i])
        {
            dfs2(i, ans);
            ans++;
        }
    }
    if (ans == 1)
        cout << "YES\n";
    else
    {
        cout << "NO\n";
        cout << mp[1].back() << " " << mp[0].back() << "\n";
    }
    return 0;
}