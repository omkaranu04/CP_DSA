#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n;
map<ll, vector<ll>> g;
vector<ll> ans;
map<ll, ll> mp1, mp2;
void dfs(ll node, ll depth)
{
    mp1[node] = depth;
    for (auto v : g[node])
    {
        if (mp1[v] == 0)
            dfs(v, depth + 1);
    }
}
void dfs2(ll node, ll depth)
{
    mp2[node] = depth;
    ans.push_back(node);
    for (auto v : g[node])
    {
        if (mp2[v] == 0)
            dfs2(v, depth + 1);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll start = g.begin()->first;
    dfs(start, 1);
    ll source = -1, maxDep = -1;
    for (auto &[i, depth] : mp1)
    {
        if (depth > maxDep)
        {
            source = i;
            maxDep = depth;
        }
    }
    dfs2(source, 1);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}