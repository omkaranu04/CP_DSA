#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
ll n;
vector<ll> a;
ll dp[110][3][2];
ll rec(ll i, ll curr_rem, ll taken)
{
    if (i == n)
    {
        if (curr_rem == 0 && taken == 1)
            return 1;
        else
            return 0;
    }

    if (dp[i][curr_rem][taken] != -1)
        return dp[i][curr_rem][taken];

    ll ans = 0;
    // include this
    if (rec(i + 1, (curr_rem + a[i]) % 3, 1) == 1)
        ans = 1;
    // do not include this
    if (rec(i + 1, curr_rem, taken) == 1)
        ans = 1;

    return dp[i][curr_rem][taken] = ans;
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    a.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll ans = rec(0, 0, 0);
    if (ans)
        cout << "Yes\n";
    else
        cout << "No\n";
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