#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n, m;
vector<ll> a;
vector<pair<ll, ll>> flares;

bool check(ll mid)
{
    vector<ll> need = a;
    ll spent = 0, d = mid; // spent on discounted shit

    for (ll i = m; i >= 1; i--)
    {
        ll item = flares[i].second, day = flares[i].first;
        if (day > mid)
            continue;
        ll req = need[item];
        ll money = min(d, min(day, req));
        spent += money;
        need[item] = max(0LL, need[item] - money);
        d = min(d - money, day - money);
    }
    ll leftamt = mid - spent;
    for (ll i = 1;i <= n; i++)
        leftamt -= 2 * need[i];
    if (leftamt >= 0)
        return true;
    return false;
}

void solve()
{
    cin >> n >> m;

    a.assign(n + 1, 0);
    flares.assign(m + 1, {0, 0});

    ll total = 0;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> a[i];
        total += a[i];
    }
    for (ll i = 1; i <= m; ++i)
        cin >> flares[i].first >> flares[i].second;

    sort(flares.begin() + 1, flares.end());

    ll lo = 0, hi = 2 * total + 100, ans = -1;
    while (lo <= hi)
    {
        ll mid = (lo + hi) >> 1;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}