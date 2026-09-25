#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    ll fn = -1, ln = -1;
    for (ll i = 0; i < n; i++)
        if (a[i] == -1)
            ln = i;
    for (ll i = n - 1; i >= 0; i--)
        if (a[i] == -1)
            fn = i;
    ll fo = -1, lo = -1;
    if (fn != -1)
        for (ll i = fn; i >= 0; i--)
            if (a[i] == 1)
                fo = i;
    if (ln != -1)
        for (ll i = ln; i < n; i++)
            if (a[i] == 1)
                lo = i;
    if (fn != -1 && fo == -1)
        a[fn] = 1;
    if (ln != -1 && lo == -1)
        a[ln] = 1;
    for (ll i = 0; i < n; i++)
        if (a[i] == -1)
            a[i] = 0;
    for (auto &x : a)
        cout << x << " ";
    cout << endl;
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