#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    string s;
    cin >> n >> s;
    vector<vector<ll>> pos(26);
    for (ll i = 0; i < n; i++)
        pos[s[i] - 'a'].push_back(i);
    ll ans = 0;
    for (ll c = 0; c < 26; c++)
    {
        vector<ll> &occ = pos[c];
        ll len = occ.size();
        for (ll i = 0; i < len; i++)
        {
            ll l = (i == 0) ? (occ[i]) : (occ[i] - occ[i - 1] - 1);
            ll r = (i == len - 1) ? (n - occ[i] - 1) : (occ[i + 1] - occ[i] - 1);
            if (len == 1)
                ans += (occ[i] + 1) * (n - occ[i]);
            else
                ans += (l + 1) * (r + 1);
        }
    }
    cout << ans << "\n";
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