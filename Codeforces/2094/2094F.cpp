#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    if (m % k != 0)
    {
        ll num = 0;
        vector<vector<ll>> ans(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans[i].push_back(num + 1);
                num = (num + 1) % k;
            }
        }
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    else
    {
        ll num = 0;
        vector<vector<ll>> ans(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans[i].push_back(num + 1);
                num = (num + 1) % k;
            }
        }
        for (int i = 1; i < n; i += 2)
        {
            ans[i].push_back(ans[i][0]);
        }
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                for (int j = 0; j < m; j++)
                    cout << ans[i][j] << " ";
            else
                for (int j = 1; j <= m; j++)
                    cout << ans[i][j] << " ";
            cout << endl;
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