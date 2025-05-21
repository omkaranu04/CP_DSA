#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
vector<vector<ll>> g;
vector<ll> pos;
void bfs(ll src)
{
    vector<ll> dist(101, -1);
    queue<ll> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (ll dice = 1; dice <= 6; dice++)
        {
            ll v = u + dice;
            if (v > 100)
                continue;
            v = pos[v];
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << dist[100] << endl;
    return;
}
void solve()
{
    g.clear();
    pos.clear();
    g.resize(101);
    pos.resize(101);

    for (ll i = 1; i <= 100; i++)
        pos[i] = i;

    ll n, m;
    cin >> n;
    while (n--)
    {
        ll st, end;
        cin >> st >> end;
        pos[st] = end;
    }
    cin >> m;
    while (m--)
    {
        ll st, end;
        cin >> st >> end;
        g[st].push_back(end);
        pos[st] = end;
    }

    bfs(1);
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