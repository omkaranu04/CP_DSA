#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
struct cmp
{
    bool operator()(const pair<ll, ll> &a, const pair<ll, ll> &b) const
    {
        return (a.first < b.first) || (a.first == b.first && a.second < b.second);
    }
};
void solve()
{
    ll n;
    cin >> n;
    vector<ll> s(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> s[i];
    vector<pair<ll, ll>> vec;
    for (ll i = 1; i <= n; i++)
        vec.push_back({s[i], i});
    sort(vec.begin(), vec.end(), cmp());
    vector<ll> pos(n + 1);
    for (ll i = 0; i < n; i++)
        pos[vec[i].second] = i;

    queue<ll> q;
    vector<ll> vis(n, 0), dist(n, -1);
    ll st = pos[1];
    vis[st] = 1;
    dist[st] = 1;
    q.push(st);
    ll ans = -1, i = 0;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();

        ll s = vec[u].first, d = dist[u];
        if (vec[u].second == n)
        {
            ans = d;
            break;
        }
        ll lim = 2 * 1LL * s;
        auto it = upper_bound(vec.begin(), vec.end(), make_pair(lim, INT_MAX), cmp()) - vec.begin();

        while (i < it)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                dist[i] = d + 1;
                q.push(i);
            }
            i++;
        }
    }
    cout << ans << endl;
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