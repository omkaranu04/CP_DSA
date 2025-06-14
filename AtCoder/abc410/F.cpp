#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct FastFreq
{
    int off;
    int tick = 1;
    vector<int> cnt, seen;

    FastFreq(int range) : off(range), cnt(2 * range + 1, 0),
                          seen(2 * range + 1, 0) {}

    inline ll addAndGet(ll sum)
    {
        int idx = int(sum) + off;
        if (seen[idx] != tick)
        {
            seen[idx] = tick;
            cnt[idx] = 0;
        }
        return cnt[idx]++;
    }
    inline void nextRect() { ++tick; }
};

void solve()
{
    ll H, W;
    cin >> H >> W;

    vector<string> S(H);
    for (string &row : S)
        cin >> row;

    bool transpose = (H > W);
    ll R = transpose ? W : H;
    ll C = transpose ? H : W;

    vector<vector<int8_t>> A(R, vector<int8_t>(C));
    for (ll i = 0; i < H; ++i)
        for (ll j = 0; j < W; ++j)
        {
            int8_t v = (S[i][j] == '#') ? 1 : -1;
            if (transpose)
                A[j][i] = v;
            else
                A[i][j] = v;
        }

    int RANGE = int(R * C);
    FastFreq freq(RANGE);

    ll ans = 0;
    vector<int> colSum(C);

    for (ll top = 0; top < R; ++top)
    {
        fill(colSum.begin(), colSum.end(), 0);

        for (ll bottom = top; bottom < R; ++bottom)
        {
            for (ll c = 0; c < C; ++c)
                colSum[c] += A[bottom][c];

            freq.nextRect();
            ll pref = 0;
            ans += freq.addAndGet(0);

            for (ll c = 0; c < C; ++c)
            {
                pref += colSum[c];
                ans += freq.addAndGet(pref);
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
