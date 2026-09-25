#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> c(n + 1);
        for (ll i = 1; i <= n; i++)
            cin >> c[i];
        sort(c.begin(), c.end());
        vector<ll> ps(n + 2, 0);
        ps[1] = c[1];
        for (ll i = 2; i <= n; i++)
            ps[i] = ps[i - 1] + c[i];

        vector<vector<ll>> ps2(k + 2);
        for (ll i = 1; i <= k + 1; i++)
        {
            for (ll j = i; j <= n; j += (k + 1))
            {
                ps2[i].push_back(c[j]);
            }
        }

        // for (auto x : ps2)
        // {
        //     for (auto x2 : x)
        //         cout << x2 << " ";
        //     cout << endl;
        // }

        for (ll i = 1; i <= k + 1; i++)
        {
            for (int j = 1; j < ps2[i].size(); j++)
            {
                ps2[i][j] += ps2[i][j - 1];
            }
        }

        for (ll m = 1; m <= n; m++)
        {
            if (m <= k)
            {
                cout << ps[m] << " ";
                continue;
            }
            ll ans = ps[m] - ps2[(m % (k + 1)) + 1][m / (k + 1) - 1];
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}