#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n;
const ll MOD = 32768;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;

    for (auto &x : a)
    {
        ll ans = 15;
        for (ll i = 0; i <= 15; i++)
        {
            ll y = x + i;
            ll curr = i;
            while (y % MOD != 0)
            {
                y = (2 * y) % MOD;
                curr++;
            }
            ans = min(ans, curr);
        }
        cout << ans << " ";
    }
    return 0;
}