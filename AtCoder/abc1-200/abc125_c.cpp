#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> pmax(n), smax(n);
    pmax[0] = a[0];
    smax[n - 1] = a[n - 1];
    for (ll i = 1; i < n; i++)
        pmax[i] = gcd(pmax[i - 1], a[i]);
    for (ll i = n - 2; i >= 0; i--)
        smax[i] = gcd(smax[i + 1], a[i]);
    ll ans = LLONG_MIN;
    ans = max(ans, smax[1]);
    ans = max(ans, pmax[n - 2]);
    // for(auto x:pmax) cout<<x<<" ";
    // cout<<endl;
    // for(auto x:smax) cout<<x<<" ";
    // cout<<endl;
    for (ll m = 1; m <= n - 2; m++)
        ans = max(ans, gcd(pmax[m - 1], smax[m + 1]));
    cout << ans << endl;
    return 0;
}