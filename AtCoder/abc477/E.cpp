#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    vector<ll> ps(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + a[i - 1];
    vector<ll> d = b;
    for (ll k = 0; k < 2 * n; k++)
    {
        ll i = k % n, j = (i + 1) % n;
        d[j] = min(d[j], d[i] + a[i]);
    }
    for (ll k = 2 * n - 1; k >= 0; k--)
    {
        ll i = k % n, j = (i + 1) % n;
        d[i] = min(d[i], d[j] + a[i]);
    }
    while (q--)
    {
        ll s, t;
        cin >> s >> t;
        s--;
        t--;
        if (t == n)
        {
            cout << d[s] << endl;
            continue;
        }
        ll cw = ps[t] - ps[s];
        ll acw = ps[n] - cw;
        cout << min(cw, min(acw, d[s] + d[t])) << endl;
    }
    return 0;
}