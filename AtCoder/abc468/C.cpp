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
    ll n;
    cin >> n;
    vector<ll> p(n), q(n), a(n);
    for (ll i = 0; i < n; i++)
        cin >> p[i];
    for (ll i = 0; i < n; i++)
        cin >> q[i];
    for (ll i = 0; i < n; i++)
        a[i] = i + 1;
    ll ans = 0;
    do
    {
        if (a > p && a < q)
            ans++;
    } while (next_permutation(a.begin(), a.end()));
    cout << ans;
    return 0;
}