#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int A, B, W;
        cin >> A >> B >> W;
        adj[A].push_back({B, W});
    }

    vector<vector<bool>> visited(N + 1, vector<bool>(1025, false)); 
    queue<pair<int, int>> q;

    q.push({1, 0});
    visited[1][0] = true;

    int answer = -1;

    while (!q.empty())
    {
        auto [u, curr_xor] = q.front();
        q.pop();

        if (u == N)
        {
            if (answer == -1 || curr_xor < answer)
                answer = curr_xor;
        }

        for (auto &[v, w] : adj[u])
        {
            int new_xor = curr_xor ^ w;
            if (!visited[v][new_xor])
            {
                visited[v][new_xor] = true;
                q.push({v, new_xor});
            }
        }
    }

    cout << answer << '\n';
    return 0;
}
