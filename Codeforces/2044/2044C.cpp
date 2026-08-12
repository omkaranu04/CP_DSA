#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll m, a, b, c;
    cin >> m >> a >> b >> c;
    ll r1 = min(m, a);
    ll r2 = min(b, m);
    ll r1_rem = m - r1;
    ll r2_rem = m - r2;
    ll c_seat = min(c, r1_rem + r2_rem);
    ll ans = r1 + r2 + c_seat;
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}