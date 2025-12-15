#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll N, M;
vector<pair<ll, ll>> arr;
ll dp[5010][5010][2];
ll nxt[5010][5010][2]; // to store the decision at that state
string x;
// at ith index what is the remaining sum, and if the previous is being reversed or not
ll rec(ll i, ll rem_sum, ll rev)
{
    if (rem_sum < 0)
        return 0;
    if (i == N)
        return rem_sum == 0;
    if (dp[i][rem_sum][rev] != -1)
        return dp[i][rem_sum][rev];
    // do not reverse this
    if (rec(i + 1, rem_sum - arr[i].first, 0))
    {
        nxt[i][rem_sum][rev] = 0;
        return dp[i][rem_sum][rev] = 1;
    }
    // reverse this
    if (rec(i + 1, rem_sum - arr[i].second, 1))
    {
        nxt[i][rem_sum][rev] = 1;
        return dp[i][rem_sum][rev] = 1;
    }
    return dp[i][rem_sum][rev] = 0;
}
void solve()
{
    arr.clear();
    memset(dp, -1, sizeof(dp));

    cin >> N >> M;
    arr.resize(N);
    for (ll i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;

    x = "";
    ll ans = rec(0, M, 0);
    if (ans == 0)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        x = "";
        ll rem = M, rev = 0;
        for (ll i = 0; i < N; i++)
        {
            ll c = nxt[i][rem][rev];
            x.push_back(c ? '1' : '0');
            rem -= (c ? arr[i].second : arr[i].first);
            rev = c;
        }
        cout << x << endl;
    }
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