#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (auto &x : a)
            cin >> x;
        sort(a.begin(), a.end());
        if (n <= 3)
        {
            cout << a[n - 1] - a[0] << endl;
            continue;
        }
        vector<ll> g(n - 3);
        for (ll i = 0; i < n - 3; i++)
            g[i] = a[i + 2] - a[i + 1];
        ll odd = 0;
        for (ll i = 1; i < n - 3; i += 2)
            odd += g[i];
        ll add = LLONG_MAX, even = 0;
        ll m = (n - 3) / 2;
        for (ll i = 0; i <= m; i++)
        {
            add = min(add, even + odd);
            if (i < m)
            {
                even += g[2 * i];
                odd -= g[2 * i + 1];
            }
        }
        ll ans = add + (a[n - 1] - a[0]);
        cout << ans << endl;
    }
    return 0;
}