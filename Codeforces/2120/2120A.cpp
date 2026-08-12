#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
vector<pair<ll, ll>> r;
bool possible()
{
    if (r[0].first == r[1].first && r[1].first == r[2].first)
    {
        if (r[0].second + r[1].second + r[2].second == r[0].first)
            return true;
    }
    if (r[0].second == r[1].second && r[1].second == r[2].second)
    {
        if (r[0].first + r[1].first + r[2].first == r[0].second)
            return true;
    }
    for (ll i = 0; i < 3; i++)
    {
        ll S = r[i].second;
        ll rem = S - r[i].first;
        if (rem <= 0)
            continue;
        ll j = (i + 1) % 3, k = (i + 2) % 3;
        if (r[j].first == rem && r[k].first == rem && r[j].second + r[k].second == r[i].second)
            return true;
    }
    for (ll i = 0; i < 3; i++)
    {
        ll S = r[i].first;
        ll rem = S - r[i].second;
        if (rem <= 0)
            continue;
        ll j = (i + 1) % 3, k = (i + 2) % 3;
        if (r[j].second == rem && r[k].second == rem && r[j].first + r[k].first == r[i].first)
            return true;
    }
    return false;
}
void solve()
{
    r.clear();

    r.resize(3);
    for (ll i = 0; i < 3; i++)
        cin >> r[i].first >> r[i].second;
    cout << (possible() ? "YES\n" : "NO\n");
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