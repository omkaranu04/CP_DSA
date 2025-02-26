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
    vector<ll> t(n), v(n);
    for (ll i = 0; i < n; i++)
        cin >> t[i] >> v[i];
    ll c_wat = v[0], c_t = t[0];
    for (int i = 1; i < n; i++)
    {
        c_wat = max(0LL, c_wat - (t[i] - c_t));
        c_wat += v[i];
        c_t = t[i];
    }
    cout << c_wat << endl;
    return 0;
}