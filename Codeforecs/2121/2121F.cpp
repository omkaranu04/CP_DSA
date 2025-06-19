#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
ll countsum(vector<ll> &v, ll t)
{
    map<ll, ll> mp;
    mp[0] = 1;
    ll ans = 0, pref = 0;
    for (auto val : v)
    {
        pref += val;
        if (mp.count(pref - t))
            ans += mp[pref - t];
        mp[pref]++;
    }
    return ans;
}
ll process_block(vector<ll> &block, ll s, ll x)
{
    if (block.empty())
        return 0;
    ll tot = countsum(block, s), wo_x = 0;
    vector<ll> subs;
    for (auto val : block)
    {
        if (val == x)
        {
            wo_x += countsum(subs, s);
            subs.clear();
        }
        else
        {
            subs.push_back(val);
        }
    }
    wo_x += countsum(subs, s);
    return tot - wo_x;
}
void solve()
{
    ll n, s, x;
    cin >> n >> s >> x;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    vector<ll> block;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] > x)
        {
            ans += process_block(block, s, x);
            block.clear();
        }
        else
        {
            block.push_back(a[i]);
        }
    }
    ans += process_block(block, s, x);
    cout << ans << endl;
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