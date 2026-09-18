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
    vector<ll> x(n + 1), ps(n + 2, 0);
    for (ll i = 1; i <= n; i++)
        cin >> x[i];
    ps[1] = x[1];
    for (ll i = 2; i <= n; i++)
        ps[i] = ps[i - 1] + x[i];
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        cout << ps[b] - ps[a - 1] << endl;
    }
    return 0;
}