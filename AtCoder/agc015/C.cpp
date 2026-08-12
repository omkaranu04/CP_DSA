#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, q;
    cin >> n >> m >> q;
    vector<string> s(n);
    for (ll i = 0; i < n; i++)
        cin >> s[i];
    vector<vector<ll>> ps(n + 1, vector<ll>(m + 1, 0)), vv(n + 1, vector<ll>(m + 1, 0)), hh(n + 1, vector<ll>(m + 1, 0));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            // blue tile
            if (s[i - 1][j - 1] == '1')
                ps[i][j] = 1;
            // horizontal edge
            if (j > 1 && s[i - 1][j - 2] == '1' && s[i - 1][j - 1] == '1')
                hh[i][j] = 1;
            // vertical edge
            if (i > 1 && s[i - 2][j - 1] == '1' && s[i - 1][j - 1] == '1')
                vv[i][j] = 1;

            ps[i][j] += ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
            hh[i][j] += hh[i - 1][j] + hh[i][j - 1] - hh[i - 1][j - 1];
            vv[i][j] += vv[i - 1][j] + vv[i][j - 1] - vv[i - 1][j - 1];
        }
    }
    while (q--)
    {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll t1 = ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1];
        ll t2 = 0, t3 = 0;
        if (x1 + 1 <= x2)
            t2 = vv[x2][y2] - vv[x1][y2] - vv[x2][y1 - 1] + vv[x1][y1 - 1];
        if (y1 + 1 <= y2)
            t3 = hh[x2][y2] - hh[x1 - 1][y2] - hh[x2][y1] + hh[x1 - 1][y1];
        cout << t1 - t2 - t3 << endl;
    }
    return 0;
}