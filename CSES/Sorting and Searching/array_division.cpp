#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
bool check(ll mid, ll k, vector<ll> &x)
{
    ll part = 1, currsum = x[0];
    for (ll i = 1; i < x.size(); i++)
    {
        if (currsum + x[i] > mid)
        {
            part++;
            currsum = x[i];
        }
        else
            currsum += x[i];
    }
    return part <= k;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n);
    for (ll i = 0; i < n; i++)
        cin >> x[i];
    ll lo = *max_element(x.begin(), x.end()), hi = accumulate(x.begin(), x.end(), 0LL), ans = -1;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (check(mid, k, x))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans << endl;
    return 0;
}