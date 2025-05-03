#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        vector<ll> a(n), ps(n + 1);
        ps[0] = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            ps[i] = ps[i - 1] + a[i - 1];
        }
        while (q--)
        {
            ll l, r, k;
            cin >> l >> r >> k;
            ll ans = ps[n] - (ps[r] - ps[l - 1]) + k * (r - l + 1);
            if (ans % 2 == 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}
