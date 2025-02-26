#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<tuple<ll, ll, char>> v;
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        char c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }
    sort(v.begin(), v.end());
    string ans = "Yes\n";
    ll minY = INT32_MAX;
    for (auto &[x, y, c] : v)
    {
        if (c == 'W')
            minY = min(minY, y);
        else
        {
            if (y >= minY)
            {
                ans = "No\n";
                break;
            }
        }
    }
    cout << ans;
    return 0;
}