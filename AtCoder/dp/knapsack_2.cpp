// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long int
// ll N, W;
// vector<ll> w, v;
// vector<ll> dp;
// int main(int argc, char const *argv[])
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     cin >> N >> W;
//     w.resize(N);
//     v.resize(N);
//     for (ll i = 0; i < N; i++)
//     {
//         cin >> w[i] >> v[i];
//     }
//     ll sum = accumulate(v.begin(), v.end(), 0LL);
//     dp.resize(sum + 1, 1e9);
//     dp[0] = 0;
//     for (ll i = 0; i < N; i++)
//     {
//         for (ll j = sum; j >= v[i]; j--)
//         {
//             dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
//         }
//     }
//     ll ans = 0;
//     for (int i = 0; i <= sum; i++)
//     {
//         if (dp[i] <= W)
//         {
//             ans = i;
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long int
// ll N, W;
// vector<ll> w, v;
// vector<vector<ll>> dp;
// ll rec(ll index, ll value) // for creating this value, min weight what i need, by hovering over choices of choosing the index or not
// {
//     // prune
//     if (index < 0)
//         return (value == 0) ? 0 : 1e9;
//     // base case
//     if (value == 0)
//         return 0;

//     // memoise
//     if (dp[index][value] != -1)
//         return dp[index][value];

//     // not take index
//     ll ans = rec(index - 1, value);
//     // take index
//     if (value >= v[index])
//         ans = min(ans, rec(index - 1, value - v[index]) + w[index]);

//     return dp[index][value] = ans;
// }
// int main(int argc, char const *argv[])
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     cin >> N >> W;
//     w.resize(N);
//     v.resize(N);
//     for (ll i = 0; i < N; i++)
//     {
//         cin >> w[i] >> v[i];
//     }
//     ll sum = accumulate(v.begin(), v.end(), 0LL);
//     dp.resize(N + 1, vector<ll>(sum + 1, -1));
//     ll ans = 0;
//     for (int i = 0; i <= sum; i++)
//     {
//         if (rec(N - 1, i) <= W)
//             ans = i;
//     }
//     cout << ans << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int N, W;
vector<int> w, v;
vector<vector<int>> dp;
int rec(int idx, int val)
{
    if (idx == N)
    {
        if (val == 0)
            return 0;
        else
            return 1e9;
    }

    if (dp[idx][val] != -1)
        return dp[idx][val];

    int ans = rec(idx + 1, val);
    if (val >= v[idx])
        ans = min(ans, rec(idx + 1, val - v[idx]) + w[idx]);

    return dp[idx][val] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> W;
    w.resize(N);
    v.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
    }
    int sum = accumulate(v.begin(), v.end(), 0);
    dp.resize(N + 1, vector<int>(sum + 1, -1));
    int ans = 0;
    for (int i = 1; i <= sum; i++)
    {
        if (rec(0, i) <= W)
            ans = i;
    }
    cout << ans << endl;
    return 0;
}