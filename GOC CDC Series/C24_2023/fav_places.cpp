#include <bits/stdc++.h>
using namespace std;
using ld = double;
const ld INF = 1e100;
const int MAXN = 16;
const int MAXMASK = 1 << MAXN;

ld dist[MAXN][MAXN];
ld dp[MAXMASK][MAXN];
ld xpos[MAXN], ypos[MAXN];

inline void relax(ld &a, ld b)
{
    if (b < a)
        a = b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i)
            cin >> xpos[i] >> ypos[i];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                ld dx = xpos[i] - xpos[j];
                ld dy = ypos[i] - ypos[j];
                dist[i][j] = sqrt(dx * dx + dy * dy);
            }

        const int FULL = 1 << n;
        for (int m = 0; m < FULL; ++m)
            for (int i = 0; i < n; ++i)
                dp[m][i] = INF;
        dp[1][0] = 0.0;

        for (int mask = 1; mask < FULL; ++mask)
        {
            int subset = mask;
            while (subset)
            {
                int u = __builtin_ctz(subset);
                subset &= subset - 1;
                ld cur = dp[mask][u];
                if (cur >= INF)
                    continue;

                int rest = (~mask) & (FULL - 1);
                while (rest)
                {
                    int v = __builtin_ctz(rest);
                    rest &= rest - 1;
                    int nmask = mask | (1 << v);
                    relax(dp[nmask][v], cur + dist[u][v]);
                }
            }
        }

        ld best = INF;
        for (int u = 1; u < n; ++u)
            relax(best, dp[FULL - 1][u] + dist[u][0]);

        cout << (long long)floor(best) << '\n';
    }
}
