#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < m; i++)
        cin >> b[i];
    ll r = -1;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        ll tmp = 1e18;
        if (it != b.end())
            tmp = abs(*it - a[i]);
        if (it != b.begin())
            tmp = min(tmp, abs(*(it - 1) - a[i]));
        r = max(r, tmp);
    }
    cout << r << endl;
    return 0;
}