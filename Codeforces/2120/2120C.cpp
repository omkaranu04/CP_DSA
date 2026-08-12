#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n, m;
    cin >> n >> m;
    ll R = -1;
    for (ll r = 1; r <= n; r++)
    {
        ll poss = r * (r + 1) / 2;
        if (poss > m)
            break;
        ll rem = m - poss;
        ll maxposs = (n - r) * r;
        if (rem >= (n - r) && rem <= maxposs)
        {
            R = r;
            break;
        }
    }
    if (R == -1)
    {
        cout << "-1\n";
        return;
    }
    vector<pair<ll, ll>> a;
    for (ll i = 2; i <= R; i++)
        a.push_back({i, i - 1});
    ll rem = m - R * (R + 1) / 2;
    ll nodes = n - R;
    vector<ll> depth(nodes, 1);
    ll tar = rem - nodes;
    for (ll i = 0; i < nodes && tar > 0; i++)
    {
        ll add = min(tar, R - 1);
        depth[i] += add;
        tar -= add;
    }
    for (ll i = 0; i < nodes; i++)
        a.push_back({depth[i], R + 1 + i});
    cout << R << endl;
    for (auto &[u, v] : a)
        cout << u << " " << v << endl;
    return;
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