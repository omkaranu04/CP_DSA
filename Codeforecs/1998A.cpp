#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll xc, yc, k;
    cin >> xc >> yc >> k;
    if (k == 1)
    {
        cout << xc << " " << yc << endl;
        return;
    }
    vector<pair<ll, ll>> points;
    for (int i = 1; i <= k - 1; i++)
    {
        points.push_back({xc - i, yc - i});
    }
    ll x = (k * (k - 1)) / 2;
    points.push_back({xc + x, yc + x});
    for (auto i : points)
    {
        cout << i.first << "  " << i.second << endl;
    }
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}