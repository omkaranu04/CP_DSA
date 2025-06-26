#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll q;
    cin >> q;
    vector<vector<ll>> mp(26, vector<ll>());
    for (ll i = 0; i < n; i++)
    {
        mp[s[i] - 'a'].push_back(i);
    }
    while (q--)
    {
        ll pi;
        cin >> pi;
        pi--;
        for (ll i = 0; i < 26; i++)
        {
            if (mp[i].empty())
                continue;
            auto it = lower_bound(mp[i].begin(), mp[i].end(), pi - k);
            if (it != mp[i].end() && *it <= pi + k)
            {
                cout << (char)(i + 'a') << endl;
                break;
            }
        }
    }
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