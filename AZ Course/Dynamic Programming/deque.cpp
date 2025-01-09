#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
vector<ll> a;
vector<vector<ll>> dp;
ll rec(ll l, ll r)
{
    if (l == r)
        return a[l];

    if (dp[l][r] != -1)
        return dp[l][r];

    ll ans = max(a[l] - rec(l + 1, r), a[r] - rec(l, r - 1));

    return dp[l][r] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    a.resize(n);
    dp.resize(n, vector<ll>(n, -1));
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    ll s1 = (sum + rec(0, n - 1)) / 2;
    ll s2 = sum - s1;

    cout << s1 - s2 << endl;
    return 0;
}