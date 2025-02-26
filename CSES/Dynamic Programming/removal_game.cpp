#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int n;
vector<ll> x;
vector<vector<ll>> dp;
ll rec(ll left, ll right)
{
    if (left == right)
        return x[left];

    if (dp[left][right] != -1)
        return dp[left][right];

    ll ans = max(x[left] - rec(left + 1, right), x[right] - rec(left, right - 1));
    return dp[left][right] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    x.resize(n);
    dp.resize(n, vector<ll>(n, -1));
    for (int i = 0; i < n; i++)
        cin >> x[i];
    ll sum = accumulate(x.begin(), x.end(), 0LL);
    ll ans = rec(0, n - 1);
    cout << (sum + ans) / 2 << endl;
    return 0;
}