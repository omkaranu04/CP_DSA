#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> b(n), w(m);
    for (ll i = 0; i < n; i++)
        cin >> b[i];
    for (ll i = 0; i < m; i++)
        cin >> w[i];
    sort(b.rbegin(), b.rend());
    sort(w.rbegin(), w.rend());
    vector<ll> psb(n + 1, 0), psw(m + 1, 0);
    for (ll i = 1; i <= n; i++)
        psb[i] = psb[i - 1] + b[i - 1];
    for (ll i = 1; i <= m; i++)
        psw[i] = psw[i - 1] + w[i - 1];
    ll ans = 0, maxw = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (i <= m)
            maxw = max(maxw, psw[i]);
        ans = max(ans, psb[i] + maxw);
    }
    cout << ans << endl;
    return 0;
}