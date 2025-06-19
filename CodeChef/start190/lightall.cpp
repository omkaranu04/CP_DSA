#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, const vector<vector<int>> &adj,
         vector<int> &matchZero, vector<int> &vis, int iter)
{
    for (int z : adj[u])
        if (vis[z] != iter) // z … zero node id
        {
            vis[z] = iter;
            if (matchZero[z] == -1 || dfs(matchZero[z], adj, matchZero, vis, iter))
            {
                matchZero[z] = u;
                return true;
            }
        }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        string S;
        cin >> S;

        /* map each lamp / zero position to a compact id */
        vector<int> lampId(N, -1), zeroId(N, -1);
        int L = 0, Z = 0;
        for (int i = 0; i < N; ++i)
            if (S[i] == '1')
                lampId[i] = L++;
            else
                zeroId[i] = Z++;

        if (Z == 0)
        { // no broken cells
            cout << "YES\n";
            continue;
        }

        /* build bipartite graph: lamp u  ->  list of zero ids it can serve */
        vector<vector<int>> adj(L);
        bool impossible = false;
        for (int i = 0; i < N; ++i)
            if (S[i] == '0')
            {
                int zid = zeroId[i];
                bool hasEdge = false;
                if (i > 0 && S[i - 1] == '1')
                {
                    adj[lampId[i - 1]].push_back(zid);
                    hasEdge = true;
                }
                if (i + 1 < N && S[i + 1] == '1')
                {
                    adj[lampId[i + 1]].push_back(zid);
                    hasEdge = true;
                }
                if (!hasEdge)
                {
                    impossible = true;
                    break;
                } // 0–cell with no neighbour lamp
            }
        if (impossible)
        {
            cout << "NO\n";
            continue;
        }

        /* maximum bipartite matching (lamps have capacity 1) */
        vector<int> matchZero(Z, -1), vis(Z, 0);
        int matchCnt = 0;
        for (int u = 0; u < L; ++u)
            if (dfs(u, adj, matchZero, vis, u + 1))
                ++matchCnt;

        cout << (matchCnt == Z ? "YES\n" : "NO\n");
    }
    return 0;
}