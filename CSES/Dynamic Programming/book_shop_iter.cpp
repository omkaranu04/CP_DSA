#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> books(n);
    for (int i = 0; i < n; i++)
        cin >> books[i].first;
    for (int i = 0; i < n; i++)
        cin >> books[i].second;

    sort(books.begin(), books.end());
    int lim = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (books[i].first <= x)
        {
            lim = i;
            break;
        }
    }
    if (lim == -1)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int>> dp(lim + 1, vector<int>(x + 1, 0));
    for (int i = books[0].first; i <= x; i++)
        dp[0][i] = books[0].second;

    for (int i = 1; i <= lim; i++)
    {
        for (int j = books[0].first; j <= x; j++)
        {
            int t = -1;
            if (j >= books[i].first)
                t = books[i].second + dp[i - 1][j - books[i].first];
            dp[i][j] = max(dp[i - 1][j], t);
        }
    }
    cout << dp[lim][x] << endl;
    return 0;
}