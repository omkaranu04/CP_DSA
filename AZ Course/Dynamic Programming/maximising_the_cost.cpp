#include <bits/stdc++.h>
using namespace std;
string s;
int n, m, k;
int cost[26][26];
int dp[101][101][26];
int visited[101][101][26];
int rec(int idx, int changes, int last_char)
{
    // prune
    if (changes < 0)
        return -1e9;

    // base case
    if (idx == n)
        return 0;

    if (visited[idx][changes][last_char])
        return dp[idx][changes][last_char];

    int ans = -1e9;
    for (int i = 0; i < 26; i++)
    {
        // if keeping the same else changing
        if (i == (s[idx] - 'a'))
            ans = max(ans, rec(idx + 1, changes, i) + cost[last_char][i]);
        else
            ans = max(ans, rec(idx + 1, changes - 1, i) + cost[last_char][i]);
    }

    visited[idx][changes][last_char] = true;

    return dp[idx][changes][last_char] = ans;
}
void solve()
{
    cin >> s >> k;
    n = s.length();
    cin >> m;
    memset(cost, 0, sizeof(cost));
    while (m--)
    {
        char a, b;
        int c;
        cin >> a >> b >> c;
        cost[a - 'a'][b - 'a'] = c;
    }
    memset(dp, -1e9, sizeof(dp));
    memset(visited, false, sizeof(visited));

    int ans = -1e9;
    for (int i = 0; i < 26; i++)
    {
        // change the first char
        if (i == (s[0] - 'a'))
        {
            ans = max(ans, rec(1, k, i));
            continue;
        }
        // do not change the first char
        ans = max(ans, rec(1, k - 1, i));
    }
    // cout << "ans : ";
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}