#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    map<string, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    string S;
    cin >> S;
    ll len = S.length();
    vector<ll> dp(len + 1, 0);
    dp[0] = 1;
    for (ll i = 1; i <= len; i++)
    {
        for (ll x = 1; x <= 20; x++)
        {
            if (i - x >= 0)
            {
                string tmp = S.substr(i - x, x);
                if (mp[tmp])
                {
                    // cout << tmp << " ";
                    dp[i] |= dp[i - x];
                }
            }
        }
    }
    // cout << endl;
    if (dp[len])
        cout << "YES\n";
    else
        cout << "NO\n";
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