#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> grid(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    ll ans = LLONG_MIN;
    if (n >= m)
    {
        for (ll l = 0; l < m; l++)
        {
            vector<ll> tmp(n, 0);
            bool flag = true;
            ll num = LLONG_MIN;
            for (ll r = l; r < m; r++)
            {
                for (ll i = 0; i < n; i++)
                {
                    tmp[i] += grid[i][r];
                    num = max(num, grid[i][r]);
                    if (grid[i][r] >= 0)
                        flag = false;
                }
                if (flag)
                    ans = max(ans, num);
                else
                {
                    ll mxSum = LLONG_MIN, currSum = 0;
                    for (ll i = 0; i < n; i++)
                    {
                        currSum += tmp[i];
                        mxSum = max(mxSum, currSum);
                        currSum = max(currSum, 0LL);
                    }
                    ans = max(ans, mxSum);
                }
            }
        }
    }
    else
    {
        for (ll l = 0; l < n; l++)
        {
            ll tmp[m];
            memset(tmp, 0, sizeof(tmp));
            bool flag = true;
            ll num = LLONG_MIN;

            for (ll r = l; r < n; r++)
            {
                for (ll i = 0; i < m; i++)
                {
                    tmp[i] += grid[r][i];
                    num = max(num, 1LL * grid[r][i]);
                    if (grid[r][i] >= 0)
                        flag = false;
                }
                if (flag)
                    ans = max(ans, num);
                else
                {
                    ll mxSum = LLONG_MIN, currSum = 0;
                    for (ll i = 0; i < m; i++)
                    {
                        currSum += tmp[i];
                        mxSum = max(mxSum, currSum);
                        currSum = max(currSum, 0LL);
                    }
                    ans = max(ans, mxSum);
                }
            }
        }
    }
    // cout << "ans : ";
    cout << ans << endl;
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