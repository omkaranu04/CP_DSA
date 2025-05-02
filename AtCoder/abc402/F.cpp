#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 21;
ll power10[2 * MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll m;
    cin >> n >> m;

    vector<vector<ll>> A(n, vector<ll>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    power10[0] = 1 % m;
    for (int i = 1; i < 2 * n; ++i)
        power10[i] = (power10[i - 1] * 10LL) % m;

    vector<vector<ll>> grid(n, vector<ll>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            grid[i][j] = (A[i][j] * power10[2 * n - i - j - 2]) % m;

    ll answer = 0;

    for (int k = 0; k < n; ++k)
    {
        int x = k, y = n - 1 - k;

        vector<vector<unordered_set<int>>> dp1(n, vector<unordered_set<int>>(n));
        dp1[0][0].insert(grid[0][0]);

        for (int i = 0; i <= x; ++i)
        {
            for (int j = 0; j <= y; ++j)
            {
                for (int val : dp1[i][j])
                {
                    if (i + 1 <= x)
                        dp1[i + 1][j].insert((val + grid[i + 1][j]) % m);
                    if (j + 1 <= y)
                        dp1[i][j + 1].insert((val + grid[i][j + 1]) % m);
                }
            }
        }

        unordered_set<int> S1 = dp1[x][y];

        vector<vector<unordered_set<int>>> dp2(n, vector<unordered_set<int>>(n));
        dp2[x][y].insert(0);

        for (int i = x; i < n; ++i)
        {
            for (int j = y; j < n; ++j)
            {
                for (int val : dp2[i][j])
                {
                    if (i + 1 < n)
                        dp2[i + 1][j].insert((val + grid[i + 1][j]) % m);
                    if (j + 1 < n)
                        dp2[i][j + 1].insert((val + grid[i][j + 1]) % m);
                }
            }
        }

        unordered_set<int> S2 = dp2[n - 1][n - 1];

        vector<int> v2(S2.begin(), S2.end());
        sort(v2.begin(), v2.end());

        for (int x_val : S1)
        {
            int target = (m - x_val) % m;
            auto it = lower_bound(v2.begin(), v2.end(), target);
            if (it != v2.begin())
            {
                --it;
                answer = max(answer, (x_val + *it) % m);
            }
            answer = max(answer, (x_val + v2.back()) % m);
        }
    }

    cout << answer << '\n';
    return 0;
}