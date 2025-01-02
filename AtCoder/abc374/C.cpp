#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> k(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> k[i];
    }
    ll sum = accumulate(k.begin(), k.end(), 0LL);
    ll ans = INT32_MAX;
    for (ll i = 0; i < (1 << n); i++)
    {
        ll temp = 0;
        for (ll j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                temp += k[j];
            }
        }
        ans = min(ans, max(temp, sum - temp));
    }
    cout << ans << endl;
    return 0;
}