#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> done(n, 0), going(n, 0);
    done[0] = 0;
    going[0] = -a[0];
    for (ll i = 1; i < n; i++)
    {
        done[i] = max(done[i - 1], going[i - 1] + a[i] - k);
        going[i] = max(going[i - 1], done[i - 1] - a[i]);
    }
    cout << done[n - 1] << "\n";
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}