#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> g;
vector<int> outdeg;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    outdeg.resize(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u); // reverse graph
        outdeg[u]++;       // out degree
    }
    vector<pair<int, int>> ans;
    priority_queue<int> q; // max heap
    for (int i = 1; i <= n; i++)
    {
        if (outdeg[i] == 0)
            q.push(i);
    }
    int cnt = n;
    while (!q.empty())
    {
        int node = q.top();
        q.pop();
        ans.push_back({node, cnt--});
        for (int v : g[node])
        {
            outdeg[v]--;
            if (outdeg[v] == 0)
                q.push(v);
        }
    }
    // cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    // cout << "print ans : ";
    for (auto x : ans)
        cout << x.second << " ";
    return 0;
}