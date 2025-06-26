#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m, q;
vector<vector<ll>> g, cb, vis;
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
bool check(ll x, ll y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
void dfs(ll x, ll y, ll &sz, ll no)
{
    vis[x][y] = 1;
    cb[x][y] = no;
    sz++;
    for (ll i = 0; i < 4; i++)
    {
        ll nx = x + dx[i], ny = y + dy[i];
        if (check(nx, ny) && vis[nx][ny] == 0 && g[nx][ny] == 1)
            dfs(nx, ny, sz, no);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> q;
    g.resize(n, vector<ll>(m));
    cb.resize(n, vector<ll>(m));
    vis.resize(n, vector<ll>(m, 0));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            cin >> g[i][j];

    vector<ll> compsz;
    ll comps = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (!vis[i][j] && g[i][j] == 1)
            {
                ll sz = 0;
                dfs(i, j, sz, comps);
                compsz.push_back(sz);
                comps++;
            }
        }
    }

    ll totwhite = accumulate(compsz.begin(), compsz.end(), 0LL);
    vector<bool> rem(comps, false);
    for (ll i = 0; i < q; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        if (g[x][y] == 1)
        {
            ll idx = cb[x][y];
            if (!rem[idx])
            {
                totwhite -= compsz[idx];
                rem[idx] = true;
            }
        }
        cout << totwhite << endl;
    }
    return 0;
}