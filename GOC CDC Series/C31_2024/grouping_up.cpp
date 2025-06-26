#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
const ll sz2 = 26 * 26, sz3 = 26 * 26 * 26;
ll hash2(char a, char b)
{
    return (a - 'a') * 26 + (b - 'a');
}
ll hash3(char a, char b, char c)
{
    return (a - 'a') * 26 * 26 + (b - 'a') * 26 + (c - 'a');
}
void solve()
{
    ll n, m, q;
    cin >> n >> m >> q;
    vector<string> grid(n);
    for (ll i = 0; i < n; i++)
        cin >> grid[i];
    vector<ll> has2(sz2, 0), has3(sz3, 0);
    for (ll i = 0; i < n; i++)
    {
        for (ll c = 0; c < m - 1; c++)
            has2[hash2(grid[i][c], grid[i][c + 1])] = 1;
        for (ll c = 0; c < m - 2; c++)
            has3[hash3(grid[i][c], grid[i][c + 1], grid[i][c + 2])] = 1;
    }
    for (ll i = 0; i < m; i++)
    {
        for (ll c = 0; c < n - 1; c++)
            has2[hash2(grid[c][i], grid[c + 1][i])] = 1;
        for (ll c = 0; c < n - 2; c++)
            has3[hash3(grid[c][i], grid[c + 1][i], grid[c + 2][i])] = 1;
    }
    string s;
    while (q--)
    {
        cin >> s;
        ll n = s.length();
        if (n < 2)
        {
            cout << "NO\n";
            continue;
        }
        vector<ll> dp(n + 1, 0);
        dp[0] = 1;
        for (ll i = 2; i <= n; i++)
        {
            if (dp[i - 2] && has2[hash2(s[i - 2], s[i - 1])])
                dp[i] = 1;
            else if (i >= 3 && dp[i - 3] && has3[hash3(s[i - 3], s[i - 2], s[i - 1])])
                dp[i] = 1;
        }
        if (dp[n])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return;
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