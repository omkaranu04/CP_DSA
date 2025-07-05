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
    ll n, m, x, t, d;
    cin >> n >> m >> x >> t >> d;
    if (m >= x && m <= n)
        cout << t << endl;
    else
    {
        ll ans = t - d * (x - m);
        cout << ans << endl;
    }
    return 0;
}