#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// void dfs(ll u, vector<vector<pair<ll, ll>>> &g, vector<bool> &visited, vector<ll> &ans)
// {
//     visited[u] = true;
//     for (auto [v, w] : g[u])
//     {
//         if (!visited[v])
//         {
//             ans[v] = ans[u] + w;
//             dfs(v, g, visited, ans);
//         }
//     }
// }
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].push_back({v, w});
        g[v].push_back({u, -w});
    }
    vector<bool> visited(n, false);
    vector<ll> ans(n, 0);
    // for (ll i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //         dfs(i, g, visited, ans);
    // }
    for (ll i = 0; i < n; i++)
    {
        if (visited[i])
            continue;

        stack<ll> st;
        st.push(i);
        visited[i] = true;

        while (!st.empty())
        {
            ll u = st.top();
            st.pop();

            for (const auto &[v, w] : g[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    ans[v] = ans[u] + w;
                    st.push(v);
                }
            }
        }
    }

    for (ll i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}