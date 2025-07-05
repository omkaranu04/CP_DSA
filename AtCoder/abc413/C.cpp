#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll q;
    cin >> q;
    deque<pair<ll, ll>> dq;
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll c, x;
            cin >> c >> x;
            dq.push_back({x, c});
        }
        else
        {
            ll k;
            cin >> k;
            ll ans = 0;
            while (k > 0)
            {
                auto &f = dq.front();
                ll take = min(k, f.second);
                ans += take * f.first;
                k -= take;
                f.second -= take;
                if (f.second == 0)
                    dq.pop_front();
            }
            cout << ans << endl;
        }
    }
    return 0;
}