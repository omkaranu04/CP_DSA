#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
ll n, ans;
string s;
vector<vector<ll>> tree;
ll dfs(ll node)
{
    ll max1 = 0, max2 = 0;
    for (auto child : tree[node])
    {
        ll th = dfs(child);
        if (s[node] == s[child])
            continue;
        if (th > max1)
        {
            max2 = max1;
            max1 = th;
        }
        else if (th > max2)
            max2 = th;
    }
    ans = max(ans, 1 + max1 + max2);
    return max1 + 1;
}
void solve()
{
    cin >> n;
    tree.clear();
    tree.resize(n);
    vector<ll> parent(n);
    for (ll i = 0; i < n; i++)
        cin >> parent[i];
    cin >> s;
    for (ll i = 1; i < n; i++)
        tree[parent[i]].push_back(i);
    ans = 1;
    dfs(0);
    cout << ans - 1 << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}