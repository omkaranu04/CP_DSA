#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll N;
ll a[3010];
ll dpj[3010][3010], dpt[3010][3010];
ll taro(ll l, ll r);
ll jiro(ll l, ll r);

ll jiro(ll l, ll r)
{
    if (l > r)
        return 0;
    if (dpj[l][r] != -1)
        return dpj[l][r];

    ll takeL = taro(l + 1, r) - a[l];
    ll takeR = taro(l, r - 1) - a[r];

    return dpj[l][r] = min(takeL, takeR);
}
ll taro(ll l, ll r)
{
    if (l > r)
        return 0;
    if (dpt[l][r] != -1)
        return dpt[l][r];

    ll takeL = a[l] + jiro(l + 1, r);
    ll takeR = a[r] + jiro(l, r - 1);

    return dpt[l][r] = max(takeL, takeR);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (ll i = 1; i <= N; i++)
        cin >> a[i];

    memset(dpj, -1, sizeof(dpj));
    memset(dpt, -1, sizeof(dpt));

    cout << taro(1, N);
    return 0;
}