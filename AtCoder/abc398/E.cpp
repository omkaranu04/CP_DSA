#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<bool>> used(N + 1, vector<bool>(N + 1, false));
    vector<vector<int>> graph(N + 1);

    for (int i = 1; i <= N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        used[u][v] = true;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> color(N + 1, -1);
    queue<int> q;
    color[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int nx : graph[cur])
        {
            if (color[nx] == -1)
            {
                color[nx] = 1 - color[cur];
                q.push(nx);
            }
        }
    }

    int count0 = 0, count1 = 0;
    for (int i = 1; i <= N; i++)
    {
        if (color[i] == 0)
            count0++;
        else
            count1++;
    }
    int totalAllowedMoves = count0 * count1 - (N - 1);

    bool amFirst = (totalAllowedMoves % 2 == 1);
    if (amFirst)
        cout << "First" << "\n";
    else
        cout << "Second" << "\n";
    cout.flush();

    bool myTurn = amFirst;
    while (true)
    {
        if (myTurn)
        {
            bool moveMade = false;
            for (int i = 1; i <= N && !moveMade; i++)
            {
                for (int j = i + 1; j <= N && !moveMade; j++)
                {
                    if (!used[i][j] && (color[i] != color[j]))
                    {
                        cout << i << " " << j << "\n";
                        cout.flush();
                        used[i][j] = true;
                        moveMade = true;
                    }
                }
            }
            if (!moveMade)
                break;
        }
        else
        {
            int u, v;
            cin >> u >> v;
            if (u == -1 && v == -1)
            {
                break;
            }
            if (u > v)
                swap(u, v);
            used[u][v] = true;
        }
        myTurn = !myTurn;
    }

    return 0;
}