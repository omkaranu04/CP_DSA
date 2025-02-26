#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), ps(n + 1, 0);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + a[i - 1];

    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        cout << ps[b] - ps[a - 1] << endl;
    }
    return 0;
}