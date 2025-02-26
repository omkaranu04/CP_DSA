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
    vector<ll> r(n), q(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> q[i] >> r[i];
    }
    // vector<vector<ll>> v(n + 1);
    // for (int i = 1; i <= n; i++)
    // {
    //     ll temp = r[i - 1];
    //     while (temp <= 1e9)
    //     {
    //         v[i].push_back(temp);
    //         temp += q[i - 1];
    //     }
    // }
    int Q;
    cin >> Q;
    while (Q--)
    {
        ll t, d;
        cin >> t >> d;
        // ll tx = lower_bound(v[t].begin(), v[t].end(), d) - v[t].begin();
        // cout << v[t][tx] << endl;
        ll rem = d % q[t - 1];
        if (rem == r[t - 1])
        {
            cout << d << endl;
            continue;
        }
        else
        {
            ll ans = d + (r[t - 1] - rem);
            if (rem > r[t - 1])
            {
                ans += q[t - 1];
            }
            cout << ans << endl;
        }
    }
    return 0;
}