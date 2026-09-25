#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MAXN = 3010;
ll N;
ll a[MAXN], dp1[MAXN][MAXN], dp2[MAXN][MAXN];
ll rec1(ll l, ll r);
ll rec2(ll l, ll r);

ll rec1(ll l, ll r)
{
    // base case
    if (l > r)
        return 0;
    // dp check and return
    if (dp1[l][r] != -1)
        return dp1[l][r];
    // transition
    ll tl = rec2(l + 1, r) + a[l];
    ll tr = rec2(l, r - 1) + a[r];
    // return
    return dp1[l][r] = max(tl, tr);
}
ll rec2(ll l, ll r)
{
    // base case
    if (l > r)
        return 0;
    // dp check and return
    if (dp2[l][r] != -1)
        return dp2[l][r];
    // transition
    ll tl = rec1(l + 1, r) - a[l];
    ll tr = rec1(l, r - 1) - a[r];
    // return
    return dp2[l][r] = min(tl, tr);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    cin >> N;
    for (ll i = 1; i <= N; i++)
        cin >> a[i];
    cout << rec1(1, N);
    return 0;
}