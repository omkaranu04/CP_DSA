#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll p = m / (k + 1);
    ll a_ = p * k * a[n - 1];
    ll b = p * a[n - 2];
    ll c = m % (k + 1);
    c *= a[n - 1];
    ll ans = a_ + b + c;
    cout << ans << endl;
    return 0;
}