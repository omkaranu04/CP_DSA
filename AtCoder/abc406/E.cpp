#include <bits/stdc++.h>
using namespace std;
static const int MOD = 998244353;

inline int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}
inline int mul(long long a, long long b)
{
    return int((a * b) % MOD);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> pow2(61);
    pow2[0] = 1;
    for (int i = 1; i <= 60; i++)
    {
        pow2[i] = add(pow2[i - 1], pow2[i - 1]);
    }

    int T;
    cin >> T;
    while (T--)
    {
        unsigned long long N;
        int K;
        cin >> N >> K;

        vector<int> bits(61);
        for (int i = 0; i < 61; i++)
        {
            bits[i] = int((N >> i) & 1ULL);
        }

        static int dp_cnt[61][2], dp_sum[61][2];
        static int ndp_cnt[61][2], ndp_sum[61][2];

        for (int c = 0; c <= K; c++)
        {
            dp_cnt[c][0] = dp_cnt[c][1] = 0;
            dp_sum[c][0] = dp_sum[c][1] = 0;
        }
        dp_cnt[0][1] = 1;

        for (int pos = 60; pos >= 0; pos--)
        {
            for (int c = 0; c <= K; c++)
            {
                ndp_cnt[c][0] = ndp_cnt[c][1] = 0;
                ndp_sum[c][0] = ndp_sum[c][1] = 0;
            }

            for (int cnt = 0; cnt <= K; cnt++)
            {
                for (int tight = 0; tight < 2; tight++)
                {
                    int ways = dp_cnt[cnt][tight];
                    int acc = dp_sum[cnt][tight];
                    if (!ways)
                        continue;

                    int limit = tight ? bits[pos] : 1;
                    for (int d = 0; d <= limit; d++)
                    {
                        int ncnt = cnt + d;
                        if (ncnt > K)
                            continue;
                        int ntight = tight && (d == limit);

                        ndp_cnt[ncnt][ntight] = add(ndp_cnt[ncnt][ntight], ways);

                        int addval = acc;
                        if (d == 1)
                        {
                            addval = add(addval, mul(ways, pow2[pos]));
                        }
                        ndp_sum[ncnt][ntight] = add(ndp_sum[ncnt][ntight], addval);
                    }
                }
            }

            for (int c = 0; c <= K; c++)
            {
                for (int t = 0; t < 2; t++)
                {
                    dp_cnt[c][t] = ndp_cnt[c][t];
                    dp_sum[c][t] = ndp_sum[c][t];
                }
            }
        }

        int answer = add(dp_sum[K][0], dp_sum[K][1]);
        cout << answer << "\n";
    }

    return 0;
}
