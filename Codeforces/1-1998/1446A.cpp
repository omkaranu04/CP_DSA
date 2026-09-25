#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
void solve()
{
    ll n, W;
    cin >> n >> W;
    vector<ll> w(n);
    for (ll i = 0; i < n; i++)
        cin >> w[i];
    ll lo = (W + 1) / 2, hi = W;
    for (ll i = 0; i < n; i++)
    {
        if (w[i] >= lo && w[i] <= hi)
        {
            cout << 1 << endl
                 << i + 1 << endl;
            return;
        }
    }
    ll sum = 0;
    vector<ll> ans;
    for (ll i = 0; i < n; i++)
    {
        if (w[i] < lo)
        {
            sum += w[i];
            ans.push_back(i + 1);
            if (sum >= lo)
                break;
        }
    }
    if (sum < lo || sum > hi)
        cout << -1 << endl;
    else
    {
        cout << ans.size() << endl;
        for (auto &x : ans)
            cout << x << " ";
        cout << endl;
    }
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