#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> color;

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    color[start] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (color[v] == -1)
            {
                color[v] = 1 - color[u];
                q.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    adj.resize(N + 1);
    color.resize(N + 1, -1);

    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u = 1; u <= N; ++u)
    {
        if (color[u] == -1)
        {
            bfs(u);
        }
    }

    int A = 0, B = 0;
    for (int u = 1; u <= N; ++u)
    {
        if (color[u] == 0)
            A++;
        else
            B++;
    }

    int K = A * B - M;

    if (K % 2 == 0)
    {
        cout << "Takahashi\n";
    }
    else
    {
        cout << "Aoki\n";
    }

    return 0;
}
