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
    vector<ll> a(n + 1), t(n + 1), s(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= n - 1; i++)
        cin >> s[i] >> t[i];
    for (ll i = 1; i <= n - 1; i++)
    {
        a[i + 1] += t[i] * (a[i] / s[i]);
    }
    cout << a[n] << endl;
    return 0;
}