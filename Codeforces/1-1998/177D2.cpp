#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, c;
    cin >> n >> m >> c;
    vector<ll> a(n), b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    vector<ll> ps(m + 1, 0);
    for (ll i = 1; i < m + 1; i++)
        ps[i] = ps[i - 1] + b[i - 1];
    for (ll i = 0; i < n; i++)
    {
        ll l = max(0LL, i - (n - m));
        ll r = min(m - 1, i);
        a[i] = (a[i] + ps[r + 1] - ps[l]) % c;
    }
    for (auto x : a)
        cout << x << " ";
    return 0;
}