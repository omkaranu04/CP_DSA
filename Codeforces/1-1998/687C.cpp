#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll maxn = 510, maxk = 510;
ll n, k;
ll c[maxn];
bool dp[maxn][maxk][maxk];
bool poss[maxk];
// total amount to be paid is k (rem is k), sub is what can be made of what is taken in rem
void rec(ll i, ll rem, ll sub)
{
    // base case
    if (rem == 0)
    {
        poss[sub] = true;
        return;
    }
    // invalid state
    if (i > n || rem < 0 || sub > k)
        return;
    // dp check and return
    if (dp[i][rem][sub])
        return;
    // transitions
    dp[i][rem][sub] = true;
    // not use
    rec(i + 1, rem, sub);
    // use to pay only
    if (rem - c[i] >= 0)
        rec(i + 1, rem - c[i], sub);
    // use to pay and include in subset
    if (rem - c[i] >= 0)
        rec(i + 1, rem - c[i], sub + c[i]);
    // return
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, false, sizeof(dp));
    memset(poss, false, sizeof(poss));
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
        cin >> c[i];
    rec(1, k, 0);
    vector<ll> ans;
    for (ll x = 0; x <= k; x++)
        if (poss[x])
            ans.push_back(x);
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << " ";
    return 0;
}