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
    ll n, m;
    cin >> n >> m;
    vector<ll> s(n), t(n);
    for (auto &x : s)
        cin >> x;
    t = s;
    for (ll i = 1; i < n; i++)
        t[i] = max(t[i], t[i - 1] - m);
    for (ll i = n - 2; i >= 0; i--)
        t[i] = max(t[i], t[i + 1] - m);
    for (auto x : t)
        cout << x << " ";
    return 0;
}