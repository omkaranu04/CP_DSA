#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll MAXA = 1000010;
ll pcnt[MAXA], sqr[MAXA];
void precompute()
{
    for (ll i = 0; i < MAXA; i++)
        sqr[i] = (ll)sqrt(i);
    memset(pcnt, 0, sizeof(pcnt));
    for (ll p = 2; p < MAXA; p++)
    {
        if (pcnt[p] == 0)
        {
            for (ll m = p; m < MAXA; m += p)
                pcnt[m]++;
        }
    }
}
bool check(ll x, ll y, ll n)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}
struct node
{
    ll x, y;
    ll d;
    bool operator<(const node &o) const { return d > o.d; }
};
void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            cin >> a[i][j];

    vector<vector<ll>> dist(n, vector<ll>(n, 1e18));
    priority_queue<node> pq;
    dist[0][0] = 0;
    pq.push({0, 0, 0});

    while (!pq.empty())
    {
        node curr = pq.top();
        pq.pop();
        ll x = curr.x, y = curr.y;
        if (curr.d != dist[x][y])
            continue;
        if (x == n - 1 && y == n - 1)
        {
            cout << curr.d << endl;
            return;
        }
        ll p = pcnt[a[x][y]], w = sqr[a[x][y]];

        if (p == 0)
            continue;

        for (ll dx = -p; dx <= p; dx++)
        {
            ll rem = p - abs(dx);
            for (ll dy = -rem; dy <= rem; dy++)
            {
                if (dx == 0 && dy == 0)
                    continue;
                ll nx = x + dx, ny = y + dy;
                if (!check(nx, ny, n))
                    continue;
                ll nd = curr.d + w;
                if (nd < dist[nx][ny])
                {
                    dist[nx][ny] = nd;
                    pq.push({nx, ny, nd});
                }
            }
        }
    }
    cout << -1 << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    precompute();
    while (t--)
    {
        solve();
    }
    return 0;
}