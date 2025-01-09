#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> g;
vector<int> indeg, topo;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    indeg.resize(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
    }
    // min heap is this
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
            pq.push(i);
    }
    while (!pq.empty())
    {
        int top = pq.top();
        pq.pop();
        topo.push_back(top);
        for (auto i : g[top])
        {
            indeg[i]--;
            if (indeg[i] == 0)
                pq.push(i);
        }
    }
    if (topo.size() != n)
    {
        cout << "-1";
    }
    else
    {
        for (auto i : topo)
        {
            cout << i << " ";
        }
    }
    return 0;
}