#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, w;
    cin >> n >> w;
    vector<vector<pair<ll, ll>>> pts(w + 1);
    map<pair<ll, ll>, ll> mp;
    map<ll, ll> rem;
    for (ll i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        pts[x].push_back({y, i});
    }
    for (ll i = 1; i <= w; i++)
    {
        if (pts[1].size())
        {
            sort(pts[i].rbegin(), pts[i].rend());
        }
    }
    ll tmp = 0;
    while (1)
    {
        ll mx = -1, x = 0;
        for (ll i = 1; i <= w; i++)
        {
            if (pts[i].size() == 0)
            {
                x = 1;
                break;
            }
            // all cols maximum y
            mx = max(mx, pts[i].back().first);
        }
        if (x)
            break;
        tmp += mx;
        for (ll i = 1; i <= w; i++)
        {
            rem[pts[i].back().second] = tmp;
            pts[i].pop_back();
            if (pts[i].size())
            {
                pts[i][pts[i].size() - 1].first = max(1LL, pts[i].back().first - tmp);
            }
        }
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll t, a;
        cin >> t >> a;
        if (rem[a] == 0 || rem[a] > t)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}