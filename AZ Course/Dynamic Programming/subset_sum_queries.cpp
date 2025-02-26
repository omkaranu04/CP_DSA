
#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
int dp[101][100001];
int n;
int generate(int level, int rem_sum, vector<int> &arr)
{
    if (level == n)
    {
        if (rem_sum == 0)
            return 1;
        return 0;
    }

    if (rem_sum == 0)
        return dp[level][rem_sum] = 1;

    if (dp[level][rem_sum] != -1)
        return dp[level][rem_sum];

    int ans = 0;
    ans = generate(level + 1, rem_sum, arr);
    if (ans != 0)
        return dp[level][rem_sum] = 1;

    if (rem_sum >= arr[level])
        ans = generate(level + 1, rem_sum - arr[level], arr);
    if (ans != 0)
        return dp[level][rem_sum] = 2;

    return dp[level][rem_sum] = 0;
}
vector<int> get_subset(int rem_sum, vector<int> &arr)
{
    vector<int> res;
    int i = 0;
    for (int i = 0; i < n && rem_sum > 0; i++)
    {
        if (dp[i][rem_sum] == 2)
        {
            res.push_back(i);
            rem_sum -= arr[i];
        }
    }
    return res;
}
vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries)
{
    // Write code here.
    vector<vector<int>> res;
    memset(dp, -1, sizeof(dp));
    n = arr.size();
    for (auto i : queries)
    {
        vector<int> temp(1, -1);
        if (generate(0, i, arr) != 0)
        {
            res.push_back(get_subset(i, arr));
        }
        else
        {
            res.push_back(temp);
        }
    }
    return res;
}

void solve()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)
        cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q)
    {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++)
    {
        auto x = ans[i];
        if (x.size() == 0)
        {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1)
        {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x)
        {
            if (y < 0 || y >= N || p >= y)
            { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i])
        {
            cout << 1 << endl;
        }
        else
            cout << 101 << endl;
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
