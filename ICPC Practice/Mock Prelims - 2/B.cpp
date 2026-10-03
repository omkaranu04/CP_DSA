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
        vector<ll> a(n), b(n);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;
        ll x = 0, ans = 0;
        bool possible = true;
        for (ll i = 0; i < n - 1; i++)
        {
            x = a[i] + 2 * x - b[i];
            if (x < 0 || x > 1000000000LL)
            {
                possible = false;
                break;
            }
            ans += x;
        }
        if (possible && a[n - 1] + 2 * x != b[n - 1])
        {
            possible = false;
        }
        if (possible)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}