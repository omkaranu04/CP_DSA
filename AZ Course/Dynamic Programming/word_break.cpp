#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool breakup(string s, vector<string> &dict)
{
    int n = s.size();
    unordered_map<string, bool> mp;
    for (auto x : dict)
        mp[x] = 1;
    vector<bool> dp(n + 1, false);
    dp[0] = true; // there is an empty string ending at 0th index
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 20 && j <= i; j++)
        {
            if (mp.find(s.substr(i - j, j)) != mp.end())
            {
                dp[i] = dp[i] || dp[i - j];
            }
        }
    }
    return dp[n];
}
void solve()
{
    int n;
    cin >> n;
    string s;
    vector<string> dict(n);
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> dict[i];
    }
    cout << ((breakup(s, dict)) ? "Yes" : "No") << endl;
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