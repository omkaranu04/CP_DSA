#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int MAXV = 100005;
int par[MAXV], sz[MAXV], label[MAXV], pos[MAXV];

// Find function with path compression
int find_set(int x)
{
    if (par[x] == x)
        return x;
    return par[x] = find_set(par[x]);
}
void solve(int tc)
{
    cout << "Case " << tc << ":\n";
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    // pos[v] stores the representative index (0 to n-1) acting as the root for value v
    for (int i = 0; i < MAXV; i++)
        pos[i] = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        par[i] = i;
        sz[i] = 1;
        label[i] = a[i];

        if (pos[a[i]] == -1)
        {
            pos[a[i]] = i;
        }
        else
        {
            // Group identical initial elements together
            int root = pos[a[i]];
            par[i] = root;
            sz[root]++;
        }
    }

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, y;
            cin >> x >> y;
            if (x == y || pos[x] == -1)
                continue; // No-op

            if (pos[y] == -1)
            {
                // No element currently has value y, rename the root of x
                int rx = pos[x];
                label[rx] = y;
                pos[y] = rx;
                pos[x] = -1;
            }
            else
            {
                // Both values exist, merge components safely (Union by Size)
                int rx = pos[x];
                int ry = pos[y];

                if (sz[rx] > sz[ry])
                {
                    swap(rx, ry); // Ensure ry is the larger set
                }

                par[rx] = ry;
                sz[ry] += sz[rx];
                label[ry] = y; // The root component of the merge displays value y

                pos[y] = ry;
                pos[x] = -1;
            }
        }
        else
        {
            int idx;
            cin >> idx;
            idx--; // convert to 0-based index
            int root = find_set(idx);
            cout << label[root] << endl;
        }
    }
}
int main()
{
    // Optimise I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        solve(tc);
    }
    return 0;
}
