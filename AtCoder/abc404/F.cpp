#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int T, M, K;
    cin >> N >> T >> M >> K;

    // Edge case: only one button
    if (N == 1)
    {
        // every press hits the winning button
        cout << ((long long)T * M >= K ? 1.0 : 0.0) << "\n";
        return 0;
    }

    // dp[t][s] = max probability of winning from repetition t with s hits so far
    // we only need two layers at a time
    vector<double> next_dp(K + 1), cur_dp(K + 1);

    // Base case: after T repetitions, probability = 1 if s>=K else 0
    for (int s = 0; s <= K; s++)
    {
        next_dp[s] = (s >= K ? 1.0 : 0.0);
    }

    // Backward over repetitions
    for (int t = T - 1; t >= 0; t--)
    {
        // compute cur_dp[0..K]
        for (int s = 0; s <= K; s++)
        {
            double best = 0.0;

            // Try clustering k presses on one button, rest distinct
            // require M-k <= N-1 (enough other buttons)
            for (int k = 0; k <= M; k++)
            {
                if ((long long)(M - k) > N - 1)
                    continue;

                // probability cluster-button is the winner
                double p_cluster = (k > 1 ? 1.0 / N : 0.0);
                // if k==1, its success merges into p_distinct below
                // probability distinct-pressed button is the winner
                double p_distinct = double(M - k) / N;

                double p0, p1, pk;
                if (k == 1)
                {
                    // all successes appear as x=1
                    p1 = p_distinct + 1.0 / N;
                    p0 = 1.0 - p1;
                    pk = 0.0;
                }
                else
                {
                    p1 = p_distinct;
                    pk = p_cluster; // only when k>1
                    p0 = 1.0 - p1 - pk;
                }

                // accumulate expected dp
                double sum = 0;
                // no new hits
                sum += p0 * next_dp[s];
                // exactly one new hit
                int s1 = min(K, s + 1);
                sum += p1 * next_dp[s1];
                // exactly k new hits (only if k>1)
                if (k > 1)
                {
                    int sk = min(K, s + k);
                    sum += pk * next_dp[sk];
                }

                best = max(best, sum);
            }

            cur_dp[s] = best;
        }

        // roll
        swap(cur_dp, next_dp);
    }

    cout << fixed << setprecision(12) << next_dp[0] << "\n";
    return 0;
}