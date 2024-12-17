#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
vector<vector<int>> dp;
int rec(int l, int r)
{
    if (l > r)
        return 0;
    if (l == r)
        return 1;

    if (dp[l][r] != -1)
        return dp[l][r];

    int ans = 1 + rec(l + 1, r);
    if (a[l] == a[l + 1])
        ans = min(ans, 1 + rec(l + 2, r));

    for (int i = l + 2; i <= r; i++)
    {
        if (a[l] == a[i])
            ans = min(ans, rec(l + 1, i - 1) + rec(i + 1, r));
    }

    return dp[l][r] = ans;
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
        cin >> n;
        a.resize(n + 2, 0);
        dp.clear();
        dp.resize(n + 2, vector<int>(n + 2, -1));
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cout << rec(1, n) << endl;
    }
    return 0;
}