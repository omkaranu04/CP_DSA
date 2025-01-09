#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    map<ll, set<ll>> ysOfx, xsOfy;
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        ysOfx[x].insert(y);
        xsOfy[y].insert(x);
    }
    ll ans = 0;
    for (ll i = 0; i < m; i++)
    {
        char c;
        int d;
        cin >> c >> d;
        if (c == 'U')
        {
            ll nY = sy + d;
            auto it = ysOfx[sx].lower_bound(sy);
            while (it != ysOfx[sx].end() && *it <= nY)
            {
                ans++;
                xsOfy[*it].erase(sx);
                it = ysOfx[sx].erase(it);
            }
            sy = nY;
        }
        else if (c == 'D')
        {
            ll nY = sy - d;
            auto it = ysOfx[sx].lower_bound(nY);
            while (it != ysOfx[sx].end() && *it <= sy)
            {
                ans++;
                xsOfy[*it].erase(sx);
                it = ysOfx[sx].erase(it);
            }
            sy = nY;
        }
        else if (c == 'L')
        {
            ll nX = sx - d;
            auto it = xsOfy[sy].lower_bound(nX);
            while (it != xsOfy[sy].end() && *it <= sx)
            {
                ans++;
                ysOfx[*it].erase(sy);
                it = xsOfy[sy].erase(it);
            }
            sx = nX;
        }
        else if (c == 'R')
        {
            ll nX = sx + d;
            auto it = xsOfy[sy].lower_bound(sx);
            while (it != xsOfy[sy].end() && *it <= nX)
            {
                ans++;
                ysOfx[*it].erase(sy);
                it = xsOfy[sy].erase(it);
            }
            sx = nX;
        }
    }
    cout << sx << " " << sy << " " << ans << " " << endl;
    return 0;
}