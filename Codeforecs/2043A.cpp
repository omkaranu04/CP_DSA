#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
map<ll, ll> dp;
ll getmax(ll n)
{
    if (n <= 3)
        return 1;
    if (dp.count(n))
        return dp[n];
    ll newVal = n / 4;
    return dp[n] = getmax(newVal) + getmax(newVal);
}
void solve()
{
    ll n;
    cin >> n;
    cout << getmax(n) << endl;
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