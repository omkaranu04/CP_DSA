#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    map<ll, ll> all, y;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> a[i][j];
            all[a[i][j]]++;
        }
    }
    ll cx = 0, cy = 0;
    while (1)
    {
        if (cx == n / 2 && cy == n / 2)
            break;
        y[a[cx][cy]]++;
        cx++, cy++;
    }
    cx = 0, cy = n - 1;
    while (1)
    {
        if (cx == n / 2 && cy == n / 2)
            break;
        y[a[cx][cy]]++;
        cx++, cy--;
    }
    y[a[n / 2][n / 2]]++;
    cx = n / 2 + 1, cy = n / 2;
    while (cx < n)
    {
        y[a[cx][cy]]++;
        cx++;
    }
    ll yoccur1, yoccur2, ymax1 = 0, ymax2 = 0;
    for (auto &[key, val] : y)
    {
        if (val > ymax1)
        {
            ymax2 = ymax1;
            yoccur2 = yoccur1;
            ymax1 = val;
            yoccur1 = key;
        }
        else if (val > ymax2)
        {
            ymax2 = val;
            yoccur2 = key;
        }
        all[key] -= val;
    }
    ll ans = 1e9;
    for (ll i = 0; i < 3; i++)
    {
        for (ll j = 0; j < 3; j++)
        {
            if (i != j)
                ans = min(ans, n * n - y[i] - all[j]);
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