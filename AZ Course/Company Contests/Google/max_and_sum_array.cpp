#include <bits/stdc++.h>
using namespace std;
#define ll int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll N, numslots;
vector<ll> nums;
// vector<vector<ll>> dp;
// ll rec(ll i, ll mask)
// {
//     if (i == N)
//         return 0;
//     if (dp[i][mask] != -1)
//         return dp[i][mask];
//     ll ans = 0;
//     for (ll s = 0; s < numslots; s++)
//     {
//         ll cnt = (mask >> (2 * s)) & 3;
//         if (cnt == 2)
//             continue;
//         ll nmask = mask + (1LL << (2 * s));
//         ll cand = ((nums[i] & (s + 1)) + rec(i + 1, nmask));
//         ans = max(ans, cand);
//     }
//     return dp[i][mask] = ans;
// }
void solve()
{
    // nums.clear();
    // dp.clear();

    cin >> N >> numslots;
    nums.resize(N);
    for (ll i = 0; i < N; i++)
        cin >> nums[i];
    // dp.resize(N + 1, vector<ll>((1LL << (2 * numslots)), -1));
    // cout << rec(0, 0) << endl;

    const ll MASKS = 1LL << (2 * numslots);
    vector<ll> dp(MASKS, -1), ndp(MASKS, -1);

    dp[0] = 0;
    for (auto num : nums)
    {
        fill(ndp.begin(), ndp.end(), -1);
        for (ll mask = 0; mask < MASKS; mask++)
        {
            if (dp[mask] == -1)
                continue;
            for (ll s = 0; s < numslots; s++)
            {
                ll cnt = (mask >> (2 * s)) & 3;
                if (cnt == 2)
                    continue;
                ll nmask = mask + (1 << (2 * s));
                ll comp = dp[mask] + (num & (s + 1));
                ndp[nmask] = max(ndp[nmask], comp);
            }
        }
        swap(dp, ndp);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
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