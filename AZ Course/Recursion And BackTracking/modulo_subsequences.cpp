#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << a[0] % m << endl;
        return 0;
    }
    vector<ll> sums;
    ll mid = (n + 1) / 2;
    for (ll i = 0; i < (1LL << mid); i++)
    {
        ll sum = 0;
        for (ll j = 0; j < mid; j++)
        {
            if ((i & (1LL << j)) != 0)
                sum = (sum + a[j]) % m;
        }
        sums.push_back(sum);
    }

    sort(sums.begin(), sums.end());
    ll ans = 0;
    for (ll i = 0; i < (1LL << n); i += 1LL << mid)
    {
        ll sum = 0;
        for (ll j = mid; j < n; j++)
        {
            if ((i & (1LL << j)) != 0)
                sum = (sum + a[j]) % m;
        }
        ll t = (m - 1 - sum + m) % m;
        ll pos = upper_bound(sums.begin(), sums.end(), t) - sums.begin() - 1;
        if (pos < 0)
        {
            pos = sums.size() - 1;
        }
        ans = max(ans, (sum + sums[pos]) % m);
    }
    cout << ans << "\n";
    return 0;
}