#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll cnt(ll a1, ll a2, ll a4, ll a5, ll a3)
{
    ll temp = 0;
    if (a3 == a1 + a2)
        temp++;
    if (a4 == a2 + a3)
        temp++;
    if (a5 == a3 + a4)
        temp++;
    return temp;
}
void solve()
{
    ll a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;
    ll a3_1 = a1 + a2;
    ll a3_2 = a4 - a2;
    ll a3_3 = a5 - a4;

    ll ans = -1;
    ans = max(ans, cnt(a1, a2, a4, a5, a3_1));
    ans = max(ans, cnt(a1, a2, a4, a5, a3_2));
    ans = max(ans, cnt(a1, a2, a4, a5, a3_3));
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