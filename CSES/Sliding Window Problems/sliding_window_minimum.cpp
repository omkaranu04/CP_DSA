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
    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<ll> ps(n);
    ps[0] = x;
    for (ll i = 1; i < n; i++)
        ps[i] = ((ps[i - 1] * 1LL * a) % c + b) % c;
    
    return 0;
}