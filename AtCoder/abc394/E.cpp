#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<vector<char>> C(n, vector<char>(n));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> C[i][j];
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(n, 1e18));
    queue<pair<ll, ll>> q;
    for (ll i = 0; i < n; i++)
    {
        q.push({i, i});
        dp[i][i] = 0;
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i == j || C[i][j] == '-')
                continue;
            q.push({i, j});
            dp[i][j] = 1;
        }
    }
    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();
        for (ll k = 0; k < n; k++)
        {
            for (ll l = 0; l < n; l++)
            {
                if (C[k][i] != '-' && C[j][l] != '-' && C[k][i] == C[j][l] && dp[k][l] == 1e18)
                {
                    dp[k][l] = dp[i][j] + 2;
                    q.push({k, l});
                }
            }
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (dp[i][j] == 1e18)
            {
                cout << -1 << " ";
            }
            else
            {
                cout << dp[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}