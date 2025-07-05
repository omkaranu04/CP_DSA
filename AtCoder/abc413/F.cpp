#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
ll H, W, K;
struct best
{
    ll a = INF, b = INF;
    bool update(ll x)
    {
        if (x <= a)
        {
            b = a;
            a = x;
            return b != INF;
        }
        if (x < b)
        {
            b = x;
            return true;
        }
        return false;
    }
};
inline ll id(ll r, ll c) { return r * W + c; }
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
bool check(ll x, ll y)
{
    return x >= 0 && x < H && y >= 0 && y < W;
}
int main(int argc, char const *argv[])
{
    cin >> H >> W >> K;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll SZ = H * W;
    vector<ll> dist(SZ, INF);
    vector<best> tbest(SZ);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    for (ll i = 0; i < K; i++)
    {
        ll r, c;
        cin >> r >> c;
        r--, c--;
        ll v = id(r, c);
        if (dist[v] > 0)
        {
            dist[v] = 0;
            pq.push({0, v});
        }
    }

    while (!pq.empty())
    {
        auto [d, v] = pq.top();
        pq.pop();
        if (d != dist[v])
            continue;

        ll r = v / W, c = v % W;
        for (ll k = 0; k < 4; k++)
        {
            ll nr = r + dx[k], nc = c + dy[k];
            if (!check(nr, nc))
                continue;
            ll u = id(nr, nc);
            if (tbest[u].update(d))
            {
                if (tbest[u].b < INF)
                {
                    if (tbest[u].b + 1 < dist[u])
                    {
                        dist[u] = tbest[u].b + 1;
                        pq.push({tbest[u].b + 1, u});
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (auto d : dist)
        if (d < INF)
            ans += d;
    cout << ans;
    return 0;
}