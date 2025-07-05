#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
struct DSU
{
    int next_node;
    vector<int> parent, sz, pos;
    vector<ll> sum;

    DSU(int n, int q)
    {
        int cap = n + q + 5;
        parent.resize(cap);
        sz.assign(cap, 0);
        sum.assign(cap, 0);
        pos.resize(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
            sz[i] = 1;
            sum[i] = i;
            pos[i] = i;
        }
        next_node = n + 1;
    }

    int find(int v)
    {
        return v == parent[v] ? v : parent[v] = find(parent[v]);
    }

    void unite(int A, int B)
    {
        int x = find(pos[A]);
        int y = find(pos[B]);
        if (x == y)
            return;

        parent[y] = x;
        sz[x] += sz[y];
        sum[x] += sum[y];
    }

    void move(int A, int B)
    {
        int rootA = find(pos[A]);
        int rootB = find(pos[B]);
        if (rootA == rootB)
            return; // nothing to do

        /* detach A from its current team */
        sz[rootA]--;
        sum[rootA] -= A;

        int node = next_node++;
        if (node >= (int)parent.size())
        {
            parent.push_back(0);
            sz.push_back(0);
            sum.push_back(0);
        }
        parent[node] = rootB;
        sz[node] = 1;
        sum[node] = A;

        sz[rootB]++;
        sum[rootB] += A;
        pos[A] = node;
    }

    pair<int, ll> query(int A)
    {
        int r = find(pos[A]);
        return {sz[r], sum[r]};
    }
};

void solve()
{
    int n, q;
    if (!(cin >> n >> q))
        return;

    DSU dsu(n, q);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int a, b;
            cin >> a >> b;
            dsu.unite(a, b);
        }
        else if (type == 2)
        {
            int a;
            cin >> a;
            auto [cnt, tot] = dsu.query(a);
            cout << cnt << ' ' << tot << '\n';
        }
        else
        {
            int a, b;
            cin >> a >> b;
            dsu.move(a, b);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
