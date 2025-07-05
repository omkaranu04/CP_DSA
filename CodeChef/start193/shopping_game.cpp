#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll topk(vector<ll> &v, ll k)
{
    if (v.size() < k)
        return 0;
    sort(v.begin(), v.end(), greater<ll>());
    ll ans = 0;
    for (ll i = 0; i < k; i++)
        ans = (ans + v[i]) % MOD;
    return ans;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> c(n);
    for (ll i = 0; i < n; i++)
        cin >> c[i];
    string A;
    cin >> A;
    bool all0 = true, all1 = true;
    for (auto c : A)
    {
        if (c == '1')
            all0 = false;
        if (c == '0')
            all1 = false;
    }
    ll ans;
    if (all0)
    {
        vector<ll> tmp(c.begin(), c.begin() + (n - 1));
        ans = topk(tmp, k);
    }
    else if (all1)
    {
        vector<ll> tmp(c.begin() + 1, c.end());
        ans = topk(tmp, k);
    }
    else
        ans = topk(c, k);

    cout << ans % MOD << endl;
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