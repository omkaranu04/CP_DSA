#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
vector<ll> nums(2e5 + 10, 0);
bool check(vector<ll> &v, ll k, ll mid)
{
    ll segs = 0, mex = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] <= v.size() + 1)
            nums[v[i]] = 1;
        while (nums[mex])
            mex++;
        if (mex >= mid)
        {
            segs++;
            for (ll j = 0; j < min(mid + 1, (ll)v.size() * 1LL + 2 * 1LL); j++)
                nums[j] = 0;
            mex = 0;
        }
    }
    for (ll j = 0; j < (ll)v.size() + 2 * 1LL; j++)
        nums[j] = 0;
    return segs >= k;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll l = 0, r = 1e9;
    while (r > l + 1)
    {
        ll mid = (l + r) / 2;
        if (check(v, k, mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
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