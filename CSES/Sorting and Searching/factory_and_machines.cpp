#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
bool check(ll mid, ll t, vector<ll> &k)
{
    ll temp = 0;
    for (ll i = 0; i < k.size(); i++)
    {
        temp += (mid / k[i]);
        if (temp >= t)
            return true;
    }
    return temp >= t;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, t;
    cin >> n >> t;
    vector<ll> k(n);
    for (ll i = 0; i < n; i++)
        cin >> k[i];
    ll lo = 1, hi = t * (*max_element(k.begin(), k.end())), ans = -1;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (check(mid, t, k))
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