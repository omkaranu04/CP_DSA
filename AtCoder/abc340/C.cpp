#include <bits/stdc++.h>
using namespace std;
#define ll long long int
unordered_map<ll, ll> dp;
ll rec(ll n)
{
    if (n < 2)
        return 0;
    if (dp.find(n) != dp.end())
        return dp[n];
    ll ans = 0;
    ans += rec(n / 2);
    ans += rec((n + 1) / 2);
    ans += n;
    return dp[n] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    cout << rec(n) << endl;
    return 0;
}