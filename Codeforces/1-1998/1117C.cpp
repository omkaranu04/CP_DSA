#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
#define F first
#define S second
int main()
{
    ll sx, sy;
    cin >> sx >> sy;
    ll dx, dy;
    cin >> dx >> dy;
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<ll, ll>> wind(n + 1);
    wind[0].F = 0;
    wind[0].S = 0;
    for (ll i = 0; i <= n; i++)
    {
        if (s[i] == 'U')
        {
            wind[i + 1].F = wind[i].F + 0;
            wind[i + 1].S = wind[i].S + 1;
        }
        else if (s[i] == 'D')
        {
            wind[i + 1].F = wind[i].F + 0;
            wind[i + 1].S = wind[i].S - 1;
        }
        else if (s[i] == 'L')
        {
            wind[i + 1].F = wind[i].F - 1;
            wind[i + 1].S = wind[i].S + 0;
        }
        else if (s[i] == 'R')
        {
            wind[i + 1].F = wind[i].F + 1;
            wind[i + 1].S = wind[i].S + 0;
        }
    }

    ll lo = 0, hi = 1e18, ans = -1;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        ll full = mid / n, fullx = mid % n;
        ll nx = sx + full * 1LL * wind[n].F + wind[fullx].F;
        ll ny = sy + full * 1LL * wind[n].S + wind[fullx].S;
        ll rem = abs(nx - dx) + abs(ny - dy);
        if (rem <= mid)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans << endl;
}