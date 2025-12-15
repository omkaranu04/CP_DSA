#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct BrokenToy
{
    int rank;
    ll price;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<ll> price(N);
        for (int i = 0; i < N; ++i)
            cin >> price[i];

        vector<pair<ll, int>> sorted;
        sorted.reserve(N);
        for (int i = 0; i < N; ++i)
            sorted.push_back({price[i], i});
        sort(sorted.begin(), sorted.end());

        vector<ll> pref(N + 1, 0);
        for (int i = 1; i <= N; ++i)
            pref[i] = pref[i - 1] + sorted[i - 1].first;

        vector<int> pos(N);
        for (int r = 0; r < N; ++r)
            pos[sorted[r].second] = r;

        int Q;
        cin >> Q;
        while (Q--)
        {
            ll C;
            int K;
            cin >> C >> K;

            vector<BrokenToy> bad;
            bad.reserve(K);
            for (int i = 0; i < K; ++i)
            {
                int idx;
                cin >> idx;
                --idx;
                bad.push_back({pos[idx], price[idx]});
            }

            auto affordable = [&](int m) -> bool
            {
                ll cost = pref[m];
                for (const auto &bt : bad)
                    if (bt.rank < m)
                        cost -= bt.price;
                return cost <= C;
            };

            int lo = 0, hi = N;
            while (lo < hi)
            {
                int mid = (lo + hi + 1) >> 1; // upper mid
                if (affordable(mid))
                    lo = mid;
                else
                    hi = mid - 1;
            }

            int brokenInPrefix = 0;
            for (const auto &bt : bad)
                if (bt.rank < lo)
                    ++brokenInPrefix;

            int answer = lo - brokenInPrefix;
            cout << answer << '\n';
        }
    }
    return 0;
}