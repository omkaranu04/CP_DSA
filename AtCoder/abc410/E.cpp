#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, H, M;
    cin >> N >> H >> M;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i] >> B[i];

    vector<int> dp(H + 1, -1);
    dp[H] = M;

    int answer = 0;

    for (int idx = 0; idx < N; ++idx)
    {
        vector<int> ndp(H + 1, -1);

        for (int h = 0; h <= H; ++h)
            if (dp[h] != -1)
            {
                int magic = dp[h];

                if (h >= A[idx])
                    ndp[h - A[idx]] = max(ndp[h - A[idx]], magic);

                if (magic >= B[idx])
                    ndp[h] = max(ndp[h], magic - B[idx]);
            }

        bool ok = false;
        for (int h = 0; h <= H && !ok; ++h)
            if (ndp[h] != -1)
                ok = true;

        if (!ok)
            break;
        answer = idx + 1;
        dp.swap(ndp);
    }

    cout << answer << '\n';
    return 0;
}
