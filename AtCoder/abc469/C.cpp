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
    string s;
    cin >> n >> s;
    vector<ll> ps(n, 0), hits(n, 0);
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'x')
            ps[i] = 1;
        else
            hits[i] = 1;
    }
    for (ll i = 1; i < n; i++)
    {
        ps[i] += ps[i - 1];
        hits[i] += hits[i - 1];
    }
    for (ll k = 1; k <= n; k++)
    {
        if (hits[k - 1])
        {
            auto it = lower_bound(ps.begin(), ps.end(), k) - ps.begin();
            cout << (it < n ? it + 1 : n) << endl;
        }
        else
            cout << k << endl;
    }
    return 0;
}