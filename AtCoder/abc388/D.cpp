#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n + 1), ps(n + 2, 0);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        ps[i] += ps[i - 1];
        a[i] = a[i] + ps[i];
        ll reach = min(i + a[i] + 1, n + 1);
        ps[reach]--;
        ps[i + 1]++;
        a[i] = max(0LL, a[i] - (reach - i - 1));
    }
    for (ll i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}